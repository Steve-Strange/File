`timescale 1ns / 1ps
`define s0 0
`define s1 1
`define s2 2
`define s3 3

module recognition(
    input in,
    input clk,
    input reset,
    output reg out
    );
    reg [1:0] status=`s0;

    always@(posedge clk, reset) begin
        out<=0;
        if (reset) begin
            out<=0;
            status<=`s0;
        end
        else begin
            if(status==`s0) begin
                if(in) status<=`s1;
                else status<=`s0;
            end
            else if (status==`s1) begin
                if(in==0) status<=`s2;
                else status<=`s1;
            end
            else if (status==`s2) begin
                if(in) begin
                    out<=1;
                    status<=`s3;
                end
                else status<=`s0;
            end
            else if (status==`s3) begin
                if(in) status<=`s1;
                else status<=`s2;
            end
        end
    end

endmodule
