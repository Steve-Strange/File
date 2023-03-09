`timescale 1ns / 1ps
module E_ALU(
    input [3:0] op,
    input [31:0] A,
    input [31:0] B,
    output [31:0] Y,
    output Exc_Ov
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

    wire [32:0] ext_A = {A[31], A};
    wire [32:0] ext_B = {B[31], B};
    wire [32:0] ext_add = ext_A + ext_B;
    wire [32:0] ext_sub = ext_A - ext_B;

    assign Exc_Ov = ((op == 4'b0000 && ext_add[32] != ext_add[31]) ||(op == 4'b0001 && ext_sub[32] != ext_sub[31]));

endmodule
