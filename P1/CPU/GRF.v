`timescale 1ns / 1ps

module GRF(
    input clk,
    input reset,
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

    //内部转发，0号寄存器特判
    assign RD1=((A1==WA)&&(A1!=5'b00000))?WD:GRF[A1];
    assign RD2=((A2==WA)&&(A2!=5'b00000))?WD:GRF[A2];

    // assign RD1=((A1===WA)&&(A1))?WD:GRF[A1];
    // assign RD2=((A2===WA)&&(A2))?WD:GRF[A2];

    always @(posedge clk) begin
        if(reset) for(i=0;i<32;i=i+1) GRF[i]<=0;
        else if(WA!=5'b00000) begin
            GRF[WA]<=WD;
            $display("@%h: $%d <= %h", PC, WA, WD);
        end
    end

    // always@(*) begin
    //     $monitor("%d %d %d",A1,A2,WA);
    // end

endmodule
