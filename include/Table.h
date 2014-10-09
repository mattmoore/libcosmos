#ifndef TABLE_H
#define TABLE_H

#include <string>

namespace Novo {
  class Table {
  private:
    std::string _name;
  public:
    Table(std::string name);
    std::string GetName();
    std::string GetSQL();
  };
}

#endif
