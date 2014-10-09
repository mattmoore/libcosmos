#include "Schema.h"

namespace Novo {
  Schema::Schema() {

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
    for (Novo::Table &table : _tables) {
      sql += table.GetSQL();
    }
    return sql;
  }
}
