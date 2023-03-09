`timescale 1ns / 1ps

module CU(
    input [5:0] opcode,
    input [5:0] funct,
    output RegWrite,
    output [2:0] GRF_WASrc,
    output [2:0] GRF_WDSrc,
    output ALUSrc,
    output [2:0] ALUSelect,
    output MemWrite,
    output EXTSelect,
    output Branch,
    output [2:0] BranchSelect,
    output Jump,
    output Jr,
    output ByteLW
    );

    wire R,add,sub,xOr,ori,lui,lw,sw,j,beq,bne,jal,jr,sll,lb,sb;
    
    assign R=(opcode==0);
    assign add =(R&&funct==6'b100000); 
    assign sub =(R&&funct==6'b100010);
    assign xOr =(R&&funct==6'b100110);
    assign ori =(opcode==6'b001101); 
    assign lui =(opcode==6'b001111);
    assign sw  =(opcode==6'b101011);  
    assign lw  =(opcode==6'b100011); 
    assign beq =(opcode==6'b000100);
    assign bne =(opcode==6'b000101);
    assign j   =(opcode==6'b000010); 
    assign jal =(opcode==6'b000011); 
    assign jr  =(R&&funct==6'b001000);
    assign sll =(R&&funct==6'b000000);
    assign lb  =(opcode==6'b100000);
    assign sb  =(opcode==6'b101000);

    assign RegWrite=(add||sub||ori||lw||lui||jal||sll||xOr||lb);
    assign GRF_WASrc=(add||sub||sll||xOr)?3'b001:       //rd
                     (jal)?3'b010:                      //31
                           3'b000;                      //rt 

    assign GRF_WDSrc=(lw||lb)?3'b001:                   //DM_RD
                     (jal)?3'b010:                      //PC+4
                     (sll)?3'b011:                      //sllResult
                           3'b000;                      //ALU_Y

    assign MemWrite=(sw||sb);
    assign ALUSrc=(ori||lw||sw||lui||lb||sb);           //0:EXT,1:GRF_RD2
    assign ALUSelect=(sub)?3'b001:                     //-
                      (ori)?3'b010:                     //|
                      (lui)?3'b011:                     //{B[15:0],16'b0}
                      (xOr)?3'b100:                     //^
                            3'b000;                     //+
    
    assign EXTSelect=(ori||lui);                        //0:SignEXT,1:ZeroEXT
    assign Branch=(bne||beq);
    assign BranchSelect=(beq)?3'b000:                  //==
                        (bne)?3'b001:                  //. !=
                              3'b000;

    assign Jump=(j||jal||jr);
    assign Jr=(jr);
    assign ByteLW=(lb||sb);

endmodule
