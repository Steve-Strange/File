`timescale 1ns / 1ps

module Memory(
    input clk,
    input reset,

    input [31:0] M_PC,
    input [31:0] M_Ins,
    output reg [31:0] W_PC,
    output reg [31:0] W_Ins,

    output [1:0] M_Tnew,        //AT算阻塞
    output [4:0] M_GRF_WA,      //写的寄存器
    output [31:0] M_GRF_WD,     //写的东西
    
    output [4:0] M_rt,                //读的寄存器
    output [31:0] M_rt_data,          //寄存器原读数
    input [31:0] M_rt_fw,             //接收转发后结果

    input M_branchTrue,
    input [31:0] M_ALU_Y,
    output reg [31:0] W_DM_RD,
    output reg [31:0] W_ALU_Y,
    output reg W_branchTrue
    );

    //CU
    wire lhogez;
    wire [2:0] GRF_WDSrc;
    wire MemWrite;
    wire ByteLW;
    //DM
    wire [31:0] M_DM_A;
    wire [31:0] M_DM_WD;
    wire [31:0] M_DM_RD;
 
    assign M_GRF_WD=(GRF_WDSrc==3'b000)?M_ALU_Y:
                    (GRF_WDSrc==3'b010)?M_PC+8:
                    32'bz;       //M级可转发出D级算的PC+8和E级算的的ALU_Y（根据当前指令写入地址判断）
     
    assign M_DM_A=M_ALU_Y;
    assign M_DM_WD=M_rt_fw;

    
    always @(posedge clk) begin
        if(reset) begin
            W_PC<=0;
            W_Ins<=0;
            W_ALU_Y<=0;
            W_DM_RD<=0;
            W_branchTrue<=0;
        end
        else begin
            W_PC<=M_PC;
            W_Ins<=M_Ins;
            W_ALU_Y<=M_ALU_Y;
            W_DM_RD<=M_DM_RD;
            W_branchTrue<=M_branchTrue;
        end
    end

CU M_cu (
    .Ins(M_Ins),
    .branchTrue(M_branchTrue),
    .M_Tnew(M_Tnew),
    .GRF_WA(M_GRF_WA),
    .lhogez(lhogez),

    .rt(M_rt),
    .GRF_WDSrc(GRF_WDSrc),
    .ByteLW(ByteLW),
    .MemWrite(MemWrite)
    );  

M_DM M_dm (
    .reset(reset), 
    .clk(clk), 
    .WE(MemWrite),
    .ByteLW(ByteLW),
    .A(M_DM_A), 
    .WD(M_DM_WD), 
    .RD(M_DM_RD),
    .PC(M_PC)
    );

endmodule
