#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <vector>
#include "Database.h"
#include "Table.h"

namespace Novo {
  class Schema {
  private:
    std::vector<Novo::Database> _databases;
    std::vector<Novo::Table> _tables;
    
  public:
    Schema();

    void AddDatabase(Novo::Database database);
    void RemoveDatabase(std::string name);

    void AddTable(Novo::Table table);
    void RemoveTable(std::string name);

    std::string GetSQL();

    enum class DataType;
  };
}

#endif
