#ifndef TABLE_H
#define TABLE_H

#include <string>

namespace Novo {
  namespace DBObjects {
    class Table {
    public:
      Table();
      std::string GetSQL();
    };
  }
}

#endif