`timescale 1ns / 1ps
`define IDLE 2'b00
`define LOAD 2'b01
`define CNT  2'b10
`define INT  2'b11

`define ctrl   mem[0]
`define preset mem[1]
`define count  mem[2]

module TC(
    input clk,
    input reset,
    input [31:2] Addr,
    input WE,
    input [31:0] Din,
    output [31:0] Dout,
    output IRQ
    );

	reg [1:0] state;
	reg [31:0] mem [2:0];		//ctrl, preset, count
	//ctrl[3]中断屏蔽（1允许中断），[2:1]模式选择，[0]计数器使能
	
	reg _IRQ;
	assign IRQ = `ctrl[3] & _IRQ;		//为0则与后为0，屏蔽中断
	
	assign Dout = mem[Addr[3:2]];		//？
	
	wire [31:0] load = Addr[3:2] == 0 ? {28'h0, Din[3:0]} : Din;		//？
	
	integer i;
	always @(posedge clk) begin
		if(reset) begin
			state <= 0; 
			for(i = 0; i < 3; i = i+1) mem[i] <= 0;
			_IRQ <= 0;
		end
		else if(WE) begin
			// $display("%d@: *%h <= %h", $time, {Addr, 2'b00}, load);
			mem[Addr[3:2]] <= load;
		end
		else begin
			case(state)
				`IDLE : if(`ctrl[0]) begin		//计数器使能为1则转至load状态
					state <= `LOAD;
					_IRQ <= 1'b0;	
				end
				`LOAD : begin					//加载初始值之后转至cnt状态
					`count <= `preset;
					state <= `CNT;
				end
				`CNT  : 						
					if(`ctrl[0]) begin			//计数器使能为1，倒计数
						if(`count > 1) `count <= `count-1;
						else begin				//==0之后产生一周期终端信号，状态变为interrupt
							`count <= 0;
							state <= `INT;
							_IRQ <= 1'b1;
						end
					end
					else state <= `IDLE;
				default : begin
					if(`ctrl[2:1] == 2'b00) `ctrl[0] <= 1'b0;	//模式0，计数到0时计数器使能变0
					else _IRQ <= 1'b0;							//模式1，计数为0时中断变0
					state <= `IDLE;								//并且回到IDLE，等待计数器使能变1
				end
			endcase
		end
	end

endmodule
