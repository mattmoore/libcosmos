#include "Schema.h"

namespace Novo {
  Schema::Schema(Novo::DatabaseType dbType) {
    this->databaseType = dbType;
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

  void Schema::AddTable(Novo::DBObjects::Table table) {
    this->tables.push_back(table);
  }

  void Schema::RemoveTable(std::string name) {
    for (uint i = 0; i < this->tables.size(); ++i) {
      if (this->tables[i].GetName() == name) {
        this->tables.erase(this->tables.begin() + i);
      }
    }
  }

  std::string Schema::GetSQL() {
    std::string sql;
    std::string fkey_sql;

    for (Novo::DBObjects::Table &table : this->tables) {
      sql += table.GetSQL();

      for (Novo::DBObjects::ForeignKey f_key : table.GetForeignKeys()) {
        fkey_sql += "ALTER TABLE " + table.GetName();
        fkey_sql += " ADD CONSTRAINT " + f_key.GetName();
        fkey_sql += " FOREIGN KEY (" + f_key.GetSourceColumn() + ")";
        fkey_sql += " REFERENCES " + f_key.GetTargetTable() + "(" + f_key.GetTargetColumn() + ")";
        fkey_sql += ";\n";
      }

    }

    sql += fkey_sql;
    
    return sql;
  }
}

