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

  //decode destination register (ADD, AND (TODO) , NOT (TODO) all use same bits as destination_register)
  destination_register = (reg[IR] & 0b0000111100000000) >> 8;

  //decode the rest of the instruction specifically depending on operation being performed
  switch(reg[OP]) { 
    case 0 : //HALT
      break;
    
    case 1 : { //LOAD
      //get immediate value (bits 7 to 0)
      immediate_value = (reg[IR] & 0b0000000011111111); 
      break;
    }
    
    case 2 : { //ADD
      source_register_1 = (reg[IR] & 0b0000000011110000) >> 4;
      source_register_2 = (reg[IR] & 0b0000000000001111);
      break;
    }
  }
}

void VM::execute() {
  switch(reg[OP]) { 
    case 0 :
      std::cout << "HALT" << std::endl;
      break;
    
    case 1 : { //LOAD
      reg[destination_register] = immediate_value;
      std::cout << "LOAD " << immediate_value << " into " << "R" << destination_register << std::endl;
      break;
    }
    
    case 2 : { //ADD
      reg[destination_register] = reg[source_register_1] + reg[source_register_2];
      std::cout << "ADD " << "R" << source_register_1 << " + " << "R" << source_register_2 << " into " << "R" << destination_register << std::endl;
      std::cout << "R" << destination_register << " = " << reg[destination_register] << std::endl;
      break;
    }
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


