#include "vm.h"

//functions
VM::VM() {
  reg[PC]=0;
}

uint16_t VM::fetch() {
  return memory[reg[PC]++];
}

void VM::decode() {
}

void VM::execute() {
  
}

void VM::run() {
  uint16_t instruction = fetch();
  printf("%u",instruction);
}

void VM::load_program(std::vector<uint16_t> program) {
  for(uint16_t i = 0; i < program.size(); i++) {
    memory[i] = program[i];
  }
}

