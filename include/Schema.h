#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <vector>
#include <fstream>

#include "DBObjects/Database.h"
#include "DBObjects/Table.h"
#include "Types.h"

namespace Novo {
  enum class DatabaseType {
    POSTGRESQL,
    MSSQL
  };

  class Schema {
  private:
    Novo::DatabaseType databaseType;
    std::vector<Novo::DBObjects::Database> databases;
    std::string schema_file_content;
    
  public:
    Schema();
    Schema(Novo::DatabaseType dbType);

    void SetDatabaseType(Novo::DatabaseType dbType);
    Novo::DatabaseType GetDatabaseType();

    Novo::DBObjects::Database* GetDatabase(std::string name);

    void AddDatabase(Novo::DBObjects::Database database);
    void RemoveDatabase(std::string name);

    std::string GetSQL();
    std::string GetSchemaFileContent();
    void Load(std::string filename);

    enum class DatabaseType;
    enum class DataType;
  };
}

#endif
