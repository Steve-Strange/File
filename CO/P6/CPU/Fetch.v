`timescale 1ns / 1ps

module Fetch(
    input clk,
    input reset,
    input D_Flush,
    input F_Stall,
    input D_Stall,
    input [31:0] NPC,
    output reg [31:0] F_PC,
    input [31:0] F_Ins,
    output reg [31:0] D_PC,
    output reg [31:0] D_Ins
    );

    always@(posedge clk) begin
        if(reset) F_PC<=32'h00003000;
        else begin
			if(!F_Stall) F_PC<=NPC;
        end
    end
    // always@(*) begin
    //     $monitor(D_Flush,D_Stall);
    // end

    //FD
    always @(posedge clk) begin
        if(reset||(D_Flush&&!D_Stall)) begin
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

endmodule