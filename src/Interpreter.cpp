#include "Interpreter.h"

namespace Novo {

  Interpreter::Interpreter() {

  }

  std::string Interpreter::ParseCommand(int argc, char *argv[]) {
    std::string response;

    if (argc >= 2) {
      // Get operations
      if (argv[1] == (std::string)"get") {
        if (argc >= 3) {
          // Return SQL from the schema object
          response = this->ParseGet(argv[2]);
          return response;
        } else {
          response = "You must specify a target to get.\n";
          return response;
        }
      }
    }

    response = "Your command was not understood.\n";
    return response;
  }

  std::string Interpreter::ParseGet(std::string target) {
    Novo::Schema schema = this->GetTestSchema();
    std::string response;
    if (target == "sql") {
      response = schema.GetSQL();
      return response;
    }
    response = "Target to get command not understood. Appropriate targets are 'sql'.\n";
    return response;
  }

  Novo::Schema Interpreter::GetTestSchema() {
    Novo::Schema schema(Novo::DatabaseType::MSSQL);
    Novo::DBObjects::Database database1("database1");

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

    // Add tables to database
    database1.AddTable(table1);
    database1.AddTable(table2);

    // Add databases to schema
    schema.AddDatabase(database1);

    return schema;
  }

}