#ifndef DB_H
#define DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <libgen.h>

#include <sybfront.h>
#include <sybdb.h>

namespace Novo {
  class DB {
  private:
    int err_handler(DBPROCESS*, int, int, int, char*, char*);
    int msg_handler(DBPROCESS*, DBINT, int, int, char*, char*, char*, int);
  public:
    DB();
  };
}

#endif
