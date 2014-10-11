#include "DBObjects/Column.h"

namespace Novo {
  namespace DBObjects {

    Column::Column(std::string name, Novo::DBObjects::ColumnType type) {
      _name = name;
      _type = type;
      _size = 0;
    }

    Column::Column(std::string name, Novo::DBObjects::ColumnType type, uint size) {
      _name = name;
      _type = type;
      _size = size;
    }

    std::string Column::GetName() {
      return _name;
    }

    Novo::DBObjects::ColumnType Column::GetType() {
      return _type;
    }

    uint Column::GetSize() {
      return _size;
    }

    std::string Column::TypeToString(Novo::DBObjects::ColumnType type) {
      switch (type) {
        case Novo::DBObjects::ColumnType::INT:
          return "INT";
        case Novo::DBObjects::ColumnType::VARCHAR:
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
}
