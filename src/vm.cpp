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
    
    case 1 : { //LOAD

      //get immediate value (bits 7 to 0)
      uint16_t immediate_value = (reg[IR] & 0b0000000011111111); 
      
      //check if destination register (bits 11 to 8) is valid (must map to R0, R1 or R2)
      uint16_t destination_register = (reg[IR] & 0b0000111100000000) >> 8;
      if (destination_register == 0 || destination_register == 1 || destination_register == 2) {
        reg[destination_register] = immediate_value;
        std::cout << "LOAD " << immediate_value << " into " << "R" << destination_register << std::endl;
        std::cout << "Value now in R" << destination_register << ": " << reg[destination_register] << std::endl; 
      } 
      else {
        std::cout << "Invalid destination register" << std::endl;
        reg[OP] = 0; //halt the program
      }

      break;
    }
    
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


