`timescale 1ns / 1ps
module EX_MEM_Reg(
    input Clk, Rst,
    input RegWrite_In, MemToReg_In,
    input MemRead_In, MemWrite_In,
    input Link_In,
    input [1:0] MemSize_In,
    input [31:0] ALUResult_In, ReadData2_In,
    input [31:0] BranchAddr_In,
    input [4:0] WriteReg_In,
     
    output reg RegWrite_Out, MemToReg_Out,
    output reg MemRead_Out, MemWrite_Out,
    output reg Link_Out,
    output reg [1:0] MemSize_Out,
    output reg [31:0] ALUResult_Out, ReadData2_Out,
    output reg [31:0] BranchAddr_Out,
    output reg [4:0] EX_MEM_Rd_Out
);
    
    always @(posedge Clk) begin
        if (Rst) begin
            RegWrite_Out <= 1'b0;
            MemToReg_Out <= 1'b0;
            MemRead_Out <= 1'b0;
            MemWrite_Out <= 1'b0;
            Link_Out <= 1'b0;
            MemSize_Out <= 2'b0;
            ALUResult_Out <= 32'b0;
            ReadData2_Out <= 32'b0;
            BranchAddr_Out <= 32'b0;
            EX_MEM_Rd_Out <= 5'b0;
        end
        else begin
            RegWrite_Out <= RegWrite_In;
            MemToReg_Out <= MemToReg_In;
            MemRead_Out <= MemRead_In;
            MemWrite_Out <= MemWrite_In;
            Link_Out <= Link_In;
            MemSize_Out <= MemSize_In;
            ALUResult_Out <= ALUResult_In;
            ReadData2_Out <= ReadData2_In;
            BranchAddr_Out <= BranchAddr_In;
            EX_MEM_Rd_Out <= WriteReg_In;
        end
    end
endmodule