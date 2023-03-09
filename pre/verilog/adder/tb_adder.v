`timescale 1ns/1ps
`include "adder.v"
module tb_adder;
  reg clk;
  initial clk = 0;
  always #10 clk = ~clk;

  // Input registers
  reg [31:0] a, b;
  wire [31:0] c;

  initial begin
    a = 0;
    b = 0;
    @(posedge clk);
    a = 32'h631;
    b = 341;
    @(posedge clk);
    $display("%d + %d = %d\n", a, b, c);
    a = 32'o1461;
    b = 0;
    @(posedge clk);
    $display("%d + %d = %d\n", a, b, c);

    #20;
    // Exit the simulation
    $finish;
  end

  adder dut(.clk(clk), .in1(a), .in2(b), .out(c));
  initial
  begin            
      $dumpfile("tb_adder.vcd");        //生成的vcd文件名称
      $dumpvars(0, tb_adder);    //tb模块名称
  end 
endmodule