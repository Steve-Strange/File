`timescale 1ns/1ps
`include "ALU.v"
module tb_ALU;

  reg clk;
  initial clk = 0;
  always #1 clk = ~clk;

  // Input registers
  reg [3:0] inA,inB;
  reg [1:0] op;
  wire [3:0] ans;

  initial begin
    inA=0;
    inB=0;
    op=0;
    #10;
        
    inA=2;
    inB=3;
    op=2;
    #2;
    $display("%d",ans);

    inA=2;
    inB=3;
    op=2'b11;
    #2;
    $display("%d",ans);
    #2;
    // Exit the simulation
    $finish;

  end

  ALU dut(.inA(inA), .inB(inB), .op (op), .ans(ans));
  initial
  begin            
      $dumpfile("tb_ALU.vcd");        //生成的vcd文件名称
      $dumpvars(0, tb_ALU);    //tb模块名称
  end 
endmodule