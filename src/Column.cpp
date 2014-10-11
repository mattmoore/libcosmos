#include "Column.h"

namespace Novo {

  Column::Column(std::string name, Novo::ColumnType type) {
    _name = name;
    _type = type;
    _size = 0;
  }

  Column::Column(std::string name, Novo::ColumnType type, uint size) {
    _name = name;
    _type = type;
    _size = size;
  }

  std::string Column::GetName() {
    return _name;
  }

  Novo::ColumnType Column::GetType() {
    return _type;
  }

  uint Column::GetSize() {
    return _size;
  }

  std::string Column::TypeToString(Novo::ColumnType type) {
    switch (type) {
      case Novo::ColumnType::INT:
        return "INT";
      case Novo::ColumnType::VARCHAR:
        return "VARCHAR";
      default:
        return NULL;
        break;
    }
  }

  std::string Column::GetSQL() {
    std::string sql;
    return sql;
  }
  
}
