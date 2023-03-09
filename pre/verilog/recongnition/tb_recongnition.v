`include "recognition.v"
`timescale  1ns / 1ps    

module tb_recognition;   

reg   clk                                  = 0 ;
reg   reset                                = 0 ;
reg   in                                   = 0 ;
wire  out                                  ;

recognition  u_recognition (
    .clk                     ( clk     ),
    .reset                   ( reset   ),
    .in                      ( in      ),

    .out                     ( out     )
);

initial
begin
    $dumpfile("wave.vcd");
	$dumpvars;
    clk=0;
    reset=1;
    in = 0;
    #2 reset=0;
    #2 in=1;
    #2 in=0;
    #2 in=1;
    #2 in=0;
    #2 in=1;
    #10
    $finish;
end
always #1 clk=~clk;
endmodule