`define s0 2'b00
`define s1 2'b01
`define s2 2'b10
`define s3 2'b11


module counting(
    input [1:0] num,
    input clk,
    output ans
    
    );
reg [1:0] status=2'b00;
always@(posedge clk)
begin
    if(status==`s0) begin
        if(num==1) status<=`s1;
        else status<=`s0;
    end // if(status==`s0)
    else if(status==`s1) begin
        if(num==2) status<=`s2;
        else if(num==1) status<=`s1;
        else status<=`s0;
    end
    else if(status==`s2) begin
        if(num==3) status<=`s3;
        else if(num==2) status<=`s2;
        else if(num==1) status<=`s1;
        else status<=`s0;
    end
    else if(status==`s3) begin
        if(num==3) status<=`s3;
        else if(num==1) status<=`s1;
        else status<=`s0;
    end
    else status<=`s0;
end

    assign ans = (status == `s3) ? 1'b1 : 1'b0;
endmodule // counting