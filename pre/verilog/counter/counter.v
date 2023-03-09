`timescale 1ns/1ps
module code (
    input Clk,
    input Reset,
    input Slt,
    input En,
    output reg [63:0] Output0,
    output reg [63:0] Output1
);
    initial begin
        Output0=0;
        Output1=0;
    end
    integer temp=0;
    always @ (posedge Clk) begin
        if(Reset) begin
            Output0<=0;
            Output1<=0;
            temp<=0;
        end else if(En) begin
            if(!Slt) Output0<=Output0+1;
            else begin
                temp=temp+1;
                if(temp==4) begin
                    Output1<=Output1+1;
                    temp<=0;
                end
            end
        end
        else ;
    end
endmodule