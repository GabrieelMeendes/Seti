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

  mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0);

  mysql_query(conn, "SELECT Usuarios.Usuario, Usuarios.Usuario, Usuarios.Login , Usuarios.Senha FROM Usuarios");

  MYSQL_RES *resultado;
  MYSQL_ROW linhas;

  Json::Value valor,JSON;

  resultado = mysql_store_result(conn);

  while ((linhas = mysql_fetch_row(resultado))) {
    valor["Usuario"] = linhas[0];
    valor["Login"] = linhas[1];
    valor["Senha"] = linhas[2];
    JSON.append(valor);
    valor.clear();
  }

  Json::FastWriter leia;

  string saidaDeDados = leia.write(JSON);
  cout << saidaDeDados;
  mysql_free_result(resultado);
  mysql_close(NULL);
  return 0;
}