#include "Connection.h"

namespace Cosmos {
  Connection::Connection() {

  }

  Connection::Connection(Cosmos::DatabaseType dbType) {
    this->databaseType = dbType;
  }

  void Connection::SetDatabaseType(Cosmos::DatabaseType dbType) {
    this->databaseType = dbType;
  }

  Cosmos::DatabaseType Connection::GetDatabaseType() {
    return this->databaseType;
  }

  Cosmos::DBObjects::Database* Connection::GetDatabase(std::string name) {
    Cosmos::DBObjects::Database* db_pointer;
    for (Cosmos::DBObjects::Database& database : this->databases) {
      if (database.GetName() == name) {
        db_pointer = &database;
      }
    }
    return db_pointer;
  }

  void Connection::AddDatabase(Cosmos::DBObjects::Database database) {
    this->databases.push_back(database);
  }

  void Connection::RemoveDatabase(std::string name) {
    for (uint i = 0; i < this->databases.size(); ++i) {
      if (this->databases[i].GetName() == name) {
        this->databases.erase(this->databases.begin() + i);
      }
    }
  }

  std::string Connection::GetSQL() {
    std::string sql;
    for (Cosmos::DBObjects::Database &database : this->databases) {
      sql += database.GetSQL();
    }
    return sql;
  }

  std::string Connection::GetCosmosFileContent() {
    return this->cosmos_file_content;
  }

  void Connection::Load(std::string filename) {
    std::fstream file(filename, std::ios::in);
    if (file.is_open()) {
      this->cosmos_file_content.clear();
      std::string line;
      while (getline(file, line)) {
        this->cosmos_file_content.append(line);
        this->cosmos_file_content.append("\n");
      }
    }
    file.close();
  }
}
