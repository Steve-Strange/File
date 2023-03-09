`timescale 1ns / 1ps

module Conflict(
    input [1:0] Tuse_rs,
    input [1:0] Tuse_rt,
    input [1:0] E_Tnew,
    input [1:0] M_Tnew,
    input D_eret,
    input E_mtc0,
    input M_mtc0,    

    input MDU,
    input MDUStart,
    input MDUBusy,

    output F_Stall,
    output D_Stall,
    output E_Flush,
    //读寄存器口
    input [4:0] D_rs,
    input [4:0] D_rt,
    input [4:0] E_rs,
    input [4:0] E_rt,
    input [4:0] E_rd,
    input [4:0] M_rd,
    //写寄存器口
    input [4:0] E_GRF_WA,
    input [4:0] M_GRF_WA
    );
    
    reg Stall_rs,Stall_rt,Stall_MDU;      	//Stall
    always@(*)
    begin
        if((D_rs==E_GRF_WA)&&D_rs&&(Tuse_rs<E_Tnew)) Stall_rs=1;
        else if((D_rs==M_GRF_WA)&&D_rs&&(Tuse_rs<M_Tnew)) Stall_rs=1;
        else Stall_rs=0;

        if((D_rt==E_GRF_WA)&&D_rt&&(Tuse_rt<E_Tnew)) Stall_rt=1;
        else if((D_rt==M_GRF_WA)&&D_rt&&(Tuse_rt<M_Tnew)) Stall_rt=1;
        else Stall_rt=0;

        if((MDUBusy||MDUStart)&&MDU) Stall_MDU=1;
        else Stall_MDU=0;
    end
    //eret和mtc0的冲突，D级为eret时看之前有没有要动EPC的mtc0
    wire Stall_eret = D_eret && ((E_mtc0 & (E_rd == 5'd14)) || (M_mtc0 & (M_rd == 5'd14)));


    assign F_Stall=Stall_rs||Stall_rt||Stall_MDU||Stall_eret;
    assign D_Stall=Stall_rs||Stall_rt||Stall_MDU||Stall_eret;
    assign E_Flush=Stall_rs||Stall_rt||Stall_MDU||Stall_eret;

endmodule
