`timescale 1ns / 1ps
module mips(
    input clk,
    input reset
    );
    
    //PC,Ins
    wire [31:0] F_PC,D_PC,E_PC,M_PC,W_PC;
    wire [31:0] D_Ins,E_Ins,M_Ins,W_Ins;
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

    //NPC,EXTout,ALU_Y,DM_RD
    wire [31:0] NPC,E_EXT_out,M_ALU_Y,W_ALU_Y,W_DM_RD;

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

    wire [31:0] a;
    wire [31:0] b;
    wire [31:0] c;

    // assign a=-1;
    // assign b=0;
    // assign c=($signed(a)>$signed(-2));
    // always@(*) begin
    //     $display("%d",c);
    // end
    

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
    .M_rt_data(M_rt_data), 
    .E_EXT_out(E_EXT_out), 
    .M_ALU_Y(M_ALU_Y),
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
    .M_rt_data(M_rt_data), 
    .M_rt_fw(M_rt_fw), 
    .M_ALU_Y(M_ALU_Y), 
    .W_DM_RD(W_DM_RD), 
    .W_ALU_Y(W_ALU_Y),
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
    .W_branchTrue(W_branchTrue)
    );

Conflict conflict (
    .Tuse_rs(Tuse_rs), 
    .Tuse_rt(Tuse_rt), 
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
