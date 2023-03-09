`timescale 1ns / 1ps

module IFU(
    input reset,
    input clk,
    input PCSrc,
    input Jump,
    input [31:0] shiftResult,
    input [31:0] jumpAdd,
    output reg [31:0] PC,
    output [31:0] D
    );

    reg [31:0] IM [4095:0];
    wire [31:0] address;
	integer i;

	initial begin
        PC<=32'h00003000;
		$readmemh("code.txt",IM);
	end

    assign D = IM[address[13:2]];

    assign address=PC-32'h00003000;
    always@(posedge clk) begin
        if(reset) PC<=32'h00003000;
        else begin
            PC<=Jump?jumpAdd:(PCSrc?PC+4+shiftResult:PC+4);
        end
    end

endmodule