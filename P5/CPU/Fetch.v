`timescale 1ns / 1ps

module Fetch(
    input clk,
    input reset,
    input D_Flush,
    input F_Stall,
    input D_Stall,
    input [31:0] NPC,
    output [31:0] F_PC,
    output reg [31:0] D_PC,
    output reg [31:0] D_Ins
    );
    wire [31:0] F_Ins;

    // always@(*) begin
    //     $monitor(D_Flush,D_Stall);
    // end

    //FD
    always @(posedge clk) begin
        if(reset) begin
            D_PC<=0;
            D_Ins<=0;
        end
        else begin
            if(!D_Stall) begin
                D_PC<=F_PC;
                D_Ins<=F_Ins;
            end
        end
    end

F_IFU F_ifu (
    .clk(clk), 
    .reset(reset),
	.F_Stall(F_Stall),
    .PC(F_PC),
    .NPC(NPC),
    .Ins(F_Ins)
    );

endmodule