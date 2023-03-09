`timescale 1ns / 1ps
//异常码
`define ExcNone    5'd0
`define ExcAdES    5'd5
`define ExcOv      5'd12

module Execute(
    input clk,
    input reset,
    input Req,

    input [31:0] E_PC,
    input [31:0] E_Ins,
    input E_DS,
    input [4:0] temp_E_ExcCode,
    output [4:0] E_ExcCode,
    output reg [31:0] M_PC,
    output reg [31:0] M_Ins,
    output reg M_DS,
    output reg [4:0] temp_M_ExcCode,
    output reg M_Exc_DMOv,

    output [1:0] E_Tnew,        //AT算阻塞
    output [4:0] E_GRF_WA,      //写的寄存器
    output [31:0] E_GRF_WD,     //写的东西
    
    output [4:0] E_rs, E_rt,E_rd,                    //读的寄存器
    input [31:0] E_rs_fw,E_rt_fw,             //接收转发后结果

    output reg [31:0] M_rt_data,     //M级DM写入地址需要rt寄存器正确结果
    
    output MDU,
    output MDUStart,
    output MDUBusy,

    input E_branchTrue,
    input [31:0] E_EXT_out,
    output reg [31:0] M_ALU_Y,
    output reg M_branchTrue,
    output reg [31:0] M_HI,M_LO,

    output E_eret,
    output E_mtc0,
    input [31:0] EBase
    );

    //CU
    wire [3:0] ALUSelect;
    wire ALUSrc;
    wire [2:0] GRF_WDSrc;
    wire [2:0] MDUSelect;
    wire ALUDM,ALUAri;
    //ALU+MDU
    wire [31:0] A,B,E_ALU_Y;
    wire [31:0] E_HI,E_LO;

    assign E_GRF_WD=(GRF_WDSrc==3'b010)?E_PC+8:
                    32'b0;       //E级可转发出D级算的PC+8（根据当前指令写入地址判断）

    assign A=E_rs_fw;
    assign B=ALUSrc?E_EXT_out:E_rt_fw;      //ALUSrc=0：计算指令  ALUSrc=1：地址指令

    //计算指令溢出，地址指令溢出
    wire Exc_Ov;
    wire E_Exc_AriOv=ALUAri&&Exc_Ov;
    wire E_Exc_DMOv=ALUDM&&Exc_Ov;     //在M级才会出现异常，需要流水

    assign E_ExcCode=temp_E_ExcCode?temp_E_ExcCode:
                     E_Exc_AriOv?`ExcOv:
                     `ExcNone;

    always @(posedge clk) begin
        if(reset||Req) begin
            M_PC<=reset?0:
                  Req?EBase:
                  0;
            M_Ins<=0;
            M_ALU_Y<=0;
            M_rt_data<=0;
            M_branchTrue<=0;
            M_HI<=0;
            M_LO<=0;
            M_DS<=0;
            temp_M_ExcCode<=0;
            M_Exc_DMOv<=0;
        end
        else begin
            M_PC<=E_PC;
            M_Ins<=E_Ins;
            M_ALU_Y<=E_ALU_Y;
            M_rt_data<=E_rt_fw;
            M_branchTrue<=E_branchTrue;
            M_HI<=E_HI;
            M_LO<=E_LO;
            M_DS<=E_DS;
            temp_M_ExcCode<=E_ExcCode;
            M_Exc_DMOv<=E_Exc_DMOv;
        end
    end

CU E_cu (
    .Ins(E_Ins),
    .branchTrue(E_branchTrue),
    .E_Tnew(E_Tnew),
    .mtc0(E_mtc0),
    
    .rs(E_rs),
    .rt(E_rt),
    .rd(E_rd),
    .GRF_WA(E_GRF_WA),
    .ALUSrc(ALUSrc),
    .ALUSelect(ALUSelect),
    .GRF_WDSrc(GRF_WDSrc),
    .MDU(MDU),
    .MDUStart(MDUStart),
    .MDUSelect(MDUSelect),

    .ALUDM(ALUDM),
    .ALUAri(ALUAri),

    .eret(E_eret)
    );

E_ALU E_alu (
    .op(ALUSelect), 
    .A(A),
    .B(B), 
    .Y(E_ALU_Y),
    .Exc_Ov(Exc_Ov)
    );

E_MDU E_mdu (
    .clk(clk), 
    .reset(reset), 
    .Req(Req),
    .Start(MDUStart), 
    .MDUSelect(MDUSelect), 
    .A(A), 
    .B(B), 
    .Busy(MDUBusy), 
    .LO(E_LO), 
    .HI(E_HI)
    );


endmodule
