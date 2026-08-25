`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// ECE369 - Computer Architecture
//
// Student(s) Name and Last Name: 
//      Candice Liu (33%), Andrew Ghartey (33%), Barack Marwanga Asande (33%)
// 
// Module - Top_tb.v
// Description - Testbench for top level design of MIPS 5 stage pipeline
//
////////////////////////////////////////////////////////////////////////////////

module Top_tb();
    reg Clk, Rst;
    wire [31:0] PC_Out, RegWriteData;
    wire [31:0] bestRow, bestCol, sadVal;
    
    // cycle count
    reg [31:0] cycle_count;
    reg [31:0] inst_count;

    Top u0(
        .Clk(Clk), 
        .Rst(Rst), 
        .PC_Out(PC_Out), 
        .RegWriteData(RegWriteData),
        .bestRow(bestRow),
        .bestCol(bestCol),
        .sadVal(sadVal)
    );
    
    initial begin
        Clk <= 1'b0;
        forever #10 Clk <= ~Clk;
    end
    
    initial begin
        Rst <= 1'b1;
        cycle_count = 0;
        inst_count = 0;
        #20;
        Rst <= 1'b0;
    end
    
    always @(posedge Clk) begin
        if (!Rst) begin
            cycle_count = cycle_count + 1;
            
            if (u0.MEM_WB_RegWrite || u0.MEM_WB_MemToReg) begin
                inst_count = inst_count + 1;
            end
            
            if (cycle_count % 10000 == 0) begin
                $display("Cycle: %d, Instructions: %d, CPI: %.3f", 
                         cycle_count, inst_count, 
                         cycle_count / (inst_count * 1.0));
            end
            
            // end_program forever loop
            if (PC_Out == 32'h00000024) begin
                $display("Total Cycles:       %d", cycle_count);
                $display("Total Instructions: %d", inst_count);
                $display("CPI:                %.3f", cycle_count / (inst_count * 1.0));
            end

        end
    end
    
endmodule