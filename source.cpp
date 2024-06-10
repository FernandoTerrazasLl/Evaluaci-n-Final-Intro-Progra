#include "header.h"

void anadiendo_ceros_extra(const Fechas& tiempo, string& key){
    
        string ano_find_string;

        if(tiempo.ano>0){
            int ceros_ano = 4 - to_string(tiempo.ano).size();
            ano_find_string= string(ceros_ano, '0')+ to_string(tiempo.ano);

        }else if(tiempo.ano<0){
            int ceros_ano = 5- to_string(tiempo.ano).size();
            ano_find_string= "-"s + string(ceros_ano, '0') + to_string(tiempo.ano*-1);
        }
        int ceros_mes = 2 - to_string(tiempo.mes).size();
        int ceros_dia = 2 - to_string(tiempo.dia).size();

        key =  ano_find_string + "-"s + string(ceros_mes, '0') + to_string(tiempo.mes) + "-"s + string(ceros_dia, '0') + to_string(tiempo.dia);
}

bool verificando_formato_fecha(const string& ano){
    int contador_error_ano=0;
    for(int i=0; i<ano.size(); ++i){
        if(ano[i]=='-' || ano[i]=='+'){
            ++contador_error_ano;
        }
        if(ano[i]>'9' || ano[i]<'0' && ano[i] !='+' && ano[i] !='-'|| contador_error_ano >1){
            return true;
        }
    }
    return false;
}
void dividir_fecha(string& ano_find, string& mes_find, string& dia_find, const string& fecha){
    int find_clock=0;

    do{
        ano_find += fecha[find_clock];
        ++find_clock;
    }while(find_clock <fecha.size() && fecha[find_clock] != '-');
    ++find_clock;

    do{
        mes_find += fecha[find_clock];
        ++find_clock;
    }while(find_clock < fecha.size() && fecha[find_clock] != '-');
    ++find_clock; 
  
    do{
        dia_find += fecha[find_clock];
        ++find_clock;
    }while(find_clock< fecha.size());
}
void comando_add(map<string,set<string>>& base_datos, Fechas tiempo, string evento){
    // Anadiendo ceros extras a las fechas AAAA-MM-DD y guardando
    string key;

    anadiendo_ceros_extra(tiempo, key);

    base_datos[key].insert(evento);

}   

void comando_del_evento(map<string,set<string>>& base_datos, Fechas tiempo, string evento){
    string key;
    anadiendo_ceros_extra(tiempo, key);

    if(base_datos.count(key) >0 && base_datos[key].count(evento)>0){
        base_datos[key].erase(evento);
        cout << "Deleted successfully" << endl;
    }else{
        cout << "Event not found" << endl;
    }
}

void comando_del_fecha(map<string,set<string>>& base_datos, Fechas tiempo){
    string key;

    anadiendo_ceros_extra(tiempo, key);

    int cantidad_eventos= base_datos[key].size();
    base_datos.erase(key);
    cout << "Deleted " << cantidad_eventos << " events" <<endl;
}

void comando_find(const map<string,set<string>>& base_datos, Fechas tiempo){
    string key;
    anadiendo_ceros_extra(tiempo, key);

    for(const string& eventos: base_datos.at(key)){ 
        cout << eventos << endl;
    }
}

void comando_print(const map<string,set<string>>& base_datos){
    
    for(const pair<string,set<string>>& fechas_eventos : base_datos){
        
        for(string evento_container_second: fechas_eventos.second){
            cout << fechas_eventos.first  << " " << evento_container_second << endl;
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