#include "Schema.h"

namespace Novo {
  Schema::Schema(Novo::DatabaseType dbType) {
    this->databaseType = dbType;
  }

  Novo::DBObjects::Database* Schema::GetDatabase(std::string name) {
    Novo::DBObjects::Database* db_pointer;
    for (Novo::DBObjects::Database& database : this->databases) {
      if (database.GetName() == name) {
        db_pointer = &database;
      }
    }
    return db_pointer;
  }

  void Schema::AddDatabase(Novo::DBObjects::Database database) {
    this->databases.push_back(database);
  }

  void Schema::RemoveDatabase(std::string name) {
    for (uint i = 0; i < this->databases.size(); ++i) {
      if (this->databases[i].GetName() == name) {
        this->databases.erase(this->databases.begin() + i);
      }
    }
  }

  std::string Schema::GetSQL() {
    std::string sql;
    for (Novo::DBObjects::Database &database : this->databases) {
      sql += database.GetSQL();
    }
    return sql;
  }
}

