//
// Created by lufe0 on 7/05/2021.
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout <<"Inicialice casino";
    jugadoresMap.clear(); // Se limpian los jugadores del casino
}


void Casino::agregarJuego(Juego * juego) {
    juegosDisponibles.push_back(juego);
}



void Casino::agregarJugador(Jugador *pJugador) {
    // Se agrega el jugador al mapa de jugadores del casino
    jugadoresMap[pJugador->getId()] = pJugador;
}

bool Casino::verExisteJugador(long id) {
    if (jugadoresMap[id] == NULL){
        return false;
    }
    return true;
}

Jugador *Casino::consultarJugador(long id) {
    return jugadoresMap[id]; // Retora el apuntador a jugador.
}

double Casino::convertirPesosAGonzos(double dinero) {
    // Cada 10 mil pesos equivalen a 100 Gonzos
    double valorGonzos = dinero / 100;
    return valorGonzos;
}

vector<Juego *> &Casino::consultarJuegos() {
    return juegosDisponibles;
}

void Casino::retirarJugador(long id) {
    Jugador *pJugador = jugadoresMap[id];
    jugadoresMap.erase(id);
    pJugador->~Jugador();
}


double Casino::convertirGonzosPesos(float gonzos) {
    double resultado = gonzos * 100;
    cout << "Se convirtieron sus gonzos a pesos\n";
    return resultado;
}

Casino::~Casino() {

}