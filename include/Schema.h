#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <vector>
#include "Table.h"

namespace Novo {
  class Schema {
  private:
    std::vector<Novo::Table> _tables;
  public:
    Schema();
    void AddTable(Novo::Table table);
    void RemoveTable(std::string name);
    std::string GetSQL();
    enum class DataType;
  };
}

#endif
