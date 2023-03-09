module test(
    input clk,
    output reg [10:0] x,
    output [10:0] y
);

always @(posedge clk) begin
    x<=x+1;
end

assign y=x;

endmodule