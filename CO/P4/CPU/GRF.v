`timescale 1ns / 1ps

module GRF(
    input clk,
    input reset,
    input WE,
    input [4:0] A1,
    input [4:0] A2,
    input [4:0] WA,
    input [31:0] WD,
    output [31:0] RD1,
    output [31:0] RD2,

    input [31:0] PC
    );

    integer i;
    reg [31:0] GRF [31:0];

    assign RD1=GRF[A1];
    assign RD2=GRF[A2];

    always @(posedge clk)
    begin
        if(reset) for(i=0;i<32;i=i+1) GRF[i]<=0;
        else begin
            if((WE==1)&&(WA!=5'b00000)) GRF[WA]<=WD;
            if(WE)
            begin
                $display("@%h: $%d <= %h", PC, WA, WD);
            end
        end
    end
endmodule
