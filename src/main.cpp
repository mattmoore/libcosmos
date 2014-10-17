#include "main.h"

int main(int argc, char *argv[]) {

  Novo::Schema schema(Novo::DatabaseType::MSSQL);

  // Create table1
  Novo::DBObjects::Table table1("table1");
  table1.AddColumn(Novo::DBObjects::Column("col1", Novo::DBObjects::ColumnType::INT));
  table1.SetPK("col1"); // set primary key to col1
  table1.AddColumn(Novo::DBObjects::Column("col2", Novo::DBObjects::ColumnType::INT));
  table1.AddColumn(Novo::DBObjects::Column("col3", Novo::DBObjects::ColumnType::VARCHAR, 255));

  // Create table2
  Novo::DBObjects::Table table2("table2");
  table2.AddColumn(Novo::DBObjects::Column("col1", Novo::DBObjects::ColumnType::INT));
  table2.SetPK("col1"); // set primary key to col1

  // Assign foreign key mapping table1(col2) -> table2(col1)
  Novo::DBObjects::ForeignKey fk1("fk__col2__table2__col1");
  fk1.SetSourceColumn("col2");
  fk1.SetTargetTable("table2");
  fk1.SetTargetColumn("col1");
  table1.AddForeignKey(fk1);

  // Add tables to schema
  schema.AddTable(table1);
  schema.AddTable(table2);

  // Print SQL for schema
  std::cout << schema.GetSQL();

  return 0;
}
