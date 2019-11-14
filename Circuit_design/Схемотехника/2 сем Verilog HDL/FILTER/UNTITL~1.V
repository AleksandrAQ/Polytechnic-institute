// Auto-generated test bench created by TestBencher Pro at Sun Jun 25 22:30:02 2000

`timescale 1ns / 1ps

module syncad_top;


wire [1:0] tb_status;
reg [1:0] tb_status_driver;
assign tb_status = tb_status_driver;
reg  X;
reg  A;
reg  B;
wire  OutResult;

initial tb_status_driver = 1'b1; //diagram always running in auto-generated file

Filter Filter(  .X ( X ),
  .A ( A ),
  .B ( B ),
  .OutResult ( OutResult ));

  initial
    begin
    end
endmodule

