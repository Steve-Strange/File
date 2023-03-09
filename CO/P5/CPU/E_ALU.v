`timescale 1ns / 1ps
module ALU(
    input [2:0] op,
    input [31:0] A,
    input [31:0] B,
    output [31:0] Y,
    output Greater,
    output Equal,
    output Less
    );


    assign Y=(op==3'b000)?A+B:
             (op==3'b001)?A-B:
             (op==3'b010)?A|B:
             (op==3'b011)?{B[15:0],16'b0}:
             (op==3'b100)?A^B:
             (op==3'b101)?((($signed(A)>$signed(B)))?(A-B):(B-A)):
             0;

    
    assign Greater=($signed(A)>$signed(B));       //$signed
    always @(*) begin
        $monitor("%h %h %h",A,B,Y);
    end
    assign Equal=(A==B);
    assign Less=(A<B);

endmodule
