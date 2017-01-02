#include "Connection.h"

namespace Cosmos {
  Connection::Connection() {

  }

  bool Connection::connect(std::string connection_string) {
    this->database_type = Cosmos::DatabaseType::POSTGRESQL;
    PGconn* pg_conn = NULL;
    pg_conn = PQconnectdb(connection_string.c_str());
    PQfinish(pg_conn);
    pg_conn = NULL;
    return true;
  }

  Cosmos::DBObjects::Database* Connection::get_database(std::string name) {
    Cosmos::DBObjects::Database* db_pointer;
    for (Cosmos::DBObjects::Database& database : this->databases) {
      if (database.GetName() == name) {
        db_pointer = &database;
      }
    }
    return db_pointer;
  }

  void Connection::add_database(Cosmos::DBObjects::Database database) {
    this->databases.push_back(database);
  }

  void Connection::remove_database(std::string name) {
    for (uint i = 0; i < this->databases.size(); ++i) {
      if (this->databases[i].GetName() == name) {
        this->databases.erase(this->databases.begin() + i);
      }
    }
  }

  std::string Connection::get_sql() {
    std::string sql;
    for (Cosmos::DBObjects::Database &database : this->databases) {
      sql += database.GetSQL();
    }
    return sql;
  }

  std::string Connection::get_cosmos_file_content() {
    return this->cosmos_file_content;
  }

  void Connection::load(std::string filename) {
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
