#include "Interpreter.h"

namespace Cosmos {

  Interpreter::Interpreter() {

  }

  std::string Interpreter::ParseCommand(int argc, char *argv[]) {
    std::string response;

    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[1], "get") == 0) {
        if (strcmp(argv[2], "sql") == 0) {
          response = this->GetTestSchema().get_sql();
        } else if (strcmp(argv[2], "raw") == 0) {
          Connection connection;
          connection.load((std::string)argv[3]);
          response = connection.get_cosmos_file_content();
        }
      }
    }

    return response;
  }

  std::string Interpreter::ParseGet(std::string target) {
    Cosmos::Connection connection = this->GetTestSchema();
    std::string response;
    if (target == "sql") {
      response = connection.get_sql();
      return response;
    }
    response = "Target to get command not understood. Appropriate targets are 'sql'.\n";
    return response;
  }

  Cosmos::Connection Interpreter::GetTestSchema() {
    Cosmos::Connection connection;
    Cosmos::DBObjects::Database database1("database1");

    // Create table1
    Cosmos::DBObjects::Table table1("table1");
    table1.AddColumn(Cosmos::DBObjects::Column("col1", Cosmos::DBObjects::ColumnType::INT));
    table1.SetPK("col1"); // set primary key to col1
    table1.AddColumn(Cosmos::DBObjects::Column("col2", Cosmos::DBObjects::ColumnType::INT));
    table1.AddColumn(Cosmos::DBObjects::Column("col3", Cosmos::DBObjects::ColumnType::VARCHAR, 255));

    // Create table2
    Cosmos::DBObjects::Table table2("table2");
    table2.AddColumn(Cosmos::DBObjects::Column("col1", Cosmos::DBObjects::ColumnType::INT));
    table2.SetPK("col1"); // set primary key to col1

    // Assign foreign key mapping table1(col2) -> table2(col1)
    Cosmos::DBObjects::ForeignKey fk1("fk__col2__table2__col1");
    fk1.SetSourceColumn("col2");
    fk1.SetTargetTable("table2");
    fk1.SetTargetColumn("col1");
    table1.AddForeignKey(fk1);

    // Add tables to database
    database1.AddTable(table1);
    database1.AddTable(table2);

    // Add databases to schema
    // connection.add_database(database1);

    return connection;
  }

}
