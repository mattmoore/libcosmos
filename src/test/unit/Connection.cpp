#include "../test_helpers.h"
#include <Connection.h>

void test_connection() {
  log("server connection");
  Cosmos::Connection conn;
  conn.connect("postgresql://localhost");
  check(conn.is_connected() == true, "connects to server");
  conn.disconnect();
  check(conn.is_connected() == false, "disconnects from server");
}

void test_psql_server_time() {
  log("query server time");
  Cosmos::Connection conn;
  conn.connect("postgresql://localhost");
}

int main() {
  log("Connection class");
  test_connection();
  test_psql_server_time();
}
