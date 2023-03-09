`timescale 1ns / 1ps

module M_DE(

    input [1:0] lowAddr,        //DM地址低两位
    input [2:0] DESelect,       //Extend选择，000不拓展，001字节符号拓展，010字节无符号拓展
                                                    //  011半字符号拓展，100半字无符号拓展
    input [31:0] in,            //从外置DM传进的DM读出数据
    output [31:0] out           //拓展后的传出至M级GRF写入数据
    );

    wire [7:0] byte[3:0];
    wire [15:0] halfword[1:0];
    assign {byte[3],byte[2],byte[1],byte[0]}=in;    //拆出字节和半字
    assign {halfword[1],halfword[0]}=in;

    assign out= (DESelect==3'b000)?in:
                (DESelect==3'b001)?{{24{byte[lowAddr][7]}},byte[lowAddr]}:
                (DESelect==3'b010)?{24'b0,byte[lowAddr]}:
                (DESelect==3'b011)?{{16{halfword[lowAddr[1]][15]}},halfword[lowAddr[1]]}:
                (DESelect==3'b100)?{16'b0,halfword[lowAddr[1]]}:
                0;
    
endmodule
