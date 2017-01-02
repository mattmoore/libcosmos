#include "Utilities.h"

namespace Cosmos {
  std::vector<std::string> Utilities::SplitString(std::string s, std::string delim) {
    std::vector<std::string> result;
    auto start = 0U;
    auto end = s.find(delim);
    while (end != std::string::npos)
    {
      result.push_back(s.substr(start, end - start));
      start = end + delim.length();
      end = s.find(delim, start);
    }
    return result;
  }
}
