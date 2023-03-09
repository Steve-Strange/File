`timescale 1ns / 1ps
`define ExcAdEL    5'd4
`define ExcAdES    5'd5
`define ExcNone    5'd0

`define StartAddrDM         32'h0000_0000
`define EndAddrDM           32'h0000_2fff
`define StartAddrTC1        32'h0000_7f00
`define EndAddrTC1          32'h0000_7f0b
`define StartAddrTC2        32'h0000_7f10
`define EndAddrTC2          32'h0000_7f1b
`define StartInt            32'h0000_7f20
`define EndInt              32'h0000_7f23

module Memory(
    input clk,
    input reset,
    input Req,

    input [31:0] M_PC,
    input [31:0] M_Ins,
    input [31:0] M_CP0Out,
    output reg [31:0] W_PC,
    output reg [31:0] W_Ins,
    output reg [31:0] W_CP0Out,

    input [4:0] temp_M_ExcCode,
    input M_Exc_DMOv,
    output [4:0] M_ExcCode,

    input M_branchTrue,
    output [1:0] M_Tnew,        //AT算阻塞
    output [4:0] M_GRF_WA,      //写的寄存器
    output [31:0] M_GRF_WD,     //写的东西
    output [4:0] M_rt,          //读的寄存器
    output [4:0] M_rd,

    input [31:0] M_HI,M_LO,
    input [31:0] M_ALU_Y,
    input [31:0] M_DM_RDin,

    input [31:0] M_rt_fw,             //M级接收转发后将写入DM的数据
    output reg [31:0] M_DM_WD,

    output reg [3:0] ByteEn,

    output reg [31:0] W_HI,W_LO,
    output reg [31:0] W_ALU_Y,
    output reg [31:0] W_DM_RD,
    output reg W_branchTrue,

    output M_eret,
    output M_CP0en,
    input [31:0] EBase
    );

    //CU
    wire [2:0] GRF_WDSrc;
    wire MemWrite;
    wire [1:0] MFSelect;
    wire [1:0] ByteSelect;
    wire [2:0] DESelect;

 
    assign M_GRF_WD=(MFSelect==2'b00)?M_HI:
                    (MFSelect==2'b01)?M_LO:
                    (GRF_WDSrc==3'b000)?M_ALU_Y:
                    (GRF_WDSrc==3'b010)?M_PC+8:
                    32'b0;       //M级可转发出D级算的PC+8和E级算的的ALU_Y（根据当前指令写入地址判断）
    
    // assign M_DM_A=M_ALU_Y;
    wire [7:0] byte=M_rt_fw[7:0];
    wire [15:0] halfword=M_rt_fw[15:0];
    wire [31:0] word=M_rt_fw[31:0];
    
    wire [1:0] lowAddr;
    assign lowAddr=M_ALU_Y[1:0];

    always@(*) begin
        if(MemWrite&&!Req) begin
            if(ByteSelect==2'b00) begin
                if(lowAddr==0) ByteEn=4'b0001;
                else if(lowAddr==1) ByteEn=4'b0010;
                else if(lowAddr==2) ByteEn=4'b0100;
                else ByteEn=4'b1000;
            end
            else if(ByteSelect==2'b01) begin
                if(lowAddr==0) ByteEn=4'b0011;
                else ByteEn=4'b1100;
            end
            else if(ByteSelect==2'b10) ByteEn=4'b1111;
            else ByteEn=4'b0000;
        end
        else ByteEn=4'b0000;
    end

    always@(*) begin
        if(ByteEn==4'b1111) M_DM_WD=word;
        else if(ByteEn==4'b1100) M_DM_WD={halfword,16'b0};
        else if(ByteEn==4'b0011) M_DM_WD={16'b0,halfword};
        else if(ByteEn==4'b1000) M_DM_WD={byte,24'b0};
        else if(ByteEn==4'b0100) M_DM_WD={8'b0,byte,16'b0};
        else if(ByteEn==4'b0010) M_DM_WD={16'b0,byte,8'b0};
        else if(ByteEn==4'b0001) M_DM_WD={24'b0,byte};
        else M_DM_WD=0;
    end

    wire [31:0] M_DM_RDout;     //内存读出的数据拓展后的结果，正式作为写入GRF的结果输出

    wire load,save;
    //不可读写字不对齐，超出范围的内存
    wire ErrAlign = ((ByteSelect == 2'b10)&&(|M_ALU_Y[1:0]))||
                    ((ByteSelect == 2'b01)&&M_ALU_Y[0]);
    wire ErrOutOfRange = !(((M_ALU_Y >= `StartAddrDM ) && (M_ALU_Y <= `EndAddrDM )) ||
                           ((M_ALU_Y >= `StartAddrTC1) && (M_ALU_Y <= `EndAddrTC1)) ||
                           ((M_ALU_Y >= `StartAddrTC2) && (M_ALU_Y <= `EndAddrTC2)) ||
                           ((M_ALU_Y >= `StartInt) && (M_ALU_Y <= `EndInt)));
    //不可用lb,lh读写timer中的三个寄存器
    wire ErrTimer = ((ByteSelect == 2'b00)||(ByteSelect == 2'b01)) && (M_ALU_Y >= `StartAddrTC1);
    //不可修改timer中的count寄存器
    wire ErrSaveTimer = (M_ALU_Y >= 32'h0000_7f08 && M_ALU_Y <= 32'h0000_7f0b) ||
                        (M_ALU_Y >= 32'h0000_7f18 && M_ALU_Y <= 32'h0000_7f1b);

    wire M_Exc_AdES=save&&(ErrAlign || ErrOutOfRange || ErrTimer || ErrSaveTimer || M_Exc_DMOv);
    wire M_Exc_AdEL=load&&(ErrAlign || ErrOutOfRange || ErrTimer || M_Exc_DMOv);

    assign M_ExcCode =  (temp_M_ExcCode) ? temp_M_ExcCode :     //次序注意
                        (M_Exc_AdES) ? `ExcAdES :
                        (M_Exc_AdEL) ? `ExcAdEL :
                        `ExcNone;


    always @(posedge clk) begin
        if(reset||Req) begin
            W_PC<=reset?0:
                  Req?EBase:
                  0;
            W_Ins<=0;
            W_ALU_Y<=0;
            W_DM_RD<=0;
            W_branchTrue<=0;
            W_HI<=0;
            W_LO<=0;
            W_CP0Out<=0;
        end
        else begin
            W_PC<=M_PC;
            W_Ins<=M_Ins;
            W_ALU_Y<=M_ALU_Y;
            W_DM_RD<=M_DM_RDout;
            W_branchTrue<=M_branchTrue;
            W_HI<=M_HI;
            W_LO<=M_LO;
            W_CP0Out<=M_CP0Out;
        end
    end

CU M_cu (
    .Ins(M_Ins),
    .branchTrue(M_branchTrue),
    .M_Tnew(M_Tnew),
    .GRF_WA(M_GRF_WA),

    .rt(M_rt),
    .rd(M_rd),
    .GRF_WDSrc(GRF_WDSrc),
    .MFSelect(MFSelect),
    .ByteSelect(ByteSelect),
    .DESelect(DESelect),
    .MemWrite(MemWrite),

    .eret(M_eret),
    .load(load),
    .save(save),
    .mtc0(M_CP0en)
    );  


M_DE M_de (
    .lowAddr(lowAddr), 
    .DESelect(DESelect), 
    .in(M_DM_RDin), 
    .out(M_DM_RDout)
    );

endmodule
