#include "DBObjects/Table.h"

namespace Cosmos {
  namespace DBObjects {

    Table::Table(std::string name) {
      this->name = name;
    }

    std::string Table::GetName() {
      return this->name;
    }

    void Table::SetPK(std::string name) {
      this->pk = name;
    }

    void Table::AddColumn(Cosmos::DBObjects::Column column) {
      this->columns.push_back(column);
    }

    void Table::RemoveColumn(std::string name) {
      for (uint i = 0; i < this->columns.size(); ++i) {
        if (this->columns[i].GetName() == name) {
          this->columns.erase(this->columns.begin() + i);
        }
      }
    }

    void Table::AddForeignKey(Cosmos::DBObjects::ForeignKey key) {
      this->f_keys.push_back(key);
    }

    void Table::RemoveForeignKey(std::string name) {
      for (uint i = 0; i < this->f_keys.size(); ++i) {
        if (this->f_keys[i].GetName() == name) {
          this->f_keys.erase(this->f_keys.begin() + i);
        }
      }
    }

    std::vector<Cosmos::DBObjects::ForeignKey> Table::GetForeignKeys() {
      return this->f_keys;
    }

    std::string Table::GetSQL() {
      std::string sql;

      sql = "CREATE TABLE " + this->name + " (" + "\n";

      uint col_index = 0;
      for (Cosmos::DBObjects::Column &column : this->columns) {
        sql += "  " + column.GetName() + " " + column.TypeToString(column.GetType());
        if (column.GetSize() > 0) {
          sql += "(" + Cosmos::Utilities::ToString(column.GetSize()) + ")";
        }
        if (column.GetName() == this->pk) {
          sql += " PRIMARY KEY";
        }
        if (col_index < this->columns.size() - 1) {
          sql += ",";
        }
        sql += "\n";
        ++col_index;
      }

      sql += ");\n";

      return sql;
    }

  }
}
