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

                dividir_fecha(ano, mes, dia, fecha);

                cout <<ano << mes << dia << endl;
                //Verificando contenido de ano, mes, dia
                int contador_error_ano=0;
                for(int i=0; i<ano.size(); ++i){
                    if(ano[i]=='-' || ano[i]=='+'){
                        ++contador_error_ano;
                    }
                    if(ano[i]>'9' || ano[i]<'0' && ano[i] !='+' && ano[i] !='-'|| contador_error_ano >1){
                        cout << "Wrong Date Format: " << fecha << endl;
                        return 0;
                    }
                }
                int contador_error_mes=0;
                for(int i=0; i<mes.size(); ++i){
                    if(mes[i]=='+'|| mes[i]=='-'){
                        ++contador_error_mes;
                    }
                    if(mes[i]>'9' || mes[i]<'0' && mes[i] !='+' && mes[i] !='-' || contador_error_mes >1){
                        cout << "Wrong Date Format: " << fecha << endl;
                        return 0;
                    }
                }
                int contador_error_dia=0;
                for(int i=0; i<dia.size(); ++i){
                    if(dia[i]=='+'|| ano[i]=='-'){
                        ++contador_error_dia;
                    }
                    if(dia[i]>'9' || dia[i]<'0' && dia[i] !='+' && dia[i] !='-'  || contador_error_dia >1){
                        cout << "Wrong Date Format: " << fecha << endl;
                        return 0;
                    }
                }

                //Verificando errores de entrada mes y dia y transformando
                if(stoi(ano)>9999 || stoi(ano)<-9999){
                    cout << "Wrong Date Format: " << fecha << endl;
                    return 0;
                }
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
