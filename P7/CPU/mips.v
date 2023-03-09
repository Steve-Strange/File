`timescale 1ns / 1ps
module mips(
    input clk,                    // 时钟信号
    input reset,                  // 同步复位信号
    input interrupt,              // 外部中断信号
    output [31:0] macroscopic_pc, // 宏观 PC

    output [31:0] i_inst_addr,    // IM 读取地址（取指 PC）
    input  [31:0] i_inst_rdata,   // IM 读取数据

    output [31:0] m_data_addr,    // DM 读写地址
    input  [31:0] m_data_rdata,   // DM 读取数据
    output [31:0] m_data_wdata,   // DM 待写入数据
    output [3 :0] m_data_byteen,  // DM 字节使能信号

    output [31:0] m_int_addr,     // 中断发生器待写入地址
    output [3 :0] m_int_byteen,   // 中断发生器字节使能信号

    output [31:0] m_inst_addr,    // M 级 PC

    output w_grf_we,              // GRF 写使能信号
    output [4 :0] w_grf_addr,     // GRF 待写入寄存器编号
    output [31:0] w_grf_wdata,    // GRF 待写入数据

    output [31:0] w_inst_addr     // W 级 PC
);

    wire TC1_IRQ;
    wire TC0_IRQ;
    wire [5:0] HWInt = {3'b0, interrupt, TC1_IRQ, TC0_IRQ};    //6口中断情况

    wire [31:0] CPUAddr,CPUWD,DMRD,CPURD;
    wire [3:0] CPUbyteen,temp_m_data_byteen;
 
    mips_CPU CPU (
        .clk(clk), 
        .reset(reset), 
        .HWInt(HWInt), 
        .macroscopic_pc(macroscopic_pc),

        .i_inst_addr(i_inst_addr), 
        .i_inst_rdata(i_inst_rdata), 

        .CPUAddr(CPUAddr), 
        .CPUWD(CPUWD), 
        .CPUbyteen(CPUbyteen), 

        .CPURD(CPURD), 
        .m_inst_addr(m_inst_addr), 

        .w_grf_we(w_grf_we), 
        .w_grf_addr(w_grf_addr), 
        .w_grf_wdata(w_grf_wdata), 
        
        .w_inst_addr(w_inst_addr)
        );

    wire [31:0] TC0_Dout,TC1_Dout;
    wire [31:0] DEV_WD,DEV_Addr;
    wire TC0Write,TC1Write;

    mips_bridge bridge (
        .CPUAddr(CPUAddr),
        .CPUWD(CPUWD),
        .CPUbyteen(CPUbyteen),

        .TC0Write(TC0Write), 
        .TC1Write(TC1Write), 
        .DEV_Addr(DEV_Addr), 
        .DEV_WD(DEV_WD), 
        .temp_m_data_byteen(temp_m_data_byteen),

        .DMRD(m_data_rdata), 
        .TC0RD(TC0_Dout), 
        .TC1RD(TC1_Dout), 
        .CPURD(CPURD)
        );

    assign m_data_addr = DEV_Addr;
    assign m_data_byteen = temp_m_data_byteen;
    assign m_data_wdata=DEV_WD;

	assign m_int_addr=CPUAddr;
	assign m_int_byteen=(CPUAddr>=32'h00007F20&&CPUAddr<=32'h00007F23)?CPUbyteen:0;


    TC TC0(
        .clk(clk),
        .reset(reset),
        .Addr(DEV_Addr[31:2]),
        .WE(TC0Write),
        .Din(DEV_WD),
        .Dout(TC0_Dout),
        .IRQ(TC0_IRQ)
    );

    TC TC1(
        .clk(clk),
        .reset(reset),
        .Addr(DEV_Addr[31:2]),
        .WE(TC1Write),
        .Din(DEV_WD),
        .Dout(TC1_Dout),
        .IRQ(TC1_IRQ)
    );    
    
endmodule