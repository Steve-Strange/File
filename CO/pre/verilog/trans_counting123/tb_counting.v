`timescale  1ns / 1ps
`include "counting123.v"
module tb_counting;

// counting Parameters
parameter PERIOD  = 10;

// counting Inputs
reg   [1:0]  num                           = 0 ;
reg   clk                                  = 0 ;
// counting Outputs
wire  ans                                  ;

initial
begin
    forever #(PERIOD/2)  clk=~clk;
end


counting  u_counting (
    .num                     ( num  [1:0] ),
    .clk                     ( clk        ),

    .ans                     ( ans        )
);

initial
begin
    num=0;
    clk=0;
    #20;
    num=1;
    @(negedge clk);
    $display("%d ",ans);

        num=1;
@(negedge clk);
    $display("%d ",ans);

    num=2;
@(negedge clk);
    $display("%d ",ans);
        num=3;
@(negedge clk);
    $display("%d ",ans);

    num=3;
@(negedge clk);
    $display("%d ",ans);

    num=1;
@(negedge clk);
    $display("%d ",ans);

    num=2;
@(negedge clk);
    $display("%d ",ans);

    num=1;
@(negedge clk);
    $display("%d ",ans);

        num=1;
@(negedge clk);
    $display("%d ",ans);

        num=1;
@(negedge clk);
    $display("%d ",ans);

        num=2;
@(negedge clk);
    $display("%d ",ans);

     num=2;
@(negedge clk);
    $display("%d ",ans);

 num=3;
@(negedge clk);
    $display("%d ",ans);

        num=3;
@(negedge clk);
    $display("%d ",ans);
    
        num=3;
@(negedge clk);
        $display("%d ",ans);

                num=1;
@(negedge clk);
        $display("%d ",ans);

    #20;
    $finish;
end
  initial
  begin            
      $dumpfile("tb_counting.vcd");        //生成的vcd文件名称
      $dumpvars(0, tb_counting);    //tb模块名称
  end 
endmodule