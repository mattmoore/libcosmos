#pragma once

#include <string>
#include "Types.h"

namespace Cosmos {
  namespace DBObjects {
    class PrimaryKey {
    private:
      std::string name;

    public:
      PrimaryKey(std::string name);
    };
  }
}
