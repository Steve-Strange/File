module id_fsm(
    input [7:0] char,
    input clk,
    output reg out
    );
    reg flag;

    initial begin
        out=0;
    end

    always@(posedge clk) begin
        if((char>="A" && char<="Z")||(char>=8'd65 && char<=8'd90)) begin
            flag<=1;
            out<=0;
        end
        else if((char>=8'd48 && char<=8'd57)) begin
            if(flag) out<=1;
            else out<=0;
        end
        else begin
            out<=0;
            flag<=0;
        end
    end

endmodule