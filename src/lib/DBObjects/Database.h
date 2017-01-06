#pragma once

#include "DBObjects/Table.h"
#include "Types.h"

namespace Cosmos {
  namespace DBObjects {
    class Database {
    private:
      std::string name;
      std::vector<Cosmos::DBObjects::Table> tables;
    public:
      Database(std::string name);

      std::string GetName();

      Cosmos::DBObjects::Table* GetTable(std::string name);

      void AddTable(Cosmos::DBObjects::Table table);
      void RemoveTable(std::string name);

      std::string GetSQL();
    };
  }
}
