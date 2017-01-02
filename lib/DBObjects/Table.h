#pragma once

#include <string>
#include <vector>
#include "Column.h"
#include "ForeignKey.h"
#include "Types.h"
#include "Utilities.h"

namespace Cosmos {
  namespace DBObjects {

    class Table {

    private:
      std::string name;
      std::vector<Cosmos::DBObjects::Column> columns;
      std::string pk;
      std::vector<Cosmos::DBObjects::ForeignKey> f_keys;

    public:
      Table(std::string name);
      std::string GetName();

      void SetPK(std::string name);

      void AddColumn(Cosmos::DBObjects::Column);
      void RemoveColumn(std::string name);

      void AddForeignKey(Cosmos::DBObjects::ForeignKey);
      void RemoveForeignKey(std::string name);

      std::vector<Cosmos::DBObjects::ForeignKey> GetForeignKeys();

      std::string GetSQL();
    };

  }
}
