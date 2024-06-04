#include "header.h"

void comando_add(map<string,set<string>>& base_datos, Fechas tiempo, string evento){
    string key = to_string(tiempo.ano) + "-" + to_string(tiempo.mes) + "-" + to_string(tiempo.dia);
    base_datos[key].insert(evento);

}   

void comando_del_evento(map<string,set<string>>& base_datos, Fechas tiempo, string evento){
    string key = to_string(tiempo.ano) + "-" + to_string(tiempo.mes) + "-" + to_string(tiempo.dia);
    if(base_datos.count(key) >0 && base_datos[key].count(evento)>0){
        base_datos[key].erase(evento);
        cout << "Deleted successfully" << endl;
    }else{
        cout << "Event not found" << endl;
    }
}

void comando_del_fecha(map<string,set<string>>& base_datos, Fechas tiempo){
    string key = to_string(tiempo.ano) + "-" + to_string(tiempo.mes) + "-" + to_string(tiempo.dia);
    int cantidad_eventos= base_datos[key].size();
    base_datos.erase(key);
    cout << "Deleted " << cantidad_eventos << " events" <<endl;
}

void comando_find(const map<string,set<string>>& base_datos, Fechas tiempo){
    string key = to_string(tiempo.ano) + "-" + to_string(tiempo.mes) + "-" + to_string(tiempo.dia);
    for(const auto& pair: base_datos(key)){ //AVERIGUAR SINTAXIS

    }
}

void comando_print(const map<string,set<string>>& base_datos){
    /*string ano_string;
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
*/
}

void base_datos_principal(string comando, Fechas tiempo, string evento, map<string,set<string>>& base_datos){
    if(comando=="Add"){
        comando_add(base_datos, tiempo, evento);

    }else if(comando=="Del" && !evento.empty()){
        comando_del_evento(base_datos, tiempo, evento);

    }else if(comando=="Del" && evento.empty()){
        comando_del_fecha(base_datos, tiempo);

    }else if(comando=="Find"){
        comando_find(base_datos, tiempo);

    }else if(comando=="Print"){
        comando_print(base_datos);
    }  
}