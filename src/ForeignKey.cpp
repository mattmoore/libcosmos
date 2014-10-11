#include "ForeignKey.h"

namespace Novo {

  ForeignKey::ForeignKey(std::string name) {
    _name = name;
  }

  std::string ForeignKey::GetName() {
    return _name;
  }

  void ForeignKey::SetSourceColumn(std::string name) {
    _source_column = name;
  }

  void ForeignKey::SetTargetTable(std::string name) {
    _target_table = name;
  }

  void ForeignKey::SetTargetColumn(std::string name) {
    _target_column = name;
  }

  std::string ForeignKey::GetSourceColumn() {
    return _source_column;
  }

  std::string ForeignKey::GetTargetTable() {
    return _target_table;
  }

  std::string ForeignKey::GetTargetColumn() {
    return _target_column;
  }

}
