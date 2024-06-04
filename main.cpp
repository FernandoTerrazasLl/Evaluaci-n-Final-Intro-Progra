#include "header.h"
#include <iostream>
using namespace std;
int main(){
    int control=0;
    map<int, string> base_datos;
    do{
        string comando;
        string fecha;
        string evento;

        Fechas tiempo;
        cout << "Ingrese comando y argumentos designados" << endl;
        cin >> comando;
        
        if(comando=="Add" || comando=="Del" || comando=="Find" || comando=="Print"){
            if(comando != "Print"){

                cin >> fecha;
                if(((fecha[0]<= '9' && fecha[0]>= '0') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))
                || ((fecha[0]=='-' && fecha[1] !='-') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))
                || ((fecha[0]=='+' && fecha[1] !='+') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))){

                }else{
                    cout << "Wrong Date Format: " << fecha << endl;
                    return 0;
                }
                int i=0;
                while(i<fecha.size()){
                    tiempo.ano +=fecha[i];
                    if(fecha[i+1]=='-'){
                        i +=2;
                        break;
                    }
                    ++i;
                }
                while(i<fecha.size()){
                    tiempo.mes +=fecha[i];
                    if(fecha[i+1]=='-'){
                        i +=2;
                        break;
                    }
                    ++i;
                }
                
                if(stoi(tiempo.mes)>12 || stoi(tiempo.mes)<1){
                    cout << "Month value is invalid:" << tiempo.mes << endl;
                    return 0;
                }

                while(i<fecha.size()){
                    tiempo.dia +=fecha[i];
                    ++i;
                }
                
                if(stoi(tiempo.dia)>31 || stoi(tiempo.dia)<1){
                    cout << "Day value is invalid: " << tiempo.dia << endl;
                    return 0;
                }
            }

        }else{
            cout << "Unknown command: " << comando << endl;
            return 0;
        }

        if(comando =="Add" || comando == "Del"){
                cin >> evento;
        }

    base_datos_principal(comando, tiempo, evento, base_datos);
    }while(control>=0);


    return 0;
}
