#ifndef VM_h
#define VM_h

#include <iostream>
#include <array>
#include <vector>

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
  
  //Decoded instructions will be stored in these:  
  uint16_t destination_register;
  uint16_t source_register_1;
  uint16_t source_register_2;
  uint16_t immediate_value;

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
