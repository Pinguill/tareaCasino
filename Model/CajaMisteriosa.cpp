#include "CajaMisteriosa.h"

float CajaMisteriosa::jugar( float gonzosApostar )
{
    // 
    int bandera = 0;
    float resultadoJuego;

    srand( time( NULL ) );
    cout << "Elije una caja: " << std::endl;
    cout << "1. Caja 1\n2. Caja 2\n3. Caja 3" << std::endl;
    cout << " ";

    // Control para verificar que la opción del jugador esté correcta
    while( bandera == 0 ) {
        // Se verifica que el jugador ingrese un valor numérico
        while( !( cin >> eleccionJugador ) ){
            cout << "\nPor favor ingrese un valor numerico: ";
            cin.clear();
            cin.ignore( std::numeric_limits< std::streamsize > ::max(), '\n' );
        }
        
        // Se verifica que el número ingresado esté entre el rango de 1 a 3
        if( eleccionJugador < 1 || eleccionJugador > 3 ){
            cout << "\n\tValor invalido, intente de nuevo" << endl;
            cout << endl;
        }else{
            bandera = 1;
        }
    }

    eleccionCasino = 1+rand()%4; // Almacena el premio
    
    cout << "\nHas elegido la Caja #" << eleccionJugador << "\n";
    cout << "\nLa caja con el premio esta en la #"  << eleccionCasino << "\n";
    resultadoJuego = calcularResultado( gonzosApostar );
    return resultadoJuego;

}

float CajaMisteriosa::calcularResultado( float gonzoApostar )
{
    // Si acierta, gana 5 veces lo apostado
    if( eleccionJugador == eleccionCasino )
    {
        gonzoApostar *= 5; 
    }
    // Si se equivoca de caja, pierde 2 veces lo apostado
    else{
        gonzoApostar *= -2;
    }
    return gonzoApostar;
}

CajaMisteriosa::~CajaMisteriosa(){
}