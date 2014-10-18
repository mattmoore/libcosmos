#include "Interpreter.h"

namespace Novo {

  Interpreter::Interpreter() {

  }

  void Interpreter::ParseCommand(int argc, char *argv[]) {
    std::string command;
    for (int i = 1; i < argc; i++) {
      command += argv[i];
      if (i < argc) {
        command += " ";
      }
    }
    this->ParseCommand(command);
  }

  void Interpreter::ParseCommand(std::string command) {
    
  }

}