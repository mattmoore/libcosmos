#include "main.h"

int main(int argc, char *argv[]) {
  Cosmos::Interpreter interpreter;
  std::cout << interpreter.ParseCommand(argc, argv);
  return 0;
}
