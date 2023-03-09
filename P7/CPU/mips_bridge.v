`timescale 1ns / 1ps

module mips_bridge(
    input [31:0] CPUAddr,               //CPU读写地址
    input [31:0] CPUWD,                 //CPU往外设写数据
    input [3:0] CPUbyteen,              //按位读写使能

    output TC0Write,                    //写TC0
    output TC1Write,                    //写TC1
    output [31:0] DEV_Addr,             //往外设写入的地址
    output [31:0] DEV_WD,               //往外设写入的数据
    output [3:0] temp_m_data_byteen,    //传给DM的按位读写使能（读写其他外设时置为0）

    input [31:0] DMRD,                  //三个外设写入CPU的数据
    input [31:0] TC0RD,
    input [31:0] TC1RD,
    output [31:0] CPURD                 //最后决定写入CPU的数据
    );

    wire TC0,TC1,WE;

    assign WE=(CPUbyteen!=0);
    assign TC0=(CPUAddr>=32'h0000_7F00)&&(CPUAddr<=32'h0000_7F0B);
    assign TC1=(CPUAddr>=32'h0000_7F10)&&(CPUAddr<=32'h0000_7F1B);

    assign TC0Write = WE && TC0;
    assign TC1Write = WE && TC1;

    assign DEV_Addr=CPUAddr;   
    assign DEV_WD=CPUWD;

    assign temp_m_data_byteen = (TC0||TC1) ? 4'd0 : CPUbyteen;
    assign CPURD = (TC0) ? TC0RD :
                   (TC1) ? TC1RD :
                   DMRD;

endmodule