#include "vm.h"

VM::VM() {
  //set program counter to start of program in memory
  reg[PC]=0;
  //set opcode register to -1, so no instruction is executed before fetching first instruction
  reg[OP]=-1;
}

void VM::fetch() {
  reg[IR]= memory[reg[PC]++];
}

void VM::decode() {
  //decode opcode, and store in opcode register
  reg[OP] = (reg[IR] & 0b1111000000000000) >> 12;
}

void VM::execute() {
  switch(reg[OP]) {
    case 0 :
      std::cout << "HALT" << std::endl;
      break;
    case 1 :
      std::cout << "LOAD" << std::endl;
      break;
    case 2 :
      std::cout << "ADD" << std::endl;
      break;
  }
}

void VM::run() {
  while(reg[OP] != 0) {
  	fetch();
  	decode();
  	execute();
  }
}

void VM::load_program(std::vector<uint16_t> program) {
  for(uint16_t i = 0; i < program.size(); i++) {
    memory[i] = program[i];
  }
}


