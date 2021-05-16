//
// Created by lufe0 on 8/05/2021.
//

#include "DosDados.h"

float DosDados::jugar(float gonzosApostar) {
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    dados = 1+rand()%13;// numeros de 1 a 13
    cout << "Que saldra par o impar:\n1. Par\n2. Impar\n";
    cin >> opcElegida;
    cout << "El valor de los dados es de: "<< dados << "\n";
    float gonzosResulado = calcularResultado(gonzosApostar);
    return gonzosResulado;
}

float DosDados::calcularResultado(float gonzosApostar) {
    // si el valor de los dados es par y dice par gana x2
    if ( dados % 2 == 0 ){
        if (opcElegida == 1){
            gonzosApostar *= 2;
            return gonzosApostar;
        }
    }
    // si el valor de los dados es impar y dice impar gana x2
    if (dados % 2 == 1){
        if (opcElegida == 2){
            gonzosApostar *= 2;
            return gonzosApostar;
        }
    }
    return gonzosApostar *= -1;
}

DosDados::~DosDados() {

}
