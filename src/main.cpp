#include "vm.h"

int main() {
  //create virtual machine
  VM virtual_machine;

  //write program
  std::vector<uint16_t> program{
    0b0001000100000001, //LOAD 1 into Register 1
    0b0001000000000010, //LOAD 2 into Register 0
    0b0010001000000001, //ADD contents of Register 1 and Register 0 into Register 2
    0b0000000000000000 //HALT program
  };

  //load program into VM memory and run the VM
  virtual_machine.load_program(program);
  virtual_machine.run();
  return 0;
}
