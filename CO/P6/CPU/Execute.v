`timescale 1ns / 1ps

module Execute(
    input clk,
    input reset,

    input [31:0] E_PC,
    input [31:0] E_Ins,
    output reg [31:0] M_PC,
    output reg [31:0] M_Ins,

    output [1:0] E_Tnew,        //AT算阻塞
    output [4:0] E_GRF_WA,      //写的寄存器
    output [31:0] E_GRF_WD,     //写的东西
    
    output [4:0] E_rs, E_rt,                    //读的寄存器
    output [31:0] E_rs_data,E_rt_data,          //寄存器原读数
    input [31:0] E_rs_fw,E_rt_fw,             //接收转发后结果

    output reg [31:0] M_rt_data,     //M级DM写入地址需要rt寄存器正确结果
    
    output MDU,
    output MDUStart,
    output MDUBusy,

    input E_branchTrue,
    input [31:0] E_EXT_out,
    output reg [31:0] M_ALU_Y,
    output reg M_branchTrue,
    output reg [31:0] M_HI,M_LO

    );

    //CU
    wire [3:0] ALUSelect;
    wire ALUSrc;
    wire [2:0] GRF_WDSrc;
    wire MDUStart;
    wire [2:0] MDUSelect;
    //ALU+MDU
    wire [31:0] A,B,E_ALU_Y;
    wire Busy;
    wire [31:0] E_HI,E_LO;

    assign E_GRF_WD=(GRF_WDSrc==3'b010)?E_PC+8:
                    32'bz;       //E级可转发出D级算的PC+8（根据当前指令写入地址判断）

    assign A=E_rs_fw;
    assign B=ALUSrc?E_EXT_out:E_rt_fw;

    always @(posedge clk) begin
        if(reset) begin
            M_PC<=0;
            M_Ins<=0;
            M_ALU_Y<=0;
            M_rt_data<=0;
            M_branchTrue<=0;
            M_HI<=0;
            M_LO<=0;
        end
        else begin
            M_PC<=E_PC;
            M_Ins<=E_Ins;
            M_ALU_Y<=E_ALU_Y;
            M_rt_data<=E_rt_fw;
            M_branchTrue<=E_branchTrue;
            M_HI<=E_HI;
            M_LO<=E_LO;
        end
    end

CU E_cu (
    .Ins(E_Ins),
    .branchTrue(E_branchTrue),
    .E_Tnew(E_Tnew),
    
    .rs(E_rs),
    .rt(E_rt),
    .GRF_WA(E_GRF_WA),
    .ALUSrc(ALUSrc),
    .ALUSelect(ALUSelect),
    .GRF_WDSrc(GRF_WDSrc),
    .MDU(MDU),
    .MDUStart(MDUStart),
    .MDUSelect(MDUSelect)
    );

E_ALU E_alu (
    .op(ALUSelect), 
    .A(A),
    .B(B), 
    .Y(E_ALU_Y)
    );

E_MDU E_mdu (
    .clk(clk), 
    .reset(reset), 
    .Start(MDUStart), 
    .MDUSelect(MDUSelect), 
    .A(A), 
    .B(B), 
    .Busy(MDUBusy), 
    .LO(E_LO), 
    .HI(E_HI)
    );


endmodule
