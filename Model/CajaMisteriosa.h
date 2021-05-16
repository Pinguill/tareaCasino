#ifndef CASINO_CAJAMISTERIOSA_H
#define CASINO_CAJAMISTERIOSA_H

#include "Juego.h"
#include <ctime>
#include<cstdlib>
#include <algorithm>
#include <cctype>
#include <fstream>


class CajaMisteriosa:public Juego{
    protected:
        int eleccionJugador;
        int eleccionCasino;
        float calcularResultado( float gonzosApostar ) override;
    public:
        float jugar( float gonzosApostar ) override;
        virtual ~CajaMisteriosa();
};

#endif 