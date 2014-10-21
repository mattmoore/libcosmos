#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>
#include <string>
#include <vector>

#include "Types.h"

namespace Novo {
  class Utilities {
  public:
    template <typename T>
    static std::string ToString(T value) {
      std::stringstream ss;
      ss << value;
      std::string result;
      ss >> result;
      return result;
    }
    std::vector<std::string> SplitString(std::string s, std::string delim);
  };
}

#endif
