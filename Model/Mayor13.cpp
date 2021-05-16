//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    int opc;
    srand(time(NULL));
    numeroJugador = 1+rand()%14;// numeros de 1 a 13
    cout << "Su numero es: " << numeroJugador << "\n";
    cout << "Desea continuar:\n1. Si\n2. No\n";
    cin >> opc;
    if (opc == 1){
        numeroCasino = 1+rand()%14;// numeros de 1 a 13
        float gonzoResultado = calcularResultado(gonzosApostar);
        return gonzoResultado;
    }
    return gonzosApostar = gonzosApostar / 2;
}


float Mayor13::calcularResultado(float gonzosApostar) {
    if (numeroJugador > numeroCasino){
        gonzosApostar = gonzosApostar * 2;
        return gonzosApostar;
    }
    if (numeroJugador < numeroCasino){
        gonzosApostar = gonzosApostar * -1;
        return gonzosApostar;
    }
}

Mayor13::~Mayor13() {

}
