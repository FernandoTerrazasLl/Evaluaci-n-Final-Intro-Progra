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
    for(const string& eventos: base_datos.at(key)){ 
        cout << eventos << endl;
    }
}

void comando_print(const map<string,set<string>>& base_datos){
    
    for(const pair<string,set<string>>& fechas_eventos : base_datos){
        string ano_find, mes_find, dia_find;
        int find_clock=0;

        while(find_clock <fechas_eventos.first.size() && fechas_eventos.first[find_clock] != '-'){
            ano_find += fechas_eventos.first[find_clock];
            ++find_clock;
        }
        ++find_clock;

        while(find_clock < fechas_eventos.first.size() && fechas_eventos.first[find_clock] != '-'){
            mes_find += fechas_eventos.first[find_clock];
            ++find_clock;
        }
        ++find_clock; 
    
        while(find_clock< fechas_eventos.first.size()){
            dia_find += fechas_eventos.first[find_clock];
            ++find_clock;
        }

        int ano_int = stoi(ano_find);
        int mes_int = stoi(mes_find);
        int dia_int = stoi(dia_find);
        string ano_find_string;

        if(ano_int>0){
            int ceros_ano = 4 - to_string(ano_int).size();
            ano_find_string= string(ceros_ano, '0')+ to_string(ano_int);

        }else if(ano_int<0){
            int ceros_ano = 5- to_string(ano_int).size();
            ano_find_string= "-"s + string(ceros_ano, '0') + to_string(ano_int*-1);
        }
        int ceros_mes = 2 - to_string(mes_int).size();
        int ceros_dia = 2 - to_string(dia_int).size();

        string key =  ano_find_string + "-"s + string(ceros_mes, '0') + to_string(mes_int) + "-"s + string(ceros_dia, '0') + to_string(dia_int);


        for(string evento_container: fechas_eventos.second){
            cout << key  << " " <<evento_container << endl;

        }       
    }
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