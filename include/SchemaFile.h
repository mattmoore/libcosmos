#ifndef SCHEMAFILE_H
#define SCHEMAFILE_H

#include <iostream>
#include <fstream>
#include <string>

namespace Novo {
  class SchemaFile {
  private:
    std::string file_contents;
  public:
    SchemaFile();
    void Load(std::string filename);
    std::string GetFileContents();
  };
}

#endif
