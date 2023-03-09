module cpu_checker(
        input clk,
        input reset,
        input [15:0] freq,
        input [7:0] char,
        output reg [1:0] format_type,
        output reg [3:0] error_code
    );
    integer state=0;
    integer cnt1=0;
    integer cnt2=0;
    integer flag=0;
    reg [31:0] pc,addr, grf,time1;
    initial begin
        format_type=0;
        error_code=0;
        pc=0;
        addr=0;
        grf=0;
        time1=0;
    end
    always@(posedge clk) begin
        format_type=0;
        flag=0;
        if(reset) begin
            state=0;
            cnt1=0;
            format_type=0;
            error_code=0;
            pc=0;
            addr=0;
            grf=0;
            time1=0;
        end
        else begin
            if(state==0) begin
                cnt1=0;
                format_type=0;
                error_code=0;
                pc=0;
                addr=0;
                grf=0;
                time1=0;
                if(char=="^") state<=1;
                else state<=0;
            end
            else if(state==1) begin
                if(char>="0"&&char<="9") begin
                        state<=2;
                        time1=time1*10+char-"0";
                    end
                else state<=0;
            end
            else if(state==2) begin
                if(char>="0"&&char<="9") begin
                        cnt1=cnt1+1;
                        time1=time1*10+char-"0";
                        if(cnt1>3) begin
                            cnt1=0;
                            state<=0;
                        end
                        else state<=2;
                    end
                else if(char=="@") begin
                    state<=3;
                    cnt1=0;
                end
                else state<=0;
            end
            else if(state==3) begin
                if((char>="0"&&char<="9")||(char>="a"&&char<="f")) begin
                    if(char>="0"&&char<="9") pc=pc*16+char-"0";
                    else pc=pc*16+char-"a"+10;
                    cnt1=cnt1+1;
                    if(cnt1<8) begin
                        state<=3;
                    end
                    else begin
                        cnt1=0;
                        state<=4;
                    end
                end
                else state<=0;
            end
            else if(state==4) begin
                if(char==":") state<=5;
                else state<=0;
            end
            else if(state==5) begin
                if(char==" ") state<=5;
                else if(char=="$") state<=6;
                else if(char==8'd42) state<=12;
                else state<=0;
            end
            else if(state==6) begin
                if(char>="0"&&char<="9") begin
                    state<=7;
                    grf=grf*10+char-"0";
                end
                else state<=0;
            end
            else if(state==7) begin
                if(char>="0"&&char<="9") begin
                    if(flag==0) begin
                        grf=grf*10+char-"0";
                        cnt1=cnt1+1;
                        if(cnt1>3) begin
                            cnt1=0;
                            state<=0;
                        end
                    else state<=7;
                    end
                    else state<=0;
                end
                else if(char==" ") begin
                    state<=7;
                    flag=1;
                    cnt1=0;
                end
                else if(char=="<") begin
                    state<=8;
                    cnt1=0;
                end
                else state<=0;
            end            
            else if(state==8) begin
                if(char=="=") state<=9;
                else state<=0;
            end
            else if(state==9) begin
                if(char==" ") state<=9;
                else if((char>="0"&&char<="9")||(char>="a"&&char<="f")) state<=10;
                else state<=0;
            end
            else if(state==10) begin
                if((char>="0"&&char<="9")||(char>="a"&&char<="f")) begin
                    cnt1=cnt1+1;
                    if(cnt1==7) begin
                        state<=11;
                        cnt1=0;
                    end
                    else state<=10;
                end
                else state<=0;
            end
            else if(state==11) begin
                if(char=="#") begin
                    format_type<=1;
                    state<=0;
                end
                else state<=0;
            end
            else if(state==12) begin
                if((char>="0"&&char<="9")||(char>="a"&&char<="f")) begin
                    if(char>="0"&&char<="9") addr=addr*16+char-"0";
                    else addr=addr*16+char-"a"+10;
                    cnt1=cnt1+1;
                    if(cnt1==8) begin
                        cnt1=0;
                        state<=13;
                    end
                    else state<=12;
                end
                else state<=0; 
            end
            else if(state==13) begin
                if(char==" ") state<=13;
                else if(char=="<") state<=14;
                else state<=0;                
            end
            else if(state==14) begin
                if(char=="=") state<=15;
                else state<=0;
            end
            else if(state==15) begin
                if(char==" ") state<=15;
                else if((char>="0"&&char<="9")||(char>="a"&&char<="f")) state<=16;
                else state<=0;
            end
            else if(state==16) begin
                if((char>="0"&&char<="9")||(char>="a"&&char<="f")) begin
                    cnt1=cnt1+1;
                    if(cnt1==7) begin
                        state<=17;
                        cnt1=0;
                    end
                    else state<=16;
                end
                else state<=0;
            end
            else if(state==17) begin
                if(char=="#") begin
                    format_type<=2;
                    state<=0;
                end
                else state<=0;
            end

            if(format_type==1) begin
                
            end
        end
    end
endmodule