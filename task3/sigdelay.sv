module top #(
  parameter A_WIDTH = 8,
            D_WIDTH = 8
)(
  // interface signals
  input  wire  clk,      // clock 
  input  wire  rst,      // reset 
  input  wire  wren,       // write enable
  input  wire  rden,  //read enable
  input wire counter_en,
  input  logic [7:0] offset,
  input logic [D_WIDTH-1:0]      mic_signal,      // count output
  output logic [D_WIDTH-1:0]      delayed_signal
);

counter addrCounter (
  .clk (clk),
  .rst (rst),
  .en (counter_en),
  .count (address)
);

logic  [A_WIDTH-1:0] address; // interconnect wire

ram sigdelayRom (
  .clk(clk),
  .wr_en(wren),
  .rd_en(rden),
  .rd_addr (address - offset),
  .wr_addr (address),
  .din(mic_signal),
  .dout(delayed_signal)
);

endmodule
