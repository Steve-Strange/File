`timescale 1ns / 1ps

module Writeback(
    input clk,
    input reset,
    input [31:0] W_Ins,
    input [31:0] W_PC,
    output [4:0] W_GRF_WA,

    input [31:0] W_ALU_Y,
    input [31:0] W_DM_RD,
    input W_branchTrue,
    output [31:0] W_GRF_WD
    );

    wire [2:0] GRF_WDSrc;

    assign W_GRF_WD=(GRF_WDSrc==3'b000)?W_ALU_Y:
                    (GRF_WDSrc==3'b001)?W_DM_RD:
                    (GRF_WDSrc==3'b010)?W_PC+8:
                    32'bz;                 //W级可转发出D级算的PC+8，E级算的的ALU_Y和M级读出的DM数据

    // always@(*) begin
    //     $monitor(W_branchTrue);
    // end
    
CU W_cu (
    .Ins(W_Ins),
    .branchTrue(W_branchTrue),
    .GRF_WA(W_GRF_WA),
    .GRF_WDSrc(GRF_WDSrc)
    );

endmodule
