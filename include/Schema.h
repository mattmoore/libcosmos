#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <vector>
#include "DBObjects/Database.h"
#include "DBObjects/Table.h"

namespace Novo {
  enum class DatabaseType {
    POSTGRESQL,
    MSSQL
  };

  class Schema {
  private:
    Novo::DatabaseType databaseType;
    std::vector<Novo::DBObjects::Database> databases;
    std::vector<Novo::DBObjects::Table> tables;
    
  public:
    Schema(Novo::DatabaseType dbType);

    Novo::DBObjects::Database* GetDatabase(std::string name);

    void AddDatabase(Novo::DBObjects::Database database);
    void RemoveDatabase(std::string name);

    std::string GetSQL();

    enum class DatabaseType;
    enum class DataType;
  };
}

#endif

