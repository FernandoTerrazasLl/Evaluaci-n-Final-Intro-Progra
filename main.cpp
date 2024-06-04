#include "header.h"
#include <iostream>
using namespace std;
int main(){
    int control=0;
    map<string, set<string>> base_datos;
    do{
        string comando;
        string fecha;
        string evento;

        Fechas tiempo;
        string ano;
        string mes;
        string dia;
        cout << "Ingrese comando y argumentos designados" << endl;
        cin >> comando;

        if(comando=="Add" || comando=="Del" || comando=="Find" || comando=="Print"){
            if(comando != "Print"){
                if(comando=="Del"){
                    //Procedimiento si no nos dan el evento en Del
                    string entrada_del;
                    getline(cin,entrada_del);
                    int size_del=1;
                    while(size_del<entrada_del.size()){
                        if(entrada_del[size_del]==' '){
                            ++size_del;
                            break;
                        } 
                        fecha += entrada_del[size_del];
                        ++size_del;
                    }
                    
                    if(size_del==entrada_del.size()-1){
                        evento ="";
                    }else{
                        while(size_del<entrada_del.size()){
                            if(entrada_del[size_del]==' '){
                                ++size_del;
                                break;
                            } 
                            evento += entrada_del[size_del];
                            ++size_del;
                        }
                    }

                }else if(comando != "Del"){
                    cin >> fecha;
                }

                if(((fecha[0]<= '9' && fecha[0]>= '0') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))
                || ((fecha[0]=='-' && fecha[1] !='-') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))
                || ((fecha[0]=='+' && fecha[1] !='+') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))){

                }else{
                    cout << "Wrong Date Format: " << fecha << endl;
                    return 0;
                }
                int i=0;
                while(i<fecha.size()){
                    ano +=fecha[i];
                    if(fecha[i+1]=='-'){
                        i +=2;
                        break;
                    }
                    ++i;
                }
                while(i<fecha.size()){
                    mes +=fecha[i];
                    if(fecha[i+1]=='-'){
                        i +=2;
                        break;
                    }
                    ++i;
                }
                
                if(stoi(mes)>12 || stoi(mes)<1){
                    cout << "Month value is invalid:" << mes << endl;
                    return 0;
                }

                while(i<fecha.size()){
                    dia +=fecha[i];
                    ++i;
                }
                
                if(stoi(dia)>31 || stoi(dia)<1){
                    cout << "Day value is invalid: " << dia << endl;
                    return 0;
                }
            }

        }else{
            cout << "Unknown command: " << comando << endl;
            return 0;
        }

        if(comando =="Add"){
                cin >> evento;
        }

        tiempo.ano = stoi(ano);
        tiempo.mes = stoi(mes);
        tiempo.dia = stoi(dia);

    base_datos_principal(comando, tiempo, evento, base_datos);
    }while(control>=0);


    return 0;
}
