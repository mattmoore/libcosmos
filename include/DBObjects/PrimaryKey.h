#ifndef PRIMARY_KEY_H
#define PRIMARY_KEY_H

#include <string>

namespace Novo {
  namespace DBObjects {
    class PrimaryKey {
    private:
      std::string name;

    public:
      PrimaryKey(std::string name);
    };
  }
}

#endif