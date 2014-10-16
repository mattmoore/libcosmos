#include "DBObjects/Column.h"

namespace Novo {
  namespace DBObjects {

    Column::Column(std::string name, Novo::DBObjects::ColumnType type) {
      this->name = name;
      this->type = type;
      this->size = 0;
    }

    Column::Column(std::string name, Novo::DBObjects::ColumnType type, uint size) {
      this->name = name;
      this->type = type;
      this->size = size;
    }

    std::string Column::GetName() {
      return this->name;
    }

    Novo::DBObjects::ColumnType Column::GetType() {
      return this->type;
    }

    uint Column::GetSize() {
      return this->size;
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
