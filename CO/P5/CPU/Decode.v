`timescale 1ns / 1ps

module Decode(
    input clk,
    input reset,
    input E_Flush,

    input [31:0] F_PC,      //算NPC
    input [31:0] D_PC,
    input [31:0] D_Ins,
    output reg [31:0] E_PC,
    output reg [31:0] E_Ins,
    output [1:0] Tuse_rs,Tuse_rt,        //AT算阻塞

    output [4:0] D_rs, D_rt,                    //读的寄存器
    output [31:0] D_rs_data,D_rt_data,          //寄存器原读数
    input [31:0] D_rs_fw,D_rt_fw,             //接收转发后结果
    output reg [31:0] E_rs_data, E_rt_data,     //E寄存器rsrt原读数输出

    output D_Flush,
    output D_branchTrue,
    output reg E_branchTrue,        //NPC, branch是否满足条件
    output reg [31:0] E_EXT_out,    //E_ALU
    output [31:0] NPC               //F_IFU
    );

	//D_CU
    wire [5:0] opcode,funct;
    wire [15:0] imm16;
	wire [2:0] BranchSelect;
	wire EXTSelect;
	wire [2:0] NPCSelect;

	//EXT
	wire [31:0] D_EXT_out;
    assign D_EXT_out=EXTSelect?{16'b0,imm16}:               //0
                               {{16{imm16[15]}},imm16};     //Signed
	
	//NPC
    wire D_branchTrue;
    assign D_branchTrue=(BranchSelect==3'b000)?(D_rs_fw==D_rt_fw):    //beq
                        (BranchSelect==3'b001)?~(D_rs_fw==D_rt_fw):   //bne
                        (BranchSelect==3'b010)?($signed(D_rs_fw)>$signed(0)):
                        (BranchSelect==3'b101)?($signed(D_rs_fw)<$signed(0)):
                        0;
    assign NPC= (NPCSelect == 3'b001&&D_branchTrue)?D_PC+4+{{14{D_Ins[15]}},D_Ins[15:0],2'b00}:   //branch(+8)
                (NPCSelect == 3'b010)?D_rs_fw:                              //jreg
                (NPCSelect == 3'b100)?{D_PC[31:28],D_Ins[25:0],2'b00}:      //jadd
                (NPCSelect == 3'b101&&D_branchTrue)?(F_PC+({{14{D_Ins[15]}},D_Ins[15:0],2'b00}<<(D_rt_fw[1:0]))):
                F_PC + 4;

    assign D_Flush=0;
    
    reg [31:0] target_offset;
    // always @(*) begin
    //     assign temp=D_rt_fw[1:0];
    //     for(i=0;i<temp;i=i+1) begin
    //         target_offset
    //     end
    // end

    //DE
    always @(posedge clk) begin
        if(reset||E_Flush) begin
            E_PC<=0;
            E_Ins<=0;
            E_rs_data<=0;
            E_rt_data<=0;
            E_EXT_out<=0;
            E_branchTrue<=0;
        end
        else begin
            E_PC<=D_PC;
            E_Ins<=D_Ins;
            E_rs_data<=D_rs_fw;
            E_rt_data<=D_rt_fw;
            E_EXT_out<=D_EXT_out;
            E_branchTrue<=D_branchTrue;
        end
    end
    

CU D_cu (
    .Ins(D_Ins),
    .branchTrue(D_branchTrue),
    .Tuse_rs(Tuse_rs), 
    .Tuse_rt(Tuse_rt),

    .rs(D_rs), 
    .rt(D_rt),
    .imm16(imm16),
    .BranchSelect(BranchSelect), 
    .EXTSelect(EXTSelect),
    
    .NPCSelect(NPCSelect)

    );

endmodule
