`timescale 1ns/1ps
module ALU(
  input  [3:0] inA, inB,
  input  [1:0] op, inC,
  output reg [3:0] ans
    );
  
//利用三目运算符完成运算

// assign ans = (op == 2'b00) ? $signed($signed(inA) >>> inC) :
//          (op == 2'b01) ? inA >> inC :
//          (op == 2'b10) ? inA - inB :
//          (op == 2'b11) ? inA + inB : 4'b000 ; //error

always@(*) begin     //或更推荐用always@(*) + case 
  case(op)
    0: begin
       ans =$signed($signed(inA) >>> inC);
    end
    1: begin
      ans=inA >> inC;
    end
    2: begin
      ans=inA - inB;
    end
    3: begin
      ans=inA + inB;
    end
    default ans=0;
  endcase

end

endmodule