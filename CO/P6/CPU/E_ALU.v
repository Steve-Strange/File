`timescale 1ns / 1ps
module E_ALU(
    input [3:0] op,
    input [31:0] A,
    input [31:0] B,
    output [31:0] Y
    );

    assign Y=(op==4'b0000)?A+B:
             (op==4'b0001)?A-B:
             (op==4'b0010)?A|B:
             (op==4'b0011)?{B[15:0],16'b0}:
             (op==4'b0100)?A^B:
             (op==4'b0101)?A&B:
             (op==4'b0110)?$signed(A)<$signed(B):
             (op==4'b0111)?A<B:
             0;

    // reg [31:0] max;
    // reg [31:0] min;
    // always @(*) begin
    //     if($signed(A)>$signed(B)) begin
    //         max=A;
    //         min=B;
    //     end
    //     else begin
    //         max=B;
    //         min=A;
    //     end
    // end

endmodule
