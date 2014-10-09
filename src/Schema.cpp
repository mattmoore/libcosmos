#include "Schema.h"

namespace Novo {
  Schema::Schema() {

  }

  void Schema::AddTable(std::string name) {
    Novo::Table table(name);
    _tables.push_back(table);
  }

  void Schema::RemoveTable(std::string name) {
    for (int i = 0; i < _tables.size(); ++i) {
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
