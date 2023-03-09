`timescale 1ns/1ps
`include "compare.v"
module compare_tb;
    // Generate clock
    reg clk;
    initial clk = 0;
    always #10 clk = ~clk;

    // Input registers
    reg [3:0] a, b;
    wire [3:0] ans1, ans2, ans3;

    initial begin
        // Initialize Inputs
        a = 0;
        b = 0;

    // Wait 100 ns for global reset to finish
    #100;
        
    a=3;
    b=1;
    $display("%b %b %b",ans1,ans2, ans3);
    #20;

    a=-2;
    b=1;
    $display("%b %b %b",ans1,ans2, ans3);

    #20;
    $finish;

    end

    // Device under test (our adder)
    compare dut(.clk(clk), .a(a), .b(b), .ans1(ans1), .ans2(ans2), .ans3(ans3));
    initial
  begin            
      $dumpfile("compare_tb.vcd");        //生成的vcd文件名称
      $dumpvars(0, compare_tb);    //tb模块名称
  end 
endmodule