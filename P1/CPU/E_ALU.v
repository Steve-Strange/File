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
             0;

    reg [31:0] ans;
    always @(*) begin
        ans=-(A+B);
        $display("%d %d %d",A,B,ans);
    end

    assign Greater=(A>B);       //$signed
    assign Equal=(A==B);
    assign Less=(A<B);

endmodule
