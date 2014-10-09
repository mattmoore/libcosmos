#include "main.h"

int main(int argc, char *argv[]) {
  Novo::Schema schema;
  schema.AddTable("table1");
  schema.AddTable("table2");
  std::cout << schema.GetSQL();
  return 0;
}
