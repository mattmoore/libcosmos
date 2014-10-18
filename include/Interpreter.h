#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include "Types.h"
#include <iostream>

namespace Novo {
  class Interpreter {
  public:
    Interpreter();
    void ParseCommand(int argc, char *argv[]);
    void ParseCommand(std::string command);
  };
}

#endif