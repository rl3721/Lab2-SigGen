module top #(
  parameter A_WIDTH = 8,
            D_WIDTH = 8
)(
  // interface signals
  input  wire             clk,      // clock 
  input  wire             rst,      // reset 
  input  wire             en,       // enable
  input  logic [D_WIDTH-1:0] incr,        // value to preload
  output logic [D_WIDTH-1:0]      dout       // count output
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
  .addr (address),
  .clk (clk),
  .dout(dout)
);

endmodule
