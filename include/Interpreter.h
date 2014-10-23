#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>

#include "Types.h"
#include "Schema.h"

namespace Novo {
  class Interpreter {
  public:
    Interpreter();
    std::string ParseCommand(int argc, char *argv[]);
    std::string ParseGet(std::string target);
    Novo::Schema GetTestSchema();
  };
}

#endif
