#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "DBObjects/Database.h"
#include "DBObjects/Table.h"
#include "Types.h"

#include <libpq-fe.h>

namespace Cosmos {
  enum class DatabaseType {
    POSTGRESQL,
    MSSQL
  };

  class Connection {
  public:
    Connection();
    bool connect(std::string);
    void disconnect();
    Cosmos::DBObjects::Database* get_database(std::string);
    void add_database(Cosmos::DBObjects::Database);
    void remove_database(std::string);
    std::string get_sql();
    std::string get_cosmos_file_content();
    void load(std::string);
    enum class DatabaseType;
    enum class DataType;

  private:
    PGconn* pg_conn;
    Cosmos::DatabaseType database_type;
    std::vector<Cosmos::DBObjects::Database> databases;
    std::string cosmos_file_content;
  };
}
