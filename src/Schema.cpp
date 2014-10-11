#include "Schema.h"

namespace Novo {
  Schema::Schema(Novo::DatabaseType dbType) {
    _databaseType = dbType;
  }

  void Schema::AddDatabase(Novo::Database database) {
    _databases.push_back(database);
  }

  void Schema::RemoveDatabase(std::string name) {
    for (uint i = 0; i < _databases.size(); ++i) {
      if (_databases[i].GetName() == name) {
        _databases.erase(_databases.begin() + i);
      }
    }
  }

  void Schema::AddTable(Novo::Table table) {
    _tables.push_back(table);
  }

  void Schema::RemoveTable(std::string name) {
    for (uint i = 0; i < _tables.size(); ++i) {
      if (_tables[i].GetName() == name) {
        _tables.erase(_tables.begin() + i);
      }
    }
  }

  std::string Schema::GetSQL() {
    std::string sql;
    std::string fkey_sql;

    for (Novo::Table &table : _tables) {
      sql += table.GetSQL();

      for (Novo::ForeignKey f_key : table.GetForeignKeys()) {
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

