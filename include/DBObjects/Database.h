#ifndef DATABASE_H
#define DATABASE_H

#include "DBObjects/Table.h"

namespace Novo {
  namespace DBObjects {
    class Database {
    private:
      std::string name;
      std::vector<Novo::DBObjects::Table> tables;
    public:
      Database(std::string name);
      std::string GetName();
      void AddTable(Novo::DBObjects::Table table);
      void RemoveTable(std::string name);
      std::string GetSQL();
    };
  }
}

#endif
