#include "../test_helpers.h"
#include <Connection.h>

void test_connection_connected();

int main() {
  test_connection_connected();
}

void test_connection_connected() {
  log("Connection class connects");
  Cosmos::Connection conn;
  conn.connect("postgresql://localhost");
  check(conn.is_connected() == true, "Connection connects to server");
}
