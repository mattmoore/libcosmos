#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include "Column.h"
#include "ForeignKey.h"

namespace Novo {

  class Table {

  private:
    std::string _name;
    std::vector<Novo::Column> _columns;
    std::vector<Novo::ForeignKey> _f_keys;

  public:
    Table(std::string name);
    std::string GetName();

    void AddColumn(Novo::Column);
    void RemoveColumn(std::string name);

    void AddForeignKey(Novo::ForeignKey);
    void RemoveForeignKey(std::string name);

    std::vector<Novo::ForeignKey> GetForeignKeys();
    
    std::string GetSQL();
  };

}

#endif

