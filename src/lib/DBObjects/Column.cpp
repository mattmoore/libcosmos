#include "DBObjects/Column.h"

namespace Cosmos {
  namespace DBObjects {

    Column::Column(std::string name, Cosmos::DBObjects::ColumnType type) {
      this->name = name;
      this->type = type;
      this->size = 0;
    }

    Column::Column(std::string name, Cosmos::DBObjects::ColumnType type, uint size) {
      this->name = name;
      this->type = type;
      this->size = size;
    }

    std::string Column::GetName() {
      return this->name;
    }

    Cosmos::DBObjects::ColumnType Column::GetType() {
      return this->type;
    }

    uint Column::GetSize() {
      return this->size;
    }

    std::string Column::TypeToString(Cosmos::DBObjects::ColumnType type) {
      switch (type) {
        case Cosmos::DBObjects::ColumnType::INT:
          return "INT";
        case Cosmos::DBObjects::ColumnType::VARCHAR:
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
