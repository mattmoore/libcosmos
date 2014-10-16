#include "DBObjects/ForeignKey.h"

namespace Novo {
  namespace DBObjects {

    ForeignKey::ForeignKey(std::string name) {
      this->name = name;
    }

    std::string ForeignKey::GetName() {
      return this->name;
    }

    void ForeignKey::SetSourceColumn(std::string name) {
      this->source_column = name;
    }

    void ForeignKey::SetTargetTable(std::string name) {
      this->target_table = name;
    }

    void ForeignKey::SetTargetColumn(std::string name) {
      this->target_column = name;
    }

    std::string ForeignKey::GetSourceColumn() {
      return this->source_column;
    }

    std::string ForeignKey::GetTargetTable() {
      return this->target_table;
    }

    std::string ForeignKey::GetTargetColumn() {
      return this->target_column;
    }

  }
}
