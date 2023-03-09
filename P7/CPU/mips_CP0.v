`timescale 1ns / 1ps

`define IM SR[15:10]        //Interrupt Mask 由mtc0修改，屏蔽中断
`define EXL SR[1]           //Exception Level 表明进入中断异常，禁止所有中断和异常
`define IE SR[0]            //Interrupt Enable 全局中断使能(不影响异常)
`define BD Cause[31]        //Branch Delay EPC是否指向前一条（延迟槽）指令
`define IP Cause[15:10]     //Interrupt Pending 表明6个外部中断有无，由计时器和外部中断修改
`define ExcCode Cause[6:2]  //ExcCode 异常编码，记录当前发生的是什么异常。

module mips_CP0(
    input clk,
    input reset,
    input en,                   //写使能信号 (mtc0)
    input [4:0] CP0Add,         //读写寄存器的编号
    input [31:0] CP0In,         //CP0写入数据
    output [31:0] CP0Out,       //CP0读出数据

    input [31:0] VPC,           //受害PC
    input BDIn,                 //是否是延迟槽指令
    output [31:0] EPCOUt,       //EPC的值

    input EXLClr,               //用来复位EXL （M级指令是eret，即退出异常）
    input [4:0] ExcCodeIn,      //记录异常类型
    input [5:0] HWInt,          //输入6个设备中断信号
    output Req,                  //进入处理程序请求（有异常或中断）
    output reg [31:0] EBase
    );

    reg [31:0] SR;
    reg [31:0] Cause;
    reg [31:0] EPC;                 //记录异常处理结束后需要返回的PC
    wire ExcReq=!`EXL&&(|ExcCodeIn);               //有中断
    wire IntReq=!`EXL&&`IE&&(|(HWInt & `IM));      //有异常
    assign Req=(ExcReq||IntReq);

    wire [31:0] tmp_EPC = Req?(BDIn?VPC-4:VPC):EPC;     //错误在延迟槽，返回PC应为到上一条跳转指令的PC
    assign EPCOUt = tmp_EPC;

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            SR <= 0;
            Cause <= 0;
            EPC <= 0;
            EBase <= 32'h4180;
        end else begin
            if(EXLClr) `EXL<=0;     //清除

            `IP<=HWInt;             //外部中断

            if(Req) begin
                `ExcCode <= IntReq?0:ExcCodeIn;
                `EXL <= 1;
                EPC <= tmp_EPC;     //错误在延迟槽，返回PC应为到上一条跳转指令的PC
                `BD <= BDIn;
            end else if(en) begin
                if(CP0Add == 12) SR <= CP0In;
                else if(CP0Add == 14) EPC <= CP0In;
                else if(CP0Add == 15) EBase <= CP0In;
            end

        end

    end

    assign CP0Out = (CP0Add == 12) ? SR :
                    (CP0Add == 13) ? Cause :
                    (CP0Add == 14) ? EPC :
                    (CP0Add == 15) ? EBase:
                    0;
    

endmodule
