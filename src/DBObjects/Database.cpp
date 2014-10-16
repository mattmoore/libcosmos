#include "DBObjects/Database.h"

namespace Novo {
  namespace DBObjects {
    Database::Database(std::string name) {
      this->name = name;
    }

    std::string Database::GetName() {
      return this->name;
    }

    void Database::AddTable(Novo::DBObjects::Table table) {
      this->tables.push_back(table);
    }

    void Database::RemoveTable(std::string name) {
      for (uint i = 0; i < this->tables.size(); ++i) {
        if (this->tables[i].GetName() == name) {
          this->tables.erase(this->tables.begin() + i);
        }
      }
    }

    std::string Database::GetSQL() {
      std::string sql;
      return sql;
    }
  }
}
