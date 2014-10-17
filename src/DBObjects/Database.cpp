#include "DBObjects/Database.h"

namespace Novo {
  namespace DBObjects {

    Database::Database(std::string name) {
      this->name = name;
    }

    std::string Database::GetName() {
      return this->name;
    }

    Novo::DBObjects::Table* Database::GetTable(std::string name) {
      Novo::DBObjects::Table* table_pointer = NULL;
      for (Novo::DBObjects::Table& table : this->tables) {
        if (table.GetName() == name) {
          table_pointer = &table;
        }
      }
      return table_pointer;
    }

    void Database::AddTable(Novo::DBObjects::Table table) {
      this->tables.push_back(table);
    }

    void Database::RemoveTable(std::string name) {
      for (uint i = 0; i < this->tables.size(); ++i) {
        if (this->tables[i].GetName() == name) {
          this->tables.erase(this->tables.begin() + i);
        }
      }
    }

    std::string Database::GetSQL() {
      std::string sql;
      std::string fkey_sql;

      for (Novo::DBObjects::Table &table : this->tables) {
        sql += table.GetSQL();

        for (Novo::DBObjects::ForeignKey f_key : table.GetForeignKeys()) {
          fkey_sql += "ALTER TABLE " + table.GetName();
          fkey_sql += " ADD CONSTRAINT " + f_key.GetName();
          fkey_sql += " FOREIGN KEY (" + f_key.GetSourceColumn() + ")";
          fkey_sql += " REFERENCES " + f_key.GetTargetTable() + "(" + f_key.GetTargetColumn() + ")";
          fkey_sql += ";\n";
        }

      }

      sql += fkey_sql;
      
      return sql;
    }

  }
}
