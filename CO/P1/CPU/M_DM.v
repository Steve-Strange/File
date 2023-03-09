`timescale 1ns / 1ps

module M_DM(
    input reset,
    input clk,
    input WE,
    input ByteLW,
    input [31:0] A,
    input [31:0] WD,
    output [31:0] RD,

    input [31:0] PC
    );

    integer i;
    reg [31:0] DM [4095:0];
    wire [11:0] address;
    wire [7:0] byte [3:0];
    wire [31:0] writeByte [4:0];

    assign address=A[13:2];
    assign {byte[3],byte[2],byte[1],byte[0]}=DM[address];
    assign RD=ByteLW?{24'b0,byte[A[1:0]]}:DM[address];
    assign writeByte[0]={byte[3],byte[2],byte[1],WD[7:0]};
    assign writeByte[1]={byte[3],byte[2],WD[7:0],byte[0]};
    assign writeByte[2]={byte[3],WD[7:0],byte[1],byte[0]};
    assign writeByte[3]={WD[7:0],byte[2],byte[1],byte[0]};

    always @(posedge clk) begin
        if(reset) for(i=0;i<4096;i=i+1) DM[i]<=0;
        else begin
            if(WE) begin
                DM[address]<=ByteLW?writeByte[A[1:0]]:WD;
                $display("@%h: *%h <= %h", PC, A, WD);
            end
        end
    end

endmodule