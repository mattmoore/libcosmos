#include "main.h"

int main(int argc, char *argv[]) {
  Cosmos::Interpreter interpreter;
  std::cout << interpreter.ParseCommand(argc, argv);
  Cosmos::Connection conn;
  conn.connect("postgresql://localhost");
  return 0;
}
