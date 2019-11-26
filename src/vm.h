#ifndef VM_h
#define VM_h

#include <iostream>
#include <array>
#include <vector>

/* Instruction set architecture
 *   - each word is 16 bits wide
 *   - the first 4 bits = opcode
 *   - remaining 12 bits are used for operands 
 *
 * Opcodes
 *   - 0000 => HALT , which will stop the program execution
 *   - 0001 => LOAD , used to load immediate values into registers
 *   - 0010 => ADD , which will add two registers, and store the results in a third register
 *
 * Operands
 *   - LOAD => bits 11 to 8 = register , bits 7 to 0 = immediate value
 */

class VM {

  enum{
    R0,
    R1,
    R2,
    IR, //instruction register, where fetched instruction will be stored
    OP, //opcode register, where decoded opcode will be stored
    PC, //program counter
    NUM_REGISTERS
  };

  std::array<uint16_t,UINT16_MAX> memory;
  std::array<uint16_t,NUM_REGISTERS> reg;
  
  private:
  void fetch();
  void decode();
  void execute();

  public:
  VM();
  void run();
  void load_program(std::vector<uint16_t> program);

};

#endif
