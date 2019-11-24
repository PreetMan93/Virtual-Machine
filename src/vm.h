#ifndef VM_h
#define VM_h

#include <iostream>
#include <array>
#include <vector>

enum{
  R0,
  R1,
  R2,
  IM, //where immediate values will be stored
  PC, //program counter
  NUM_REGISTERS
};

class VM {

  std::array<uint16_t,UINT16_MAX> memory;
  std::array<uint16_t,NUM_REGISTERS> reg;
  
  private:
  uint16_t fetch();
  void decode();
  void execute();

  public:
  VM();
  void run();
  void load_program(std::vector<uint16_t> program);

};

#endif
