#pragma one
#include <iostream>
#include <map>
#include <string>

using namespace std;
void comando_add(map<int,string>& base_datos);
void comando_del_evento(map<int,string>& base_datos);
void comando_del_fecha(map<int,string>& base_datos);
void comando_find(const map<int,string>& base_datos);
void comando_print(const map<int,string>& base_datos);
void base_datos_principal(string comando, string fecha, string evento, map<int,string>& base_datos);
