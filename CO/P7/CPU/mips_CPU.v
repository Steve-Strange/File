`timescale 1ns / 1ps

module mips_CPU(
    input clk,
    input reset,

    output [31:0] i_inst_addr,
    input [31:0] i_inst_rdata,

    output [31:0] CPUAddr,
    input [31:0] CPURD,
    output [31:0] CPUWD,
    output [3:0] CPUbyteen,

    output [31:0] m_inst_addr,

    output w_grf_we,
    output [4:0] w_grf_addr,
    output [31:0] w_grf_wdata,

    output [31:0] w_inst_addr,

    input [5:0] HWInt,
    output [31:0] macroscopic_pc	    //宏观pc
    );

    //PC,Ins
    wire [31:0] temp_F_PC,F_PC,D_PC,E_PC,M_PC,W_PC;
    wire [31:0] F_Ins,D_Ins,E_Ins,M_Ins,W_Ins;
	//Stall
    wire [1:0] Tuse_rs,Tuse_rt,E_Tnew,M_Tnew;
    wire F_Stall,D_Stall,D_Flush,E_Flush,M_Flush,W_Flush;
    //MDU_Stall
    wire MDU,MDUStart,MDUBusy;

    //Forward_in
    wire [4:0] D_rs,D_rt,E_rs,E_rt,M_rt,E_rd,M_rd;
    wire [31:0] D_rs_data,D_rt_data,E_rs_data,E_rt_data,M_rt_data;
    wire [31:0] D_rs_fw,D_rt_fw,E_rs_fw,E_rt_fw,M_rt_fw;
    //Forward_out
    wire [4:0] E_GRF_WA,M_GRF_WA,W_GRF_WA;
    wire [31:0] E_GRF_WD,M_GRF_WD,W_GRF_WD;
    //Forward
    assign D_rs_fw= (D_rs==0)?0:
                    (E_GRF_WA==D_rs)?E_GRF_WD:
                    (M_GRF_WA==D_rs)?M_GRF_WD:
                    D_rs_data;
    assign D_rt_fw= (D_rt==0)?0:
                    (E_GRF_WA==D_rt)?E_GRF_WD:
                    (M_GRF_WA==D_rt)?M_GRF_WD:
                    D_rt_data;
                    
    assign E_rs_fw= (E_rs==0)?0:
                    (M_GRF_WA==E_rs)?M_GRF_WD:
                    (W_GRF_WA==E_rs)?W_GRF_WD:
                    E_rs_data;
    assign E_rt_fw= (E_rt==0)?0:
                    (M_GRF_WA==E_rt)?M_GRF_WD:
                    (W_GRF_WA==E_rt)?W_GRF_WD:
                    E_rt_data;

    assign M_rt_fw= (M_rt==0)?0:
                    (W_GRF_WA==M_rt)?W_GRF_WD:
                    M_rt_data;

    //Exc
    wire D_eret, E_eret, M_eret;        //各级是否为eret指令
    wire E_mtc0,M_mtc0;
    wire F_DS, D_DS, E_DS, M_DS;        //指令是否在DelaySlot
    wire [4:0] F_ExcCode, D_ExcCode, E_ExcCode, M_ExcCode;
    wire [4:0] temp_D_ExcCode, temp_E_ExcCode, temp_M_ExcCode;
    wire M_Exc_DMOv;
    // 各级可能发生的异常指示信息
    // wire F_Exc_AdEL, D_Exc_RI, D_Exc_Syscall, E_Exc_AriOv, E_Exc_DMOv, M_Exc_AdEL, M_Exc_AdES;
    // EPC
    wire [31:0] EPC,EBase;
    wire Req;

Conflict conflict (
    .Tuse_rs(Tuse_rs),
    .Tuse_rt(Tuse_rt),
    .MDU(MDU),
    .MDUStart(MDUStart),
    .MDUBusy(MDUBusy),
    .E_Tnew(E_Tnew), 
    .M_Tnew(M_Tnew), 
    .D_eret(D_eret),
    .E_mtc0(E_mtc0),
    .M_mtc0(M_mtc0),
    .D_rs(D_rs), 
    .D_rt(D_rt), 
    .E_rs(E_rs), 
    .E_rt(E_rt), 
    .E_rd(E_rd),
    .M_rd(M_rd),
    .E_GRF_WA(E_GRF_WA), 
    .M_GRF_WA(M_GRF_WA), 
    .F_Stall(F_Stall), 
    .D_Stall(D_Stall), 
    .E_Flush(E_Flush)
    );

    //branchTrue
    wire D_branchTrue,E_branchTrue,M_branchTrue,W_branchTrue;
    //HI, LO
    wire [31:0] M_HI,W_HI,M_LO,W_LO;
    //NPC,EXTout,ALU_Y,DM_RD,NPCSelect
    wire [31:0] NPC,E_EXT_out,M_ALU_Y,W_ALU_Y,W_DM_RD;
    wire [2:0] NPCSelect;

    //Fetch
Fetch fetch (
    .clk(clk), 
    .reset(reset), 
    .F_Stall(F_Stall), 
    .D_Stall(D_Stall),
    .D_Flush(D_Flush),

    .temp_F_PC(temp_F_PC), 
    .F_PC(F_PC), 
    .F_Ins(F_Ins), 
    .F_DS(F_DS), 
    .F_ExcCode(F_ExcCode),
    .D_PC(D_PC),
    .D_Ins(D_Ins),
    .D_DS(D_DS),
    .temp_D_ExcCode(temp_D_ExcCode),

    .NPC(NPC),
    .NPCSelect(NPCSelect),
    .Req(Req),
    .D_eret(D_eret),
    .EPC(EPC),
    .EBase(EBase)
    );

    assign F_PC=D_eret?EPC:temp_F_PC;
    assign i_inst_addr=F_PC;
    assign F_Ins=i_inst_rdata;
    assign F_DS=(NPCSelect!=0);      //如果不是PC+4，有跳转则F级指令在延迟槽

    //Decode
    GRF grf (
        .clk(clk),
        .reset(reset),
        .A1(D_rs),
        .A2(D_rt), 
        .RD1(D_rs_data),
        .RD2(D_rt_data),
        .WA(W_GRF_WA), 
        .WD(W_GRF_WD),
        .PC(W_PC)
        );
        
    Decode decode (
        .clk(clk), 
        .reset(reset), 
        .E_Flush(E_Flush),
        .D_Stall(D_Stall),  
        .Req(Req),
        .EPC(EPC),

        .F_PC(F_PC), 
        .D_PC(D_PC), 
        .D_Ins(D_Ins), 
        .D_DS(D_DS),
        .temp_D_ExcCode(temp_D_ExcCode),
        .D_ExcCode(D_ExcCode),
        .E_PC(E_PC), 
        .E_Ins(E_Ins), 
        .E_DS(E_DS),
        .temp_E_ExcCode(temp_E_ExcCode),

        .MDU(MDU),
        .Tuse_rs(Tuse_rs), 
        .Tuse_rt(Tuse_rt),

        .D_rs(D_rs), 
        .D_rt(D_rt), 
        .D_rs_fw(D_rs_fw), 
        .D_rt_fw(D_rt_fw), 
        .E_rs_data(E_rs_data), 
        .E_rt_data(E_rt_data), 
    
        .E_branchTrue(E_branchTrue),
        .E_EXT_out(E_EXT_out), 
        .NPCSelect(NPCSelect),
        .NPC(NPC),
        .D_Flush(D_Flush),
        .D_eret(D_eret),
        .EBase(EBase)
        );

    //Execute
Execute execute (
    .clk(clk), 
    .reset(reset), 
    .Req(Req),

    .E_PC(E_PC), 
    .E_Ins(E_Ins), 
    .E_DS(E_DS),
    .temp_E_ExcCode(temp_E_ExcCode),
    .E_ExcCode(E_ExcCode),
    .M_PC(M_PC), 
    .M_Ins(M_Ins), 
    .M_DS(M_DS),
    .temp_M_ExcCode(temp_M_ExcCode),
    .M_Exc_DMOv(M_Exc_DMOv),

    .E_Tnew(E_Tnew), 
    .E_GRF_WA(E_GRF_WA), 
    .E_GRF_WD(E_GRF_WD), 
    .E_rs(E_rs), 
    .E_rt(E_rt), 
    .E_rd(E_rd), 
    .E_rs_fw(E_rs_fw), 
    .E_rt_fw(E_rt_fw),
    .M_rt_data(M_rt_data), 

    .MDUStart(MDUStart),
    .MDUBusy(MDUBusy),
    .E_EXT_out(E_EXT_out), 
    .M_ALU_Y(M_ALU_Y),
    .M_HI(M_HI),
    .M_LO(M_LO),
    .E_branchTrue(E_branchTrue),
    .M_branchTrue(M_branchTrue),
    .E_eret(E_eret),
    .E_mtc0(E_mtc0),
    .EBase(EBase)
    );

    //Memory
    wire [31:0] M_CP0Out,W_CP0Out;
    wire M_CP0en;
    assign M_mtc0=M_CP0en;

Memory memory (
    .clk(clk), 
    .reset(reset),
    .Req(Req),

    .M_PC(M_PC), 
    .M_Ins(M_Ins), 
    .temp_M_ExcCode(temp_M_ExcCode),
    .M_Exc_DMOv(M_Exc_DMOv),
    .M_ExcCode(M_ExcCode),
    .W_PC(W_PC),
    .W_Ins(W_Ins), 

    .M_Tnew(M_Tnew), 
    .M_GRF_WA(M_GRF_WA), 
    .M_GRF_WD(M_GRF_WD),
    .M_rt(M_rt), 
    .M_rt_fw(M_rt_fw),
    .M_rd(M_rd),            //写入CP0的地址为rd

    .M_DM_WD(CPUWD),         //输出写入DM的数据
    .ByteEn(CPUbyteen),         //输出字节写入使能
    .M_ALU_Y(M_ALU_Y),
    .M_CP0Out(M_CP0Out),
    .M_DM_RDin(CPURD),       //输入DM读出的数据
    .W_DM_RD(W_DM_RD),
    .W_ALU_Y(W_ALU_Y),
    .W_CP0Out(W_CP0Out),
    
    .M_HI(M_HI),
    .M_LO(M_LO),
    .W_HI(W_HI),
    .W_LO(W_LO),
    .M_branchTrue(M_branchTrue),
    .W_branchTrue(W_branchTrue),
    .M_eret(M_eret),
    .M_CP0en(M_CP0en),
    .EBase(EBase)
    );

    assign macroscopic_pc = M_PC;
    assign CPUAddr=M_ALU_Y;
    assign m_inst_addr=M_PC;

    mips_CP0 CP0 (
        .clk(clk), 
        .reset(reset), 
        .en(M_CP0en), 
        .CP0Add(M_rd), 
        .CP0In(M_rt_fw), 
        .CP0Out(M_CP0Out), 
        .VPC(macroscopic_pc), 
        .BDIn(M_DS), 
        .EPCOUt(EPC), 
        .EXLClr(M_eret), 
        .ExcCodeIn(M_ExcCode), 
        .HWInt(HWInt), 
        .Req(Req),
        .EBase(EBase)
        );


    //Writeback

Writeback writeback (
    .clk(clk), 
    .reset(reset), 
    .W_Ins(W_Ins), 
    .W_PC(W_PC), 
    .W_GRF_WA(W_GRF_WA), 
    .W_ALU_Y(W_ALU_Y), 
    .W_DM_RD(W_DM_RD),
    .W_GRF_WD(W_GRF_WD),
    .W_HI(W_HI),
    .W_LO(W_LO),
    .W_CP0Out(W_CP0Out),
    .W_branchTrue(W_branchTrue)
    );

    assign w_grf_we=(|W_GRF_WA);
    
    assign w_grf_addr=W_GRF_WA;
    assign w_grf_wdata=W_GRF_WD;
    assign w_inst_addr=W_PC;

	
endmodule
