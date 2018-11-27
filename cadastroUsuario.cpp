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

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    cout << " Parametros Invalidos !" << endl;
    return 0;
  }

  MYSQL *conn;
  conn = mysql_init(NULL);

  string nome = string(argv[2]);
  string login = string(argv[3]);
  string senha = string(argv[4]);

  mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0);

  MYSQL_RES *resultado;

  mysql_query(conn, ("select Login from Usuarios where Login = '" + login + "'").c_str());
  resultado = mysql_store_result(conn);
  int linhas = mysql_num_rows(resultado);
  if (linhas == 0)
  {
    mysql_query(conn, ("INSERT INTO Usuarios(Usuario,Login,Senha)Values('" + nome + "','" + login + "','" + senha + "')").c_str());
    cout << "Usuario cadastrado !!!" << endl;
  }
  else
  {
    cout << "Usuario já existe !!!" << endl;
  }
  
  mysql_free_result(resultado);
  mysql_close(conn);
  return 0;
}
