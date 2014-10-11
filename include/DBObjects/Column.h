#ifndef COLUMN_H
#define COLUMN_H

#include <string>

namespace Novo {
  namespace DBObjects {
    enum class ColumnType {
      INT,
      VARCHAR
    };

    class Column {
    private:
      std::string _name;
      Novo::DBObjects::ColumnType _type;
      uint _size;
    public:
      Column(std::string name, Novo::DBObjects::ColumnType type);
      Column(std::string name, Novo::DBObjects::ColumnType type, uint size);
      std::string GetName();
      Novo::DBObjects::ColumnType GetType();
      uint GetSize();
      std::string TypeToString(Novo::DBObjects::ColumnType type);
      std::string GetSQL();
    };
  }
}

#endif
