#ifndef FOREIGN_KEY_H
#define FOREIGN_KEY_H

#include <string>

namespace Novo {
  namespace DBObjects {
    class ForeignKey {
    private:
      std::string _name;
      std::string _source_column;
      std::string _target_table;
      std::string _target_column;

    public:
      ForeignKey(std::string name);

      std::string GetName();

      void SetSourceColumn(std::string name);
      void SetTargetTable(std::string name);
      void SetTargetColumn(std::string name);

      std::string GetSourceColumn();
      std::string GetTargetTable();
      std::string GetTargetColumn();
    };
  }
}

#endif
