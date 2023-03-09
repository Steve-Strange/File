`timescale 1ns / 1ps

module CU(
    input [31:0] Ins,
    input branchTrue,           //branch通路要改

    // output RegWrite,
    output [4:0] GRF_WA,        //直接输出地址
    output [2:0] GRF_WDSrc,
    output ALUSrc,
    output [2:0] ALUSelect,
    output MemWrite,
    output EXTSelect,
    output [2:0] BranchSelect,
    output [2:0] NPCSelect,
    output ByteLW,

    output [5:0] opcode,funct,
    output [4:0] rs,rt,rd,
    output [4:0] shamt,
    output [15:0] imm16,
    output [25:0] imm26,

    output [1:0] Tuse_rs,
    output [1:0] Tuse_rt,
    output [1:0] E_Tnew,
    output [1:0] M_Tnew
    );
	
    wire R,add,sub,xOr,ori,lui,lw,sw,j,beq,bne,jal,jr,sll,lb,sb,bltzal;
    wire cal_r,cal_i,load,save,branch,shift,jreg,jadd,jlink;
    
    assign {opcode,rs,rt,rd,shamt,funct}=Ins;
    assign imm16 = {rd,shamt,funct};
    assign imm26 = {rs,rt,rd,shamt,funct};

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
    assign bltzal=(opcode==6'b000001);

    assign cal_r=(add||sub||xOr);
	assign cal_i=(ori||lui);
	assign load=(lw||lb);
	assign save=(sw||sb);
	assign branch=(beq||bne);
    assign shift=sll;

    assign jreg = jr;
    assign jadd = (j||jal);
    assign jlink = jal;


    // assign RegWrite=(cal_r||cal_i||jlink||shift||load);
    assign GRF_WA=  (cal_i||load)?rt:
                    (cal_r||shift)?rd:
                    (jlink||(bltzal&&branchTrue))?5'd31:
                    5'b00000;     //不写，就写去0，注意link地址和前提条件：&&branchTrue
    
    assign GRF_WDSrc=(load)?3'b001:                  //DM_RD
                     (jlink)?3'b010:                 //PC+4 (PC+8)
                     3'b000;                         //ALU_Y

    assign MemWrite=(save);
    assign ALUSrc=(cal_i||load||save);               //0:EXT,1:GRF_RD2
    assign ALUSelect= (sub)?3'b001:                     //-
                      (ori)?3'b010:                     //|
                      (lui)?3'b011:                     //{B[15:0],16'b0}
                      (xOr)?3'b100:                     //^
                      3'b000;                           //+
    assign EXTSelect=(cal_i);                           //0:SignEXT,1:ZeroEXT
    assign BranchSelect= (beq)?3'b000:                  //==
                         (bne)?3'b001:                  //. !=
                         (bltzal)?3'b010:
                         3'b100;
    assign NPCSelect=(branch||bltzal)?3'b001:       //PC+8+offset
                     (jreg)?3'b010:                 //GPR[rs]
                     (jadd)?3'b100:                 //imm26
                      3'b000;                       //PC+4
    assign ByteLW=(lb||sb);


	assign Tuse_rs= (branch||jreg||bltzal)?0:
				    (cal_r||(cal_i&&!shift)||save||load)?1:
					3;
	assign Tuse_rt= (branch)?0:
					(cal_r)?1:
					(save)?2:
					3;
	assign E_Tnew=  (cal_r||cal_i)?1:
					(load)?2:
					0;
	assign M_Tnew=  (load)?1:
					0;

endmodule