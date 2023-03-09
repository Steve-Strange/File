`timescale 1ns / 1ps

module F_IFU(
    input clk,
    input reset,
    input F_Stall,
    input [31:0] NPC,
    output reg [31:0] PC,
    output [31:0] Ins
    );

    reg [31:0] IM [4095:0];
    wire [31:0] address;
	integer i;

	initial begin
        PC<=32'h00003000;
		$readmemh("code.txt",IM);
	end

    assign address=PC-32'h00003000;
    assign Ins = IM[address[13:2]];     //清空延迟槽的时候给0

    always@(posedge clk) begin
        if(reset) PC<=32'h00003000;
        else begin
			if(!F_Stall) PC<=NPC;
        end
    end
    
endmodule