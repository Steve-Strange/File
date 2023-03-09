`timescale 1ns / 1ps
module mips(
    input clk,
    input reset,

    output [31:0] i_inst_addr,
    input [31:0] i_inst_rdata,

    output [31:0] m_data_addr,
    input [31:0] m_data_rdata,
    output [31:0] m_data_wdata,
    output [3:0] m_data_byteen,

    output [31:0] m_inst_addr,

    output w_grf_we,
    output [4:0] w_grf_addr,
    output [31:0] w_grf_wdata,

    output [31:0] w_inst_addr
    );
    
    //PC,Ins
    wire [31:0] F_PC,D_PC,E_PC,M_PC,W_PC;
    wire [31:0] F_Ins,D_Ins,E_Ins,M_Ins,W_Ins;
	//Stall
    wire [1:0] Tuse_rs,Tuse_rt,E_Tnew,M_Tnew;
    wire F_Stall,D_Stall,D_Flush,E_Flush;


    //Forward_in
    wire [4:0] D_rs,D_rt,E_rs,E_rt,M_rt;
    wire [31:0] D_rs_data,D_rt_data,E_rs_data,E_rt_data,M_rt_data;
    wire [31:0] D_rs_fw,D_rt_fw,E_rs_fw,E_rt_fw,M_rt_fw;
    //Forward_out
    wire [4:0] E_GRF_WA,M_GRF_WA,W_GRF_WA;
    wire [31:0] E_GRF_WD,M_GRF_WD,W_GRF_WD;

    //branchTrue
    wire D_branch_true,E_branchTrue,M_branchTrue,W_branchTrue;

    //HI, LO
    wire [31:0] M_HI,W_HI,M_LO,W_LO;

    //NPC,EXTout,ALU_Y,DM_RD,MDU
    wire [31:0] NPC,E_EXT_out,M_ALU_Y,W_ALU_Y,W_DM_RD;
    wire MDU,MDUStart,MDUBusy;

    wire [31:0] M_DM_WD;
    wire [3:0] ByteEn;

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

    //IFU,DM
    assign i_inst_addr=F_PC;
    assign F_Ins=i_inst_rdata;

    assign m_data_addr=M_ALU_Y;   
    assign m_inst_addr=M_PC;

    assign w_grf_we=(W_GRF_WA!=0);
    
    assign w_grf_addr=W_GRF_WA;
    assign w_grf_wdata=W_GRF_WD;
    assign w_inst_addr=W_PC;

    assign m_data_wdata=(M_PC==32'h3000)?M_Ins:M_DM_WD;
    assign m_data_byteen=(M_PC==32'h3000)?4'b1111:ByteEn;
    

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
    
Fetch fetch (
    .clk(clk), 
    .reset(reset), 
    .F_Stall(F_Stall), 
    .D_Stall(D_Stall),
    .D_Flush(D_Flush),
    .NPC(NPC),
    .F_PC(F_PC), 
    .F_Ins(F_Ins), 
    .D_PC(D_PC),
    .D_Ins(D_Ins)
    );

Decode decode (
    .clk(clk), 
    .reset(reset), 
    .E_Flush(E_Flush), 
    .F_PC(F_PC), 
    .D_PC(D_PC), 
    .D_Ins(D_Ins), 
    .E_PC(E_PC), 
    .E_Ins(E_Ins), 
    .MDU(MDU),
    .Tuse_rs(Tuse_rs), 
    .Tuse_rt(Tuse_rt), 
    .D_rs(D_rs), 
    .D_rt(D_rt), 
    .D_rs_data(D_rs_data), 
    .D_rt_data(D_rt_data), 
    .D_rs_fw(D_rs_fw), 
    .D_rt_fw(D_rt_fw), 
    .E_rs_data(E_rs_data), 
    .E_rt_data(E_rt_data), 
    .E_EXT_out(E_EXT_out), 
    .NPC(NPC),
    .D_Flush(D_Flush),
    .E_branchTrue(E_branchTrue)
    );

Execute execute (
    .clk(clk), 
    .reset(reset), 
    .E_PC(E_PC), 
    .E_Ins(E_Ins), 
    .M_PC(M_PC), 
    .M_Ins(M_Ins), 
    .E_Tnew(E_Tnew), 
    .E_GRF_WA(E_GRF_WA), 
    .E_GRF_WD(E_GRF_WD), 
    .E_rs(E_rs), 
    .E_rt(E_rt), 
    .E_rs_data(E_rs_data), 
    .E_rt_data(E_rt_data), 
    .E_rs_fw(E_rs_fw), 
    .E_rt_fw(E_rt_fw),
    .MDUStart(MDUStart),
    .MDUBusy(MDUBusy),
    .M_rt_data(M_rt_data), 
    .E_EXT_out(E_EXT_out), 
    .M_ALU_Y(M_ALU_Y),
    .M_HI(M_HI),
    .M_LO(M_LO),
    .E_branchTrue(E_branchTrue),
    .M_branchTrue(M_branchTrue)
    );


Memory memory (
    .clk(clk), 
    .reset(reset), 
    .M_PC(M_PC), 
    .M_Ins(M_Ins), 
    .W_PC(W_PC),
    .W_Ins(W_Ins), 
    .M_Tnew(M_Tnew), 
    .M_GRF_WA(M_GRF_WA), 
    .M_GRF_WD(M_GRF_WD),
    .M_rt(M_rt), 
    .M_rt_fw(M_rt_fw),
    .M_DM_WD(M_DM_WD),         //输出写入DM的数据
    .ByteEn(ByteEn),         //输出字节写入使能
    .M_ALU_Y(M_ALU_Y),
    .M_DM_RDin(m_data_rdata),       //输入DM读出的数据
    .W_DM_RD(W_DM_RD),
    .W_ALU_Y(W_ALU_Y),
    
    .M_HI(M_HI),
    .M_LO(M_LO),
    .W_HI(W_HI),
    .W_LO(W_LO),
    .M_branchTrue(M_branchTrue),
    .W_branchTrue(W_branchTrue)
    );

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
    .W_branchTrue(W_branchTrue)
    );

Conflict conflict (
    .Tuse_rs(Tuse_rs), 
    .Tuse_rt(Tuse_rt),
    .MDU(MDU),
    .MDUStart(MDUStart),
    .MDUBusy(MDUBusy),
    .E_Tnew(E_Tnew), 
    .M_Tnew(M_Tnew), 
    .F_Stall(F_Stall), 
    .D_Stall(D_Stall), 
    .E_Flush(E_Flush), 
    .D_rs(D_rs), 
    .D_rt(D_rt), 
    .E_rs(E_rs), 
    .E_rt(E_rt), 
    .E_GRF_WA(E_GRF_WA), 
    .M_GRF_WA(M_GRF_WA), 
    .W_GRF_WA(W_GRF_WA)
    );
	
endmodule
