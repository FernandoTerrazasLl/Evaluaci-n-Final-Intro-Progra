#pragma one
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

struct Fechas{
    int ano;
    int mes;
    int dia;
};

void anadiendo_ceros_extra(const Fechas& tiempo, string& key);
void dividir_fecha(string& ano_find, string& mes_find, string& dia_find, const string& fecha);
void comando_add(map<string,set<string>>& base_datos, Fechas tiempo, string evento);
void comando_del_evento(map<string,set<string>>& base_datos, Fechas tiempo, string evento);
void comando_del_fecha(map<string,set<string>>& base_datos, Fechas tiempo);
void comando_find(const map<string,set<string>>& base_datos, Fechas tiempo);
void comando_print(const map<string,set<string>>& base_datos);
void base_datos_principal(string comando, Fechas tiempo, string evento, map<string,set<string>>& base_datos);
