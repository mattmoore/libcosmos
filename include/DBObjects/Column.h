#ifndef COLUMN_H
#define COLUMN_H

#include <string>

namespace Novo {
  namespace DBObjects {
    class Column {
    public:
      Column();
      std::string GetSQL();
    };
  }
}

#endif