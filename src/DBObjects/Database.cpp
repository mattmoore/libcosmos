#include "DBObjects/Database.h"

namespace Novo {
  namespace DBObjects {
    Database::Database(std::string name) {
      _name = name;
    }

    std::string Database::GetName() {
      return _name;
    }

    void Database::AddTable(Novo::DBObjects::Table table) {
      _tables.push_back(table);
    }

    void Database::RemoveTable(std::string name) {
      for (uint i = 0; i < _tables.size(); ++i) {
        if (_tables[i].GetName() == name) {
          _tables.erase(_tables.begin() + i);
        }
      }
    }

    std::string Database::GetSQL() {
      std::string sql;
      return sql;
    }
  }
}
