#pragma one
#include <iostream>
#include <map>
#include <string>

using namespace std;
struct Fechas{
    int ano;
    int mes;
    int dia;
};

void comando_add(map<string,string>& base_datos, Fechas tiempo, string evento);
void comando_del_evento(map<string,string>& base_datos, Fechas tiempo, string evento);
void comando_del_fecha(map<string,string>& base_datos, Fechas tiempo);
void comando_find(const map<string,string>& base_datos, Fechas tiempo);
void comando_print(const map<string,string>& base_datos);
void base_datos_principal(string comando, Fechas tiempo, string evento, map<string,string>& base_datos);
