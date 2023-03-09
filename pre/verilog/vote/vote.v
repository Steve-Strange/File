`timescale 1ns / 1ps
module vote(
    input a,
    input b,
    input c,
    input d,
    input e,
	input clk,
	input rst,
    output reg Y
    );
	reg [3:0] sum=0;
	initial Y=0;
	always@(posedge clk)
	begin
		if(rst==1) Y<=0;
		else begin
			sum<=a+b+c+d+e;
			if (sum>=3) Y<=1;
			else Y<=0;
		end
	end
endmodule