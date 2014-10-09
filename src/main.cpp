#include "main.h"

int main(int argc, char *argv[]) {
  Novo::Schema schema;

  Novo::Table table1("table1");
  table1.AddColumn(Novo::Column("col1", Novo::ColumnType::VARCHAR, 255));
  schema.AddTable(table1);

  Novo::Table table2("table2");
  table2.AddColumn(Novo::Column("col1", Novo::ColumnType::INT));
  schema.AddTable(table2);

  std::cout << schema.GetSQL();
  return 0;
}
