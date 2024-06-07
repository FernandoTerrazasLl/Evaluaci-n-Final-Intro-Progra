#include "header.h"

int main(){
    map<string, set<string>> base_datos;
    do{
        string comando, fecha, evento, ano, mes, dia;
        Fechas tiempo;

        cout << "Ingrese comando y argumentos designados" << endl;
        cin >> comando;
        //Verificando si el comando es valido
        
        if(comando=="Add" || comando=="Del" || comando=="Find" || comando=="Print"){
            //Pidiendo fecha
            if(comando != "Print"){
                cin >> fecha;

                //Verificando formato de fecha
                if(((fecha[0]<= '9' && fecha[0]>= '0') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))
                || ((fecha[0]=='-' && fecha[1] !='-') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))
                || ((fecha[0]=='+' && fecha[1] !='+') && (fecha[fecha.size()-1] >= '0' && fecha[fecha.size()-1] <= '9'))){
                }else{
                    cout << "Wrong Date Format: " << fecha << endl;
                    return 0;
                }

                dividir_fecha(ano, mes, dia, fecha);
   
                //Verificando errores de entrada mes y dia y transformando
                if(stoi(mes)>12 || stoi(mes)<1){
                    cout << "Month value is invalid:" << mes << endl;
                    return 0;
                }
                if(stoi(dia)>31 || stoi(dia)<1){
                    cout << "Day value is invalid: " << dia << endl;
                    return 0;
                }

                tiempo.ano = stoi(ano);
                tiempo.mes = stoi(mes);
                tiempo.dia = stoi(dia);
            }
        }else{
            cout << "Unknown command: " << comando << endl;
            return 0;
        }

        //Pidiendo evento y verificando validez
        if(comando =="Add"){
            cin >> evento;
        }else if(comando == "Del"){
            getline(cin, evento);
            if(evento[0]==' '){
                evento.erase(0,1); //Borrando el primer caracter (Suele dar error por espacio extra)
            }
        }
    base_datos_principal(comando, tiempo, evento, base_datos);
    }while(1);

    return 0;
}
