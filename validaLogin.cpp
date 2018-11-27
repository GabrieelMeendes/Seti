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

int main(int argc, char *argv[]){
  if(argc != 3 ){
    cout << " Parametros Invalidos !" << endl ;
    return 0;
  }

  MYSQL *conn;
  conn = mysql_init(NULL);

  string login = string(argv[1]);
  string senha = string(argv[2]);

  mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0);

  MYSQL_RES *resultado;

  mysql_query(conn,("select Login,Senha from Usuarios where Login ='"+login+"' and Senha = '"+senha+"'").c_str());
  resultado = mysql_store_result(conn);
  int linhas = mysql_num_rows(resultado);

  if (linhas == 1){
    cout << "1" << endl ;
    mysql_close(conn);
  }
  else{
    cout << "2" << endl ;
    mysql_close(conn);
  }

  mysql_free_result(resultado);
  mysql_close(conn);
  return 0;

}
