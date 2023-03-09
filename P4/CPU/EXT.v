module EXT(
	input [15:0] in,
	input EXTSelect,
	output [31:0] out
	);
	
	assign out=EXTSelect?{16'b0,in}:({{16{in[15]}},in});
    
endmodule
