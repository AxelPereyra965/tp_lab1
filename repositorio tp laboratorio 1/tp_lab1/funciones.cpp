#include "funciones.h"
#include <iostream>
using namespace std;

// Funcion para cargar el mazo de cartas
void cargar_mazo(string mazo[][4], string numero_cartas[5], string tipo_palo[4])
{
    for (int x = 0; x < 5; x++) {
        for (int i = 0; i < 4; i++) {
            mazo[x][i] = numero_cartas[x] + " " + tipo_palo[i];
        }
    }
}

// Funcion para que los jugadores elijan sus nombres
void elegir_nombres(string &nombre_j1, string &nombre_j2)
{
    char confirmacion;
    bool CONFIRMAR_NOMBRE = false;

    do {
        cout << "CLUTCH" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << endl;
        cout << "Jugador 1 ingrese su nombre: " << endl;
        cin >> nombre_j1;
        cout << "Jugador 2 ingrese su nombre: " << endl;
        cin >> nombre_j2;
        cout << "Pulse 'S' PARA CONFIRMAR" << endl;
        cin >> confirmacion;
        if (confirmacion == 's' || confirmacion == 'S') {
            CONFIRMAR_NOMBRE = true;
            cout << "------------------------------------------------------------------------" << endl;
        } else {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "           POR FAVOR, PULSE LA TECLA 'S' PARA CONTINUAR" << endl;
            cout << "------------------------------------------------------------------------" << endl;
        }

    } while (CONFIRMAR_NOMBRE != true);
}

// Funcion para obtener un número de carta aleatorio
string numero_aleatorio(string numero_cartas[5])
{
    return numero_cartas[rand() % 5];
}

// Funcion para obtener un palo de carta aleatorio
string palo_aleatorio(string tipo_palo[4])
{
    return tipo_palo[rand() % 4];
}

// Funcion para repartir cartas al jugador 1
void repartir_cartas_j1(bool (&cartas_usando)[5][4], string nombre_j1, string corral_j1[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[])
{
    bool bandera;

    cout << "Cartas repartidas para el jugador " << nombre_j1 << endl;

    for (int x = 0; x < cantidad_repartida; x++) //este for es para que reparta 5 cartas
    {
       bandera = false;
       while(bandera!=true)
       {
           int numero = rand() % 5;
           int palo = rand() % 4;

           if(cartas_usando[numero][palo]==false)
           {
               //x es el numero de la carta
               corral_j1[x][0]=numero_cartas[numero]; //en la posicion 0 guardo el numero de carta
               corral_j1[x][1]=tipo_palo[palo]; //en la posicion 1 el palo de esa carta
               cartas_usando[numero][palo]=true;
               bandera=true;
           }
        }

        cout << corral_j1[x][0] << " " << corral_j1[x][1] << endl;
    }

}

// Funcion para repartir cartas al jugador 2
void repartir_cartas_j2(bool (&cartas_usando)[5][4], string nombre_j2, string corral_j2[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[])
{
    bool bandera;


    cout << "Cartas repartidas para el jugador " << nombre_j2 << endl;

    for (int x = 0; x < cantidad_repartida; x++) //este for es para que reparta 5 cartas
    {
       bandera = false;
       while(bandera!=true)
       {
           int numero = rand() % 5;
           int palo = rand() % 4;

           if(cartas_usando[numero][palo]==false)
           {
               //x es el numero de la carta
               corral_j2[x][0]=numero_cartas[numero]; //en la posicion 0 guardo el numero de carta
               corral_j2[x][1]=tipo_palo[palo]; //en la posicion 1 el palo de esa carta
               cartas_usando[numero][palo]=true;
               bandera=true;
           }
        }

        cout << corral_j2[x][0] << " " << corral_j2[x][1] << endl;
    }
}

// Funcion para decidir quien empieza primero
void empieza_primero(string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &nombre_j1, string &nombre_j2, string &INICIA_PARTIDA, string &carta_repetida)
{
    bool BANDERA_PRIMERIZO = false;
    int I = 0, CONT_J1, CONT_J2;

    while (BANDERA_PRIMERIZO != true) {
        CONT_J1 = CONT_J2 = 0;

        for (int x = 0; x < 5; x++) {
            if (corral_j1[x][0] == numero_cartas[I]) {
                CONT_J1++;
            }
            if (corral_j2[x][0] == numero_cartas[I]) {
                CONT_J2++;
            }
        }
        if (CONT_J1 > CONT_J2) {
            INICIA_PARTIDA = nombre_j1;
            BANDERA_PRIMERIZO = true;
            carta_repetida = numero_cartas[I];
        } else if (CONT_J2 > CONT_J1) {
            INICIA_PARTIDA = nombre_j2;
            BANDERA_PRIMERIZO = true;
            carta_repetida = numero_cartas[I];
        } else {
            I++;
        }
    }
}

// Funcion para lanzar un dado aleatorio
int lanzar_dado(const int caras_dado)
{
    return rand() % caras_dado + 1;
}
