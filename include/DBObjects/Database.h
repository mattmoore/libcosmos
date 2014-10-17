#ifndef DATABASE_H
#define DATABASE_H

#include "DBObjects/Table.h"
#include "Types.h"

namespace Novo {
  namespace DBObjects {
    class Database {
    private:
      std::string name;
      std::vector<Novo::DBObjects::Table> tables;
    public:
      Database(std::string name);

      std::string GetName();

      Novo::DBObjects::Table* GetTable(std::string name);

      void AddTable(Novo::DBObjects::Table table);
      void RemoveTable(std::string name);

      std::string GetSQL();
    };
  }
}

#endif
