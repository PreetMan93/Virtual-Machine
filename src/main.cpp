#include "vm.h"

int main() {
  VM virtual_machine;
  std::vector<uint16_t> program{3,4,0x4001, 0x4000};
  virtual_machine.load_program(program);
  virtual_machine.run();
  return 0;
}
