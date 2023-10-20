#include <iostream>
#include "funciones.h"
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
    const int cantidad_repartida = 5;
    const int caras_dado = 6;

    int opcion;
    int dado_j1, dado_j2;
    string nombre_j1, nombre_j2, INICIA_PARTIDA, carta_repetida;
    string numero_cartas[5] = {"A", "K", "Q", "J", "10"};
    string tipo_palo[4] = {"trebol", "corazon", "pica", "diamante"};
    string corral_j1[cantidad_repartida][2], corral_j2[cantidad_repartida][2];
    string mazo [5][4];
    bool cartas_usando [5][4]={false}; //esta matriz nos sirve para no repetir carta

    srand(time(NULL));

    do {
        cout << "CLUTCH" << endl;
        cout << "--------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "----------------" << endl;
        cout << "0 - SALIR" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                elegir_nombres(nombre_j1, nombre_j2);
                cout << "Los nombres son " << nombre_j1 << " y " << nombre_j2 << endl;
                cout << "CLUTCH" << endl;
                cout << "------------------------------------------------------------------------" << endl;

                cargar_mazo(mazo, numero_cartas, tipo_palo);
                repartir_cartas_j1(cartas_usando, nombre_j1, corral_j1, cantidad_repartida, numero_cartas, tipo_palo);
                cout << endl;
                repartir_cartas_j2(cartas_usando, nombre_j2, corral_j2, cantidad_repartida, numero_cartas, tipo_palo);
                cout << endl;
                empieza_primero(corral_j1, corral_j2, numero_cartas, nombre_j1, nombre_j2, INICIA_PARTIDA, carta_repetida);
                cout << "El jugador " << INICIA_PARTIDA << " será el primero en tirar el dado" << endl;

                if (INICIA_PARTIDA == nombre_j1) {
                    dado_j1 = lanzar_dado();
                    cout << "El jugador " << nombre_j1 << " sacó un " << dado_j1 << endl;
                } else {
                    dado_j2 = lanzar_dado();
                    cout << "El jugador " << nombre_j2 << " sacó un " << dado_j2 << endl;
                }

                break;
            case 2:

                break;
            case 3:

                break;
            default:
                cout << "------------------------------------------------------------------------" << endl;
                cout << "      OPCION INCORRECTA, ELIJA NUEVAMENTE ENTRE ESAS TRES OPCIONES" << endl;
                cout << "------------------------------------------------------------------------" << endl;
        }

    } while (opcion != 0);

    return 0;
}
//----------------------------------------------funciones-------------------------------------------

