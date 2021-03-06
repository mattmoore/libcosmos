#pragma once

#include <sstream>
#include <string>
#include <vector>

#include "Types.h"

namespace Cosmos {
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
