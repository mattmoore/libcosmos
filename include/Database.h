#ifndef DATABASE_H
#define DATABASE_H

#include "Table.h"

namespace Novo {
  class Database {
  private:
    std::string _name;
    std::vector<Novo::Table> _tables;
  public:
    Database(std::string name);
    std::string GetName();
    void AddTable(Novo::Table table);
    void RemoveTable(std::string name);
    std::string GetSQL();
  };
}

#endif
