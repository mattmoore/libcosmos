#include "Table.h"

namespace Novo {
  Table::Table(std::string name) {
    _name = name;
  }

  std::string Table::GetName() {
    return _name;
  }

  void Table::AddColumn(Novo::Column column) {
    _columns.push_back(column);
  }

  void Table::RemoveColumn(std::string name) {
    for (uint i = 0; i < _columns.size(); ++i) {
      if (_columns[i].GetName() == name) {
        _columns.erase(_columns.begin() + i);
      }
    }
  }

  std::string Table::GetSQL() {
    std::string sql;
    sql = "CREATE TABLE " + _name + " (" + "\n";
    for (Novo::Column &column : _columns) {
      sql += "  " + column.GetName() + " " + column.TypeToString(column.GetType());
      if (column.GetSize() > 0) {
        sql += "(" + std::to_string(column.GetSize()) + ")";
      }
      sql += ",\n";
    }
    sql += ");\n";
    return sql;
  }
}
