`timescale 1ns / 1ps
//异常码
`define ExcNone    5'd0
`define ExcSyscall 5'd8
`define ExcRI      5'd10

module Decode(
    input clk,
    input reset,
    input E_Flush,
    input D_Stall,      //D级Stall的时候后续流水中的PC,DS与ExcCode要正常输出
    input Req,
    input [31:0] EPC,

    input [31:0] F_PC,  //算NPC
    input [31:0] D_PC,
    input [31:0] D_Ins,
    input D_DS,
    input [4:0] temp_D_ExcCode,
    output [4:0] D_ExcCode,
    output reg [31:0] E_PC,
    output reg [31:0] E_Ins,
    output reg E_DS,
    output reg [4:0] temp_E_ExcCode,
 
    output MDU,
    output [1:0] Tuse_rs,Tuse_rt,        //AT算阻塞

    output [4:0] D_rs, D_rt,                    //读的寄存器
    input [31:0] D_rs_fw,D_rt_fw,             //接收转发后结果
    output reg [31:0] E_rs_data, E_rt_data,     //E寄存器rsrt原读数输出

    output D_Flush,
    output D_branchTrue,
    output reg E_branchTrue,        //NPC, branch是否满足条件
    output reg [31:0] E_EXT_out,    //E_ALU
    output [31:0] NPC,              //F_IFU
    output [2:0] NPCSelect,
    output D_eret,
    input [31:0] EBase
    );

	//D_CU
    wire [5:0] opcode,funct;
    wire [15:0] imm16;
	wire [2:0] BranchSelect;
	wire EXTSelect;

	//EXT
	wire [31:0] D_EXT_out;
    assign D_EXT_out=EXTSelect?{16'b0,imm16}:               //0
                               {{16{imm16[15]}},imm16};     //Signed
	
	//NPC
    assign D_branchTrue=(BranchSelect==3'b000)?(D_rs_fw==D_rt_fw):    //beq
                        (BranchSelect==3'b001)?~(D_rs_fw==D_rt_fw):   //bne
                        (BranchSelect==3'b011)?($signed(D_rs_fw)<$signed(0)):   //bltzal
                        // (BranchSelect==3'b100)?($signed(D_rs_fw)>$signed(0)):   //其他指令
                        0;
    assign NPC= (Req)?EBase:         //Req跳转
                (D_eret)?EPC+4:             //EPC
                (NPCSelect == 3'b001&&D_branchTrue)?D_PC+4+{{14{D_Ins[15]}},D_Ins[15:0],2'b00}:   //branch(+8)
                (NPCSelect == 3'b010)?D_rs_fw:                              //jreg
                (NPCSelect == 3'b011)?{D_PC[31:28],D_Ins[25:0],2'b00}:      //jadd
                F_PC + 4;

    assign D_Flush=(BranchSelect==3'b011&&!D_branchTrue);       //清空延迟槽（新指令&&猜错了）
    
    //未知指令异常、syscall
    wire D_Exc_RI;
    wire D_Exc_syscall;
    assign D_ExcCode=temp_D_ExcCode?temp_D_ExcCode:
                     D_Exc_RI?`ExcRI:
                     D_Exc_syscall?`ExcSyscall:
                     `ExcNone;

    //DE
    always @(posedge clk) begin
        if(reset||E_Flush||Req||D_Stall) begin
            E_PC<=reset?0:
                  Req?EBase:
                  D_Stall?D_PC:
                  0;
            E_Ins<=0;
            E_rs_data<=0;
            E_rt_data<=0;
            E_EXT_out<=0;
            E_branchTrue<=0;
            E_DS<=reset?0:
                  D_Stall?D_DS:
                  0;
            temp_E_ExcCode<=reset?0:
                            D_Stall?D_ExcCode:
                            0;
        end
        else begin
            E_PC<=D_PC;
            E_Ins<=D_Ins;
            E_rs_data<=D_rs_fw;
            E_rt_data<=D_rt_fw;
            E_EXT_out<=D_EXT_out;
            E_branchTrue<=D_branchTrue;
            E_DS<=D_DS;
            temp_E_ExcCode<=D_ExcCode;
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
    .MDU(MDU),
    .BranchSelect(BranchSelect), 
    .EXTSelect(EXTSelect),
    .NPCSelect(NPCSelect),

    .eret(D_eret),
    .syscall(D_Exc_syscall),
    .D_Exc_RI(D_Exc_RI)
    );

endmodule
