#include "Table.h"

namespace Novo {
  Table::Table(std::string name) {
    _name = name;
  }

  std::string Table::GetName() {
    return _name;
  }

  std::string Table::GetSQL() {
    std::string sql;
    sql = "CREATE TABLE " + _name + " (" + "\n";
    // TODO: Add columns
    sql += ");\n";
    return sql;
  }
}
