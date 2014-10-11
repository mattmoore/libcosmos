#ifndef COLUMN_H
#define COLUMN_H

#include <string>

namespace Novo {
  enum class ColumnType {
    INT,
    VARCHAR
  };

  class Column {
  private:
    std::string _name;
    Novo::ColumnType _type;
    uint _size;
  public:
    Column(std::string name, Novo::ColumnType type);
    Column(std::string name, Novo::ColumnType type, uint size);
    std::string GetName();
    Novo::ColumnType GetType();
    uint GetSize();
    std::string TypeToString(Novo::ColumnType type);
    std::string GetSQL();
  };
}

#endif
