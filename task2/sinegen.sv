module top #(
  parameter A_WIDTH = 8,
            D_WIDTH = 8
)(
  // interface signals
  input  wire             clk,      // clock 
  input  wire             rst,      // reset 
  input  wire             en,       // enable
  input  logic [7:0] offset,
  input  logic [D_WIDTH-1:0] incr,        // value to preload
  output logic [D_WIDTH-1:0]      dout1,      // count output
  output logic [D_WIDTH-1:0]      dout2
);

  

counter addrCounter (
  .clk (clk),
  .rst (rst),
  .en (en),
  .incr(incr),
  .count (address)
);

logic  [A_WIDTH-1:0] address; // interconnect wire

rom sineRom (
  .addr1 (address),
  .addr2 (address + offset),
  .clk (clk),
  .dout1(dout1),
  .dout2(dout2)
);

endmodule
