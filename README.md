# Virtual-Machine
A process virtual machine written in C++

#### Instruction set architecture
---
-Each word is 16 bits wide  
-Bits 15 to 12 are the opcode  
-Remaining 12 bits are used for operands  
  
#### Current Opcodes  
---  
0000 => HALT , stops program execution  
0001 => LOAD, loads immediate values into registers  
0010 => ADD, adds two registers together, and stores results in a third register  
0011 => AND (TODO), bitwise and's one register with another, and stores the results in a third register  
0100 => NOT (TODO), bitwise not's one register, and stores the results in a second register  
  
#### Current  Operands 
---
LOAD => bits 11 to 8 = destination register, bits 7 to 0 = immediate value  
ADD => bits 11 to 8 = destination register, bits 7 to 4 = source register 1, bits 3 to 0 = source register 2  
