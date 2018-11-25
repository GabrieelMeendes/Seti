#include "/usr/include/jsoncpp/json/json.h"
#include "/usr/include/mysql/mysql.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define HOST "localhost"
#define USER "root"
#define PASS "132567"
#define DB "Teste"

int main() {
  MYSQL *conn;
  conn = mysql_init(NULL);

  if (mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0)) {
    cout << "Conectado ao Banco " << endl;
  } else {
    cout << "Não Conectado " << endl;
  }