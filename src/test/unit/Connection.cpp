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
  std::string server_time = conn.server_time();
  conn.disconnect();
  check(server_time.find("2017") != std::string::npos, "server returns time: " + server_time);
}

int main() {
  log("Connection class");
  test_connection();
  test_psql_server_time();
}
