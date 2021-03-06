//
// Created by lufe0 on 7/05/2021.
//

#include "Controller.h"
#include "../Model/Mayor13.h"
#include "../Model/DosColores.h"
#include "../Model/DosDados.h"
#include "../Model/CajaMisteriosa.h"

Controller::Controller() {
  this->casino = Casino();
  // Se agregan los juegos disponibles para el casino
  Mayor13 * juego1 = new Mayor13();
  DosColores * juego2 = new DosColores();
  DosDados * juego3 = new DosDados();
  CajaMisteriosa * juego4 = new CajaMisteriosa();
  casino.agregarJuego(juego1);
  casino.agregarJuego(juego2);
  casino.agregarJuego(juego3);
  casino.agregarJuego(juego4);

}
void Controller::agregarJugador(long id, string nombreJugador, double dinero)
{
    // Se agrega jugador solo si no existe con anticipacion
    if (casino.verExisteJugador(id) == false){
        // Se convierte el dinero a Gonzos
        float cantGonzos = casino.convertirPesosAGonzos(dinero);
        Jugador * pJugador = new Jugador (id, nombreJugador, cantGonzos);
        casino.agregarJugador(pJugador);

    }else {
        throw std::domain_error("El jugador con la identificacion recibida ya existe\n");
    }
}

bool Controller::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > casino.consultarJuegos().size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    // Si no hay errores se inicia el juego
    int posJuego = idJuego -1; // Se corrige la posicion para acceder al juego
    Juego * pJuegoAJugar = casino.consultarJuegos().at(idJuego-1);
    Jugador *pJugador = casino.consultarJugador(idJugador);

    // Consutlta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    float resultado = pJuegoAJugar->jugar(gonzosApostar);


    // Actualiza el saldo del jugador con el resultado
    pJugador->actualizarGonzos(resultado);

    // Actualiza la cantidad de juegos jugados
    pJugador->aumentarJuegos();

    // Retorna verdadero si el jugador gan?? y false si el jugador perdio
    if (resultado < 0 ){
        return false;
    }
    return true;
}

void Controller::verInfoJugador(long idJugador){
    // En teor??a esta excepci??n no deber??a salir nunca pero se pone como t??ctica de programaci??n segura.
    if (casino.verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador * pJugador = casino.consultarJugador(idJugador);
    pJugador->mostrarInfo();
}

bool Controller::verPuedeContinuar(int idJugador) {
    // En teor??a esta excepci??n no deber??a salir nunca pero se pone como t??ctica de programaci??n segura.
    if (casino.verExisteJugador(idJugador) == false) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() == 0) {
        return false;
    }
    return true;
}

void Controller::retirarJugador(long idJugador) {
    casino.retirarJugador(idJugador);
    cout << "Se retiro el jugador \n";
}

void Controller::recargarGonzos(long idJugador, float cantGonzos) {
    Jugador * pJugador = casino.consultarJugador(idJugador);
    pJugador->actualizarGonzos(cantGonzos);
}

void Controller::venderGonzos(long idJugador, float cantGonzos) {
    Jugador *pJugador = casino.consultarJugador(idJugador);
    float resultPesos = casino.convertirGonzosPesos(cantGonzos);
    cantGonzos *= -1;
    pJugador->actualizarGonzos(cantGonzos);
}

