#include "SchemaFile.h"

namespace Novo {

  SchemaFile::SchemaFile() {

  }

  void SchemaFile::Load(std::string filename) {
    std::fstream file(filename, std::ios::in);
    if (file.is_open()) {
      this->file_contents.clear();
      std::string line;
      while (getline(file, line)) {
        this->file_contents.append(line);
        this->file_contents.append("\n");
      }
    }
    file.close();
  }

  std::string SchemaFile::GetFileContents() {
    return this->file_contents;
  }

}