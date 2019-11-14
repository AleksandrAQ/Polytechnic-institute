// Auto-generated test bench created by TestBencher Pro at Sat Jun 24 21:06:57 2000

`timescale 1ns / 1ps

module syncad_top;


wire [1:0] tb_status;
reg [1:0] tb_status_driver;
assign tb_status = tb_status_driver;
reg [2:0] command_code;
reg  clock;
reg [3:0] xdata;
reg [3:0] ydata;
wire [7:0] result;
wire  flagZ;
wire  flagO;
wire  flagN;

initial tb_status_driver = 1'b1; //diagram always running in auto-generated file

initial
  begin                  //SIGNAL command_code
        command_code = 3'h7;
      #127.000000                    // Abs Time: 127.000000
        command_code = 3'h2;
      #94.000000                    // Abs Time: 221.000000
        command_code = 3'h3;
      #98.000000                    // Abs Time: 319.000000
        ;
  end

initial
  begin                  //SIGNAL clock
        clock = 1'b0;
      #9.000000                    // Abs Time: 9.000000
        clock = 1'b1;
      #41.000000                    // Abs Time: 50.000000
        clock = 1'b0;
      #51.000000                    // Abs Time: 101.000000
        clock = 1'b1;
      #50.000000                    // Abs Time: 151.000000
        clock = 1'b0;
      #50.000000                    // Abs Time: 201.000000
        clock = 1'b1;
      #49.000000                    // Abs Time: 250.000000
        clock = 1'b0;
      #51.000000                    // Abs Time: 301.000000
        clock = 1'b1;
      #17.000000                    // Abs Time: 318.000000
        ;
  end

initial
  begin                  //SIGNAL xdata
        xdata = 4'h2;
      #87.000000                    // Abs Time: 87.000000
        xdata = 4'h9;
      #92.000000                    // Abs Time: 179.000000
        xdata = 4'h1;
      #92.000000                    // Abs Time: 271.000000
        xdata = 4'hf;
      #46.000000                    // Abs Time: 317.000000
        ;
  end

initial
  begin                  //SIGNAL ydata
        ydata = 4'h3;
      #86.000000                    // Abs Time: 86.000000
        ydata = 4'h4;
      #93.000000                    // Abs Time: 179.000000
        ydata = 4'h4;
      #52.000000                    // Abs Time: 231.000000
        ydata = 4'h2;
      #55.000000                    // Abs Time: 286.000000
        ydata = 4'h2;
      #31.000000                    // Abs Time: 317.000000
        ;
  end

ALU ALU(  .command_code ( command_code ),
  .clock ( clock ),
  .xdata ( xdata ),
  .ydata ( ydata ),
  .result ( result ),
  .flagZ ( flagZ ),
  .flagO ( flagO ),
  .flagN ( flagN ));

  initial
    begin
    end
endmodule

