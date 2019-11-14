// Auto-generated test bench created by TestBencher Pro at Sun Jun 25 22:08:21 2000

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

initial
  begin                  //SIGNAL X
        X = 1'b0;
      #129.000000                    // Abs Time: 129.000000
        X = 1'b1;
      #6.000000                    // Abs Time: 135.000000
        X = 1'b0;
      #63.000000                    // Abs Time: 198.000000
        ;
  end

initial
  begin                  //SIGNAL A
        A = 1'b0;
      #39.000000                    // Abs Time: 39.000000
        A = 1'b1;
      #41.000000                    // Abs Time: 80.000000
        A = 1'b0;
      #40.000000                    // Abs Time: 120.000000
        A = 1'b1;
      #40.000000                    // Abs Time: 160.000000
        A = 1'b0;
      #40.000000                    // Abs Time: 200.000000
        ;
  end

initial
  begin                  //SIGNAL B
        B = 1'b1;
      #38.000000                    // Abs Time: 38.000000
        B = 1'b0;
      #42.000000                    // Abs Time: 80.000000
        B = 1'b1;
      #40.000000                    // Abs Time: 120.000000
        B = 1'b0;
      #43.000000                    // Abs Time: 163.000000
        B = 1'b1;
      #37.000000                    // Abs Time: 200.000000
        ;
  end

Filter Filter(  .X ( X ),
  .A ( A ),
  .B ( B ),
  .OutResult ( OutResult ));

  initial
    begin
    end
endmodule

