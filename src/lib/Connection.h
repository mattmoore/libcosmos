#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <ctime>

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
    void connect(std::string);
    void disconnect();
    bool is_connected();
    std::string server_time();
    std::vector<Cosmos::DBObjects::Database> get_databases();
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
    std::string cosmos_file_content;
  };
}
