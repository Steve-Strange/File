`timescale  1ns / 1ps
`include "id_fsm.v"
module tb_id_fsm;
// id_fsm Parameters
parameter PERIOD  = 10;

// id_fsm Inputs
reg   [7:0]  char                          = 0 ;
reg   clk                                  = 0 ;
// id_fsm Outputs
wire  out                                  ;

initial
begin
    forever #(PERIOD/2)  clk=~clk;
end


id_fsm  u_id_fsm (
    .char                    ( char  [7:0] ),
    .clk                     ( clk         ),

    .out                     ( out         )
);

initial
begin
    char=30;
    #20;
    $display("%d",out);
    char=88;
    #10;
    $display("%d",out);
        char=30;
    #10;
    $display("%d",out);
        char=30;
    #10;
    $display("%d",out);
        char=29;
    #10;
    $display("%d",out);
        char=89;
    #10;
    $display("%d",out);
    $finish;
end
    initial
    begin
        $dumpfile("tb_id_fsm.vcd");        //生成的vcd文件名称
        $dumpvars(0, tb_id_fsm);    //tb模块名称
    end 
endmodule