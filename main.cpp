#include "header.h"
#include <iostream>
int main(){
    int i=0;
    map<int, string> base_datos;
    do{
        string comando;
        string fecha;
        string evento;
        cout << "Ingrese comando y argumentos designados" << endl;
        cin >> comando;
        if(comando != "Print"){
            cin >> fecha;
        }
        if(comando =="Add" || comando == "Del"){
            cin >> evento;
        }
    }while(i>=0);


    return 0;
}
