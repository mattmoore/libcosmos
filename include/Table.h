#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include "Column.h"

namespace Novo {
  class Table {
  private:
    std::string _name;
    std::vector<Novo::Column> _columns;
  public:
    Table(std::string name);
    std::string GetName();

    void AddColumn(Novo::Column);
    void RemoveColumn(std::string name);
    
    std::string GetSQL();
  };
}

#endif

