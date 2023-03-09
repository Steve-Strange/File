`timescale 1ns / 1ps
module mips(
    input clk,
    input reset
    );
    wire [31:0] PC;
    //IFU
    wire [31:0] Ins;    
    wire [31:26] opcode;
    wire [25:21] rs;
    wire [20:16] rt;
    wire [15:11] rd;
    wire [10:6] shamt;
    wire [5:0] funct;

    //CU
    wire RegWrite;
    wire [2:0] GRF_WASrc;
    wire [2:0] GRF_WDSrc;
    wire EXTSelect;
    wire MemWrite;
    wire ByteLW;
    wire ALUSrc;
    wire [2:0] ALUSelect;
    wire Branch;
    wire [2:0] BranchSelect;
    wire Jump;
    wire Jr;
    wire PCSrc;
    wire [15:0] offset;
    wire [31:0] jumpAdd;

    //GRF
    wire [4:0] GRF_A1;
    wire [4:0] GRF_A2;
    wire [4:0] GRF_WA;
    wire [31:0] GRF_WD;
    wire [31:0] GRF_RD1;
    wire [31:0] GRF_RD2;

    //ALU
    wire [31:0] ALU_A;
    wire [31:0] ALU_B;
    wire [31:0] ALU_Y;
    wire Greater;
    wire Equal;
    wire Less;

    //DM
    wire [31:0] DM_A;
    wire [31:0] DM_WD;
    wire [31:0] DM_RD;

    //EXT
    wire [15:0] EXT_in;
    wire [31:0] EXT_out;
    wire [31:0] shiftResult;
    wire [31:0] sllResult;

    //IFU
    assign {opcode,rs,rt,rd,shamt,funct}=Ins;
    //CU
    assign PCSrc=Branch&&
                 ((BranchSelect==3'b000)?Equal:
                  (BranchSelect==3'b001)?~Equal:
                  0);
    assign offset={rd,shamt,funct};
    assign jumpAdd=Jr?GRF_RD1:{{PC[31:28]},rs,rt,offset,2'b0};
    //GRF
    assign GRF_A1=rs;
    assign GRF_A2=rt;
    assign GRF_WA=(GRF_WASrc==3'b000)?rt:
                  (GRF_WASrc==3'b001)?rd:
                  (GRF_WASrc==3'b010)?5'd31:
                  0;

    assign GRF_WD=(GRF_WDSrc==3'b000)?ALU_Y:
                  (GRF_WDSrc==3'b001)?DM_RD:
                  (GRF_WDSrc==3'b010)?PC+4:
                  (GRF_WDSrc==3'b011)?sllResult:
                  9999;

    //ALU
    assign ALU_A=GRF_RD1;
    assign ALU_B=ALUSrc?EXT_out:GRF_RD2;
    //DM
    assign DM_A=ALU_Y;
    assign DM_WD=GRF_RD2;
    //EXT
    assign EXT_in=offset;
    assign shiftResult={EXT_out,2'b00};
    assign sllResult=GRF_RD2<<shamt;


IFU ifu (
    .reset(reset),
    .clk(clk), 
    .PCSrc(PCSrc), 
    .Jump(Jump), 
    .shiftResult(shiftResult),
    .jumpAdd(jumpAdd), 
    .PC(PC),
    .D(Ins)
    );
	
DM dm (
    .reset(reset), 
    .clk(clk), 
    .WE(MemWrite),
    .ByteLW(ByteLW),
    .A(DM_A), 
    .WD(DM_WD), 
    .RD(DM_RD),
    .PC(PC)
    );
	
GRF grf (
    .clk(clk), 
    .reset(reset), 
    .WE(RegWrite), 
    .A1(GRF_A1), 
    .A2(GRF_A2), 
    .WA(GRF_WA), 
    .WD(GRF_WD), 
    .RD1(GRF_RD1), 
    .RD2(GRF_RD2),
    .PC(PC)
    );
	
ALU alu (
    .op(ALUSelect), 
    .A(ALU_A),
    .B(ALU_B), 
    .Y(ALU_Y), 
    .Greater(Greater), 
    .Equal(Equal), 
    .Less(Less)
    );

EXT ext (
    .in(EXT_in), 
    .EXTSelect(EXTSelect), 
    .out(EXT_out)
    );
	

CU cu (
    .opcode(opcode), 
    .funct(funct), 
    .RegWrite(RegWrite), 
    .ALUSrc(ALUSrc), 
    .Branch(Branch), 
    .BranchSelect(BranchSelect),
    .MemWrite(MemWrite), 
    .EXTSelect(EXTSelect), 
    .Jump(Jump), 
    .Jr(Jr),
    .GRF_WASrc(GRF_WASrc),
    .GRF_WDSrc(GRF_WDSrc),
    .ALUSelect(ALUSelect),
    .ByteLW(ByteLW)
    );  
	
	
endmodule
