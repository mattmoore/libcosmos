#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "DBObjects/Database.h"
#include "DBObjects/Table.h"
#include "Types.h"

namespace Cosmos {
  enum class DatabaseType {
    POSTGRESQL,
    MSSQL
  };

  class Connection {
  public:
    Connection();
    Connection(Cosmos::DatabaseType dbType);

    void SetDatabaseType(Cosmos::DatabaseType dbType);
    Cosmos::DatabaseType GetDatabaseType();

    Cosmos::DBObjects::Database* GetDatabase(std::string name);

    void AddDatabase(Cosmos::DBObjects::Database database);
    void RemoveDatabase(std::string name);

    std::string GetSQL();
    std::string GetCosmosFileContent();
    void Load(std::string filename);

    enum class DatabaseType;
    enum class DataType;

  private:
    Cosmos::DatabaseType databaseType;
    std::vector<Cosmos::DBObjects::Database> databases;
    std::string cosmos_file_content;
  };
}
