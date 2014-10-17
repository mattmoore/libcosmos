#include "main.h"

int main(int argc, char *argv[]) {

  Novo::Schema schema(Novo::DatabaseType::MSSQL);

  Novo::DBObjects::Table table1("table1");
  table1.AddColumn(Novo::DBObjects::Column("col1", Novo::DBObjects::ColumnType::INT));
  table1.AddColumn(Novo::DBObjects::Column("col2", Novo::DBObjects::ColumnType::INT));
  table1.AddColumn(Novo::DBObjects::Column("col3", Novo::DBObjects::ColumnType::VARCHAR, 255));
  table1.SetPK("col1");
  Novo::DBObjects::ForeignKey fk1("fk__col3__table2__col1");
  fk1.SetSourceColumn("col2");
  fk1.SetTargetTable("table2");
  fk1.SetTargetColumn("col1");
  table1.AddForeignKey(fk1);
  schema.AddTable(table1);

  Novo::DBObjects::Table table2("table2");
  table2.AddColumn(Novo::DBObjects::Column("col1", Novo::DBObjects::ColumnType::INT));
  schema.AddTable(table2);

  std::cout << schema.GetSQL();

  return 0;
}
