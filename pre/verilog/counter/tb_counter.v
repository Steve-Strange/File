`timescale 1ns/1ps
`include "counter.v"
module tb_counter;

// code Parameters
parameter PERIOD  = 10;
// code Inputs
reg   Clk                                  = 0 ;
reg   Reset                                = 0 ;
reg   Slt                                  = 0 ;
reg   En                                   = 0 ;

// code Outputs
wire  [63:0]  Output0                      ;
wire  [63:0]  Output1                      ;


initial
begin
    forever #(PERIOD/2)  Clk=~Clk;
end

code  u_code (
    .Clk                     ( Clk             ),
    .Reset                   ( Reset           ),
    .Slt                     ( Slt             ),
    .En                      ( En              ),

    .Output0                 ( Output0  [63:0] ),
    .Output1                 ( Output1  [63:0] )
);

initial
begin
    Reset=0;
    En=0;
    Slt=0;
    #20;
    Reset=0;
    En=1;   
    Slt=0; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=0; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=1;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    Reset=0;
    En=1;   
    Slt=1; 
    #10;
    $display ("%d %d",Output0,Output1);
    #5;
    $finish;
end

    initial
  begin
      $dumpfile("tb_counter.vcd");        //生成的vcd文件名称
      $dumpvars(0, tb_counter);    //tb模块名称
  end 
endmodule