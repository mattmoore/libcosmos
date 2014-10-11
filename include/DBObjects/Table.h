#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include "Column.h"
#include "ForeignKey.h"

namespace Novo {
  namespace DBObjects {

    class Table {

    private:
      std::string _name;
      std::vector<Novo::DBObjects::Column> _columns;
      std::string _pk;
      std::vector<Novo::DBObjects::ForeignKey> _f_keys;

    public:
      Table(std::string name);
      std::string GetName();

      void SetPK(std::string name);

      void AddColumn(Novo::DBObjects::Column);
      void RemoveColumn(std::string name);

      void AddForeignKey(Novo::DBObjects::ForeignKey);
      void RemoveForeignKey(std::string name);

      std::vector<Novo::DBObjects::ForeignKey> GetForeignKeys();
      
      std::string GetSQL();
    };

  }
}

#endif

