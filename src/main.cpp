#include "main.h"

int main(int argc, char *argv[]) {

  // Test schema functionality.

  Novo::Schema schema(Novo::DatabaseType::MSSQL);

  Novo::Table table1("table1");
  table1.AddColumn(Novo::Column("col1", Novo::ColumnType::INT));
  table1.AddColumn(Novo::Column("col2", Novo::ColumnType::INT));
  table1.AddColumn(Novo::Column("col3", Novo::ColumnType::VARCHAR, 255));
  table1.SetPK("col1");
  Novo::ForeignKey fk1("fk_table1_col3_table2_col1");
  fk1.SetSourceColumn("col2");
  fk1.SetTargetTable("table2");
  fk1.SetTargetColumn("col1");
  table1.AddForeignKey(fk1);
  schema.AddTable(table1);

  Novo::Table table2("table2");
  table2.AddColumn(Novo::Column("col1", Novo::ColumnType::INT));
  schema.AddTable(table2);

  std::cout << schema.GetSQL();
  // End test schema functionality.

  return 0;
}
