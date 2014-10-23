#include "Schema.h"

namespace Novo {
  Schema::Schema() {

  }

  Schema::Schema(Novo::DatabaseType dbType) {
    this->databaseType = dbType;
  }

  void Schema::SetDatabaseType(Novo::DatabaseType dbType) {
    this->databaseType = dbType;
  }

  Novo::DatabaseType Schema::GetDatabaseType() {
    return this->databaseType;
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

  std::string Schema::GetSchemaFileContent() {
    return this->schema_file_content;
  }

  void Schema::Load(std::string filename) {
    std::fstream file(filename, std::ios::in);
    if (file.is_open()) {
      this->schema_file_content.clear();
      std::string line;
      while (getline(file, line)) {
        this->schema_file_content.append(line);
        this->schema_file_content.append("\n");
      }
    }
    file.close();
  }
}
