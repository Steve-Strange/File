`timescale 1ns / 1ps

module Conflict(
    input [1:0] Tuse_rs,
    input [1:0] Tuse_rt,
    input [1:0] E_Tnew,
    input [1:0] M_Tnew,

    output F_Stall,
    output D_Stall,
    output E_Flush,
    //读寄存器口
    input [4:0] D_rs,
    input [4:0] D_rt,
    input [4:0] E_rs,
    input [4:0] E_rt,
    //写寄存器口
    input [4:0] E_GRF_WA,
    input [4:0] M_GRF_WA,
    input [4:0] W_GRF_WA
    );
    
    reg Stall_rs,Stall_rt;      	//Stall
    always@(*)
    begin
        if((D_rs==E_GRF_WA)&&D_rs&&(Tuse_rs<E_Tnew)) Stall_rs=1;
        else if((D_rs==M_GRF_WA)&&D_rs&&(Tuse_rs<M_Tnew)) Stall_rs=1;
        else Stall_rs=0;    
    end
    always@(*)
    begin
        if((D_rt==E_GRF_WA)&&D_rt&&(Tuse_rt<E_Tnew)) Stall_rt=1;
        else if((D_rt==M_GRF_WA)&&D_rt&&(Tuse_rt<M_Tnew)) Stall_rt=1;
        else Stall_rt=0; 
    end
    assign F_Stall=Stall_rs|Stall_rt;
    assign D_Stall=Stall_rs|Stall_rt;
    assign E_Flush=Stall_rs|Stall_rt;

//   always@(*)
//   begin
//     $monitor("%d %d %d",E_GRF_WA,M_GRF_WA,W_GRF_WA);
//   end

endmodule
