#include "DBObjects/Table.h"

namespace Novo {
  namespace DBObjects {
    Table::Table(std::string name) {
      _name = name;
    }

    std::string Table::GetName() {
      return _name;
    }

    void Table::SetPK(std::string name) {
      _pk = name;
    }

    void Table::AddColumn(Novo::DBObjects::Column column) {
      _columns.push_back(column);
    }

    void Table::RemoveColumn(std::string name) {
      for (uint i = 0; i < _columns.size(); ++i) {
        if (_columns[i].GetName() == name) {
          _columns.erase(_columns.begin() + i);
        }
      }
    }

    void Table::AddForeignKey(Novo::DBObjects::ForeignKey key) {
      _f_keys.push_back(key);
    }

    void Table::RemoveForeignKey(std::string name) {
      for (uint i = 0; i < _f_keys.size(); ++i) {
        if (_f_keys[i].GetName() == name) {
          _f_keys.erase(_f_keys.begin() + i);
        }
      }
    }

    std::vector<Novo::DBObjects::ForeignKey> Table::GetForeignKeys() {
      return _f_keys;
    }

    std::string Table::GetSQL() {
      std::string sql;

      sql = "CREATE TABLE " + _name + " (" + "\n";

      for (Novo::DBObjects::Column &column : _columns) {
        sql += "  " + column.GetName() + " " + column.TypeToString(column.GetType());
        if (column.GetSize() > 0) {
          sql += "(" + std::to_string(column.GetSize()) + ")";
        }
        if (column.GetName() == _pk) {
          sql += " PRIMARY KEY";
        }
        sql += ",\n";
      }

      sql += ");\n";

      return sql;
    }
  }
}
