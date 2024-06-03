#include "header.h"

void comando_add(map<int,string>& base_datos){
    
}
void comando_del_evento(map<int,string>& base_datos){

}
void comando_del_fecha(map<int,string>& base_datos){

}
void comando_find(const map<int,string>& base_datos){

}
void comando_print(const map<int,string>& base_datos){

}
void base_datos_principal(string comando, string fecha, string evento,map<int,string>& base_datos){
    if(comando=="Add"){
        comando_add(base_datos);

    }else if(comando=="Del" && evento.empty()){
        comando_del_evento(base_datos);

    }else if(comando=="Del" && !evento.empty()){
        comando_del_fecha(base_datos);

    }else if(comando=="Find"){
        comando_find(base_datos);

    }else if(comando=="Print"){
        comando_print(base_datos);
    }  
}