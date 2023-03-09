`timescale 1ns / 1ps
module E_MDU(
    input clk,
    input reset,
    
    input Req,
    input Start,                    //开始运算
    input [2:0] MDUSelect,          //功能选择
    input [31:0] A,
    input [31:0] B,
    output reg Busy,                //正在运算
    output reg [31:0] LO,
    output reg [31:0] HI
    );

    reg [3:0] cnt=0;

    //mthi mtlo上升沿直接写入
    always @(posedge clk) begin
        if((MDUSelect == 3'b100)&&(!Req)) HI <= A;
        if((MDUSelect == 3'b101)&&(!Req)) LO <= A; 
    end

    always @(posedge clk) begin
        if(reset) begin
            LO<=0;
            HI<=0;
            Busy<=0;
            cnt<=0;
        end else if(!Req) begin         //中断时乘除法不能执行
            if(cnt==0) begin
                if(Start) begin
                    Busy<=1;
                    if(MDUSelect==3'b000) begin
                        cnt<=5;
                        {HI,LO}<=$signed(A)*$signed(B);
                    end
                    else if(MDUSelect==3'b001)begin
                        cnt<=5;
                        {HI,LO}<=A*B;
                    end
                    else if(MDUSelect==3'b010) begin
                        cnt<=10;
                        if(B!=0) begin
                            LO<=$signed(A)/$signed(B);
                            HI<=$signed(A)%$signed(B);                            
                        end
                    end
                    else if(MDUSelect==3'b011) begin
                        cnt<=10;
                        if(B!=0) begin
                            LO<=A/B;
                            HI<=A%B;
                        end
                    end
                    else cnt<=0;        //注意添加MDUSelect时100，101已经被用了
                end
            end
            else if(cnt==1) begin
                Busy<=0;
                cnt<=0;
            end
            else begin
                Busy<=1;
                cnt<=cnt-1;
            end
        end
    end

endmodule
