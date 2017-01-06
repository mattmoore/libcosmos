#pragma once

#include <string>
#include "Types.h"

namespace Cosmos {
  namespace DBObjects {
    enum class ColumnType {
      INT,
      VARCHAR
    };

    class Column {
    private:
      std::string name;
      Cosmos::DBObjects::ColumnType type;
      uint size;
    public:
      Column(std::string name, Cosmos::DBObjects::ColumnType type);
      Column(std::string name, Cosmos::DBObjects::ColumnType type, uint size);
      std::string GetName();
      Cosmos::DBObjects::ColumnType GetType();
      uint GetSize();
      std::string TypeToString(Cosmos::DBObjects::ColumnType type);
      std::string GetSQL();
    };
  }
}
