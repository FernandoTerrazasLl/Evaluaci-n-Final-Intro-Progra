#pragma one
#include <iostream>
#include <map>
#include <string>

using namespace std;
struct Fechas{
    string ano;
    string mes;
    string dia;
};

void comando_add(map<int,string>& base_datos);
void comando_del_evento(map<int,string>& base_datos);
void comando_del_fecha(map<int,string>& base_datos);
void comando_find(const map<int,string>& base_datos);
void comando_print(const map<int,string>& base_datos);
void base_datos_principal(string comando, Fechas tiempo, string evento, map<int,string>& base_datos);
