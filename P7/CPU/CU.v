`timescale 1ns / 1ps

module CU(
    input [31:0] Ins,
    input branchTrue,           //branch通路要改

    // output RegWrite,
    output [4:0] GRF_WA,        //直接输出地址
    output [2:0] GRF_WDSrc,

    output EXTSelect,

    output ALUSrc,
    output [3:0] ALUSelect,
    output MDU,
    output MDUStart,
    output [2:0] MDUSelect,
    output [1:0] MFSelect,

    output MemWrite,

    output [2:0] BranchSelect,
    output [2:0] NPCSelect,
    output [1:0] ByteSelect,
    output [2:0] DESelect,

    output [5:0] opcode,funct,
    output [4:0] rs,rt,rd,
    output [4:0] shamt,
    output [15:0] imm16,
    output [25:0] imm26,

    output [1:0] Tuse_rs,
    output [1:0] Tuse_rt,
    output [1:0] E_Tnew,
    output [1:0] M_Tnew,

    output load,
    output save,

    output ALUDM,
    output ALUAri,
    
    output mfc0,
    output mtc0,
    output eret,                //跳出中断异常信号
    output syscall,
    // output CP0Write,
    output D_Exc_RI
    // output D_EXC_Syscall
    );
	
    wire R, add, sub, And, Or, Xor, slt, sltu;
    wire addi, andi, xori, ori, lui;
    wire lb, lh, lw, sb, sh, sw, lbu, lhu;
    wire mult, multu, div, divu, mfhi, mflo, mthi, mtlo, fdiv;
    wire beq, bne, j, jal, jr, bltzal, jap;
    wire nop;

    wire cal_r,cal_i,md,mt,mf,branch,branch_ucl,branch_cl,shift,jreg,jadd,jlink;

    //Ins
    assign {opcode,rs,rt,rd,shamt,funct}=Ins;
    assign imm16 = {rd,shamt,funct};
    assign imm26 = {rs,rt,rd,shamt,funct};

    assign R=(opcode==0);
    //cal_r
    assign add  =(R&&funct==6'b100000); 
    assign sub  =(R&&funct==6'b100010);
    assign And  =(R&&funct==6'b100100);
    assign Or   =(R&&funct==6'b100101);
    assign Xor  =(R&&funct==6'b100110);
    assign slt  =(R&&funct==6'b101010);
    assign sltu =(R&&funct==6'b101011);
    //cal_i
    assign addi =(opcode==6'b001000); 
    assign andi =(opcode==6'b001100); 
    assign xori =(opcode==6'b001110);
    assign ori  =(opcode==6'b001101); 
    assign lui  =(opcode==6'b001111);
    //load
    assign lb   =(opcode==6'b100000);
    assign lbu  =(opcode==6'b100100);
    assign lh   =(opcode==6'b100001);
    assign lhu  =(opcode==6'b100101);
    assign lw   =(opcode==6'b100011);  
    //save
    assign sw   =(opcode==6'b101011);  
    assign sh   =(opcode==6'b101001);
    assign sb   =(opcode==6'b101000);
    //m+d
    assign mult =(R&&funct==6'b011000);
    assign multu=(R&&funct==6'b011001);
    assign div  =(R&&funct==6'b011010);
    assign divu =(R&&funct==6'b011011);
    assign mfhi =(R&&funct==6'b010000);
    assign mflo =(R&&funct==6'b010010);
    assign mthi =(R&&funct==6'b010001);
    assign mtlo =(R&&funct==6'b010011);
    //b+j
    assign beq  =(opcode==6'b000100);
    assign bne  =(opcode==6'b000101);
    assign j    =(opcode==6'b000010);
    assign jal  =(opcode==6'b000011); 
    assign jr   =(R&&funct==6'b001000);
    assign bltzal=(opcode==6'b000001);
    //EXC
    assign mtc0 =((opcode==6'b010000)&&(rs==5'b00100));
    assign mfc0 =((opcode==6'b010000)&&(rs==5'b00000));
    assign eret =(Ins==32'b01000010000000000000000000011000);
    assign syscall=(R&&funct==6'b001100);
    //nop
    assign nop  =(Ins==0);

    assign jap  =0;
    assign fdiv =0;


    assign cal_r=(add||sub||And||Or||Xor||slt||sltu);
	assign cal_i=(addi||andi||xori||ori||lui);

    assign md   =(mult||multu||div||divu||fdiv);
    assign mf   =(mfhi||mflo);
    assign mt   =(mthi||mtlo);

	assign load=(lw||lh||lhu||lb||lbu);
	assign save=(sw||sh||sb);

    assign branch=(beq||bne||branch_ucl||branch_cl);
    assign branch_ucl=bltzal;
    assign branch_cl=0;

    assign jreg = jr;
    assign jadd = (j||jal||jap);
    assign jlink = jal;

    assign shift=0;

    assign ALUDM = (save | load);
    assign ALUAri = (add | addi | sub);
    // assign RegWrite=(cal_r||cal_i||jlink||shift||load);
    
    //EXT拓展选择
    assign EXTSelect=(andi||ori||xori);              //0:SignEXT,1:ZeroEXT
    //分支判断条件选择
    assign BranchSelect= (beq)?3'b000:                  //==
                         (bne)?3'b001:                  //!=
                         (bltzal)?3'b010:
                         3'b111;
    //NPC来源选择
    assign NPCSelect=(branch)?3'b001:               //PC+8+offset
                     (jreg)?3'b010:                 //GPR[rs]
                     (jadd)?3'b011:                 //imm26
                      3'b000;                       //PC+4
    //GRF写入地址
    assign GRF_WA=  (cal_r||shift||mf)?rd:
                    (cal_i||load||mfc0)?rt:
                    (jlink||branch_ucl||(branch_cl&&branchTrue))?5'd31:
                    5'b00000;     //不写，就写去0，注意link地址和前提条件：&&branchTrue
    //GRF写入数据来源
    assign GRF_WDSrc=(load)?3'b001:                  //DM_RD
                     (jlink||branch_ucl||(branch_cl&&branchTrue))?3'b010:    //PC+4 (PC+8)
                     (mfc0)?3'b011:                  //CP0Out
                     3'b000;                         //ALU_Y
    //内存写入使能
    assign MemWrite=(save);
    //ALU_A数据来源
    assign ALUSrc=(cal_i||load||save);                  //0:EXT,1:GRF_RD2
    //ALU功能选择
    assign ALUSelect= (sub)?4'b0001:                     //-
                      (ori||Or)?4'b0010:                 //|
                      (lui)?4'b0011:                     //{B[15:0],16'b0}
                      (Xor)?4'b0100:                     //^
                      (And||andi)?4'b0101:               //&
                      (slt)?4'b0110:                     //$signed(A)<$signed(B)
                      (sltu)?4'b0111:                    //A<B
                      4'b0000;                           //+
    //乘除指令  
    assign MDU=(md||mf||mt);
    //乘除开始运算
    assign MDUStart=(md);
    //乘除功能选择
    assign MDUSelect=(mult)?3'b000:
                     (multu)?3'b001:
                     (div)?3'b010:
                     (divu)?3'b011:
                     (mthi)?3'b100:
                     (mtlo)?3'b101:
                     3'b111;
    assign MFSelect=(mfhi)?2'b00:
                    (mflo)?2'b01:
                    2'b10;
    //读写数据类型选择
    assign ByteSelect=(lb||lbu||sb)?2'b00:               //byte
                      (lh||lhu||sh)?2'b01:               //half word
                      (lw||sw)?2'b10:               //word
                      2'b11;
    //字节拓展功能选择
    assign DESelect=(lb)?3'b001:                //字节符号拓展
                    (lbu)?3'b010:               //字节无符号拓展
                    (lh)?3'b011:                //半字符号拓展
                    (lhu)?3'b100:               //半字无符号拓展
                    3'b000;                     //无拓展


	assign Tuse_rs= (branch||jreg)?0:
				    (cal_r||cal_i||save||load||mt||md)?1:
					3;
	assign Tuse_rt= (branch)?0:
					(cal_r||md)?1:
					(save||mtc0)?2:
					3;
	assign E_Tnew=  (cal_r||cal_i||mf)?1:
					(load||mfc0)?2:
					0;
	assign M_Tnew=  (load||mfc0)?1:
					0;

    // assign CP0Write= mtc0;

    assign D_Exc_RI = !(add | sub | And | Or | slt | sltu |
                        lui | addi | andi | ori |
                        beq | bne | jal | jr |
                        lb | lh | lw | sb | sh | sw |
                        mult | multu | div | divu | mfhi | mflo | mthi | mtlo |
                        mtc0 | mfc0 | eret | syscall |
                        nop);
    // assign D_EXC_Syscall=syscall;

endmodule