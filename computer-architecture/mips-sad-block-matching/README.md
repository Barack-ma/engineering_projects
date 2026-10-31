# MIPS SAD Block Matching

Collaborative computer-architecture project implementing a block-matching algorithm in MIPS assembly using **Sum of Absolute Differences (SAD)**. The repository contains assembly programs, Verilog hardware modules, a testbench, memory initialization files, and an FPGA constraint file.

> **Contribution note:** This was a team project. The specific modules and responsibilities of each contributor have not yet been documented; do not interpret this repository as exclusively solo work.

## Project overview

The project explores block matching using SAD, including nested loops, memory addressing, register management, branching, and zig-zag search traversal. The existing project notes report FPGA validation using a **Digilent Nexys A7**.

## Source guide

| Files | Purpose |
| --- | --- |
| `vbsme_competition.s`, `vbsme_lab7.s` | MIPS assembly implementations |
| `ALU32Bit.v`, `RegisterFile.v`, `Controller.v` | Datapath and control building blocks |
| `ProgramCounter.v`, `PCAdder.v`, `InstructionMemory.v` | Instruction-fetch building blocks |
| `IF_ID_Reg.v`, `ID_EX_Reg.v`, `EX_MEM_Reg.v`, `MEM_WB_Reg.v` | Pipeline register modules |
| `DataMemory.v`, `data_memory.mem`, `instruction_memory.mem` | Data and instruction memory sources |
| `Top.v`, `Top_tb.v` | Top-level Verilog and testbench |
| `DisplayTop.v`, `SevenSegment.v`, `Two4DigitDisplay.v` | Display-related modules |
| `Two4DigitDisplay.xdc` | FPGA constraint file |

Additional utility modules include the clock divider, multiplexer and sign extension.

## Testing and reproduction

A Verilog testbench (`Top_tb.v`) and FPGA constraint file are included. Simulator commands, tool versions, expected waveforms, and a verified end-to-end setup procedure have **not yet been documented**. Reproduction requires confirming the relevant top-level module, simulator/synthesis configuration, and board pin mapping.

## Improvements to document

- Add a system block diagram and SAD search example
- Document individual team contributions
- Specify simulator/FPGA tool versions and exact build steps
- Attach representative waveforms, hardware photos, and test results, where permitted

## Academic context

This repository showcases collaborative coursework in computer architecture. Source is shared for portfolio and learning purposes; check any applicable course distribution restrictions before reuse.
