#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <iostream>
#include <vector>
#include <string>

namespace Novo {
  class StringUtils {
  public:
    StringUtils();
    std::vector<std::string> Split(std::string str, std::string delim);
  };
}

#endif

