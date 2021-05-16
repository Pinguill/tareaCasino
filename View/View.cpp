//
// Created by lufe0 on 7/05/2021.
//

#include "View.h"

View::View(){
    controller = Controller();
}
void View::agregarJugador()
{
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    cout << "Ingrese el id del jugador \n";
    cin >> idJugador;
    // Validacion de los datos del jugador
    do
    {
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        controller.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}


void View::pedirUsuario(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);

        // LLama a la función que hacer toda la logica de jugar.
        jugarView(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View:: jugarView(long idJugador) {
    int opc;
    float cantGonzos;
    int idJuego;
    do{
        try {
            do {
                cout << "Cuantos gonzos desea apostar \n";
                cin >> cantGonzos;
            } while (cantGonzos <= 0);

            // Agregue el esto de la logica para el juego 1. Juego mayor a 13, 2 juego de dos colores.
            do {
                cout << "Que juego quiere jugar?\n1. Juego mayor a 13\n2. Juego de dos colores\n3. Juego de dos dados\n4. Juego Caja misteriosa\n0. Salir\n";
                cin >> opc;
                if (opc != 0){
                    if (controller.jugar(opc, idJugador, cantGonzos) == false){
                        cout << "Perdio\n";
                    }else {
                        cout << "Gano\n";
                    }
                }
            } while (opc != 0);
        } catch (std::domain_error ex){
            cout << ex.what();
        }
    }while (opc!=0);
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador" << std::endl;
    cout << "4. Vender gonzos" << std::endl;
    cout << "5. Recargar gonzos" << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
            case 1: agregarJugador();
                break;
            case 2:
                pedirUsuario();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                venderGonzos();
                break;
            case 5:
                recargarGonzos();
                break;
        }
    } while (opcion != 0);
}

void View::mostrarJugador() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador que quiere mostrar:\n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::retirarJugador() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador que quiere retirar:\n";
        cin >> idJugador;
        controller.retirarJugador(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::venderGonzos(){
    try {
        long idJugador;
        float cantGonzos;
        cout << "Ingrese el id del jugador que quiere cambiar los gonzos:\n";
        cin >> idJugador;
        cout << "Ingrese la cantidad de gonzos a cambiar:\n";
        cin >> cantGonzos;
        controller.venderGonzos(idJugador, cantGonzos);


    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::recargarGonzos() {
    try {
        long idJugador;
        float cantGonzos;
        cout << "Ingrese el id del jugador que quiere recargar los gonzos:\n";
        cin >> idJugador;
        cout << "Ingrese la cantidad de gonzos a recargar:\n";
        cin >> cantGonzos;
        controller.recargarGonzos(idJugador, cantGonzos);


    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}
