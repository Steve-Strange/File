`timescale 1ns / 1ps
//异常码
`define ExcNone    5'd0
`define ExcAdEL    5'd4

module Fetch(
    input clk,
    input reset,
    input D_Flush,
    input F_Stall,
    input D_Stall,

    output reg [31:0] temp_F_PC,
    input [31:0] F_PC,
    input [31:0] F_Ins,
    output F_DS,
    output [4:0] F_ExcCode,
    output reg [31:0] D_PC,
    output reg [31:0] D_Ins,
    output reg D_DS,
    output reg [4:0] temp_D_ExcCode,

    input [31:0] NPC,
    input [2:0] NPCSelect,
    input Req,
    input D_eret,
    input [31:0] EPC,EBase
    );

    
    always@(posedge clk) begin
        if(reset) temp_F_PC<=32'h00003000;
        else begin
			if(!F_Stall||Req) temp_F_PC<=NPC;    //有中断请求应传入0x4180/EBase，PC需要enable
        end
    end
    
    //指令是否在延迟槽的信号的流水开始
    assign F_DS=(NPCSelect!=0); 
    //取指令异常
    wire F_Exc_AdEL = ((|F_PC[1:0]) | (F_PC < 32'h0000_3000) | (F_PC > 32'h0000_6fff)) && !D_eret;
    assign F_ExcCode=F_Exc_AdEL?`ExcAdEL:`ExcNone;

    //FD
    always @(posedge clk) begin
        if(reset||(!D_Stall&&D_Flush)||Req) begin
            D_PC<=reset?0:
                  Req?EBase:
                  0;
            D_Ins<=0;
            D_DS<=0;
            temp_D_ExcCode<=0;
        end
        else begin
            if(!D_Stall) begin
                D_PC<=F_PC;
                D_Ins<=F_Exc_AdEL?0:F_Ins;
                D_DS<=F_DS;
                temp_D_ExcCode<=F_ExcCode;
            end
        end
    end

endmodule