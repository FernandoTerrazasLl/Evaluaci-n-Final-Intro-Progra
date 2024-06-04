#include "header.h"

void comando_add(map<string,string>& base_datos, Fechas tiempo, string evento){
    string ano_string;
    if(tiempo.ano>0){
        int ceros_extras_ano = 4 - to_string(tiempo.ano).size();
        ano_string= string(ceros_extras_ano, '0')+ to_string(tiempo.ano);

    }else if(tiempo.ano<0){
        int ceros_extras_ano = 5- to_string(tiempo.ano).size();
        ano_string= "-"s + string(ceros_extras_ano, '0') + to_string(tiempo.ano*-1);
    }
    int ceros_extras_mes = 2 - to_string(tiempo.mes).size();
    int ceros_extras_dia = 2 - to_string(tiempo.dia).size();

    string key =  ano_string + "-"s + string(ceros_extras_mes, '0') + to_string(tiempo.mes) + "-"s + string(ceros_extras_dia, '0') + to_string(tiempo.dia);
    base_datos[key] = "evento";

}   
void comando_del_evento(map<string,string>& base_datos, Fechas tiempo, string evento){

}
void comando_del_fecha(map<string,string>& base_datos, Fechas tiempo){

}
void comando_find(const map<string,string>& base_datos, Fechas tiempo){

}
void comando_print(const map<string,string>& base_datos){

}
void base_datos_principal(string comando, Fechas tiempo, string evento, map<string,string>& base_datos){
    if(comando=="Add"){
        comando_add(base_datos, tiempo, evento);

    }else if(comando=="Del" && evento.empty()){
        comando_del_evento(base_datos, tiempo, evento);

    }else if(comando=="Del" && !evento.empty()){
        comando_del_fecha(base_datos, tiempo);

    }else if(comando=="Find"){
        comando_find(base_datos, tiempo);

    }else if(comando=="Print"){
        comando_print(base_datos);
    }  
}