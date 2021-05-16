//
// Created by lufe0 on 8/05/2021.
//

#ifndef CASINO_DOSDADOS_H
#define CASINO_DOSDADOS_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>


class DosDados: public Juego {

protected:
    int dados;
    int opcElegida;
    float calcularResultado(float gonzosApostar) override;

public:
    float jugar(float gonzosApostar) override;
    virtual ~DosDados();

};


#endif //CASINO_DOSDADOS_H
