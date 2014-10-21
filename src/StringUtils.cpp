#include "StringUtils.h"

namespace Novo {
  StringUtils::StringUtils() {

  }

  std::vector<std::string> StringUtils::Split(std::string str, std::string delim) {
    std::vector<std::string> result;
    auto start = 0U;
    auto end = str.find(delim);
    while (end != std::string::npos)
    {
      result.push_back(str.substr(start, end - start));
      start = end + delim.length();
      end = str.find(delim, start);
    }
    return result;
  }
}
