#pragma once

#include <iostream>
#include <string>
#include <cstring>

#include "Types.h"
#include "Connection.h"

namespace Cosmos {
  class Interpreter {
  public:
    Interpreter();
    std::string ParseCommand(int argc, char *argv[]);
    std::string ParseGet(std::string target);
    Cosmos::Connection GetTestSchema();
  };
}
