#include "Connection.h"

namespace Cosmos {
  Connection::Connection() {

  }

  void Connection::connect(std::string connection_string) {
    this->database_type = Cosmos::DatabaseType::POSTGRESQL;
    this->pg_conn = PQconnectdb(connection_string.c_str());
  }

  void Connection::disconnect() {
    PQfinish(this->pg_conn);
    this->pg_conn = NULL;
  }

  std::string Connection::server_time() {
    PGresult* result = PQexec(this->pg_conn, "select now()");
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
      PQfinish(this->pg_conn);
      exit(1);
    }
    std::string time_with_zone = PQgetvalue(result, 0, 0);
    return time_with_zone;
  }

  std::vector<Cosmos::DBObjects::Database> Connection::get_databases() {
    PGresult* result = PQexec(this->pg_conn, "select datname from pg_database");
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
      PQfinish(this->pg_conn);
      exit(1);
    }
    std::vector<Cosmos::DBObjects::Database> databases;
    return databases;
  }

  bool Connection::is_connected() {
    return PQstatus(this->pg_conn) == CONNECTION_OK;
  }

  std::string Connection::get_sql() {
    std::string sql;
    auto databases = get_databases();
    for (auto database : databases) {
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
