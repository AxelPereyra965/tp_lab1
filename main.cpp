#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Declaración de funciones
void elegir_nombres(string &nombre_j1, string &nombre_j2);
string numero_aleatoreo(string numero_cartas[13]);
string palo_aleatoreo(string tipo_palo[4]);
void repartir_cartasj1(string &nombre_j1, string corral_j1[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);
void repartir_cartasj2(string &nombre_j2, string corral_j2[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);

int main()
{
    const int cantidad_repartida = 5; // la cantidad de cartas repartidas

    int opcion; // se usa en el menú para elegir la opción
    string nombre_j1, nombre_j2;
    string numero_cartas[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string tipo_palo[4] = {"trebol", "corazon", "pica", "diamante"};
    string corral_j1[cantidad_repartida][2], corral_j2[cantidad_repartida][2]; // las 5 cartas que les toquen a cada uno, cada carta tiene número y palo

    srand(time(0));

    do {
        cout << "GLUTCH" << endl;
        cout << "--------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "----------------" << endl;
        cout << "0 - SALIR" << endl;
        cin >> opcion;

        if (opcion == 1) // dentro de este if se va a desarrollar el juego
        {
            elegir_nombres(nombre_j1, nombre_j2); // al pasar por referencia no hace falta asignar porque la función ya lo hace
            cout << "Los nombres son " << nombre_j1 << " y " << nombre_j2 << endl;

            cout << "CLUTCH" << endl;
            cout << "------------------------------------------------------------------------" << endl;

            repartir_cartasj1(nombre_j1, corral_j1, cantidad_repartida, numero_cartas, tipo_palo);
            repartir_cartasj2(nombre_j2, corral_j2, cantidad_repartida, numero_cartas, tipo_palo);

            cout<<endl;//despues sacar esto
            cout<<"esto lo pongo para verificar si se cargaron bien los corrales este es el del j1"<<endl;

            for(int x=0;x<cantidad_repartida;x++)
            {
                for(int i=0;i<2;i++)
                {
                    cout<<corral_j1[x][i]<<"  ";
                }
                cout<<endl;
            }
        }

    } while (opcion != 0);

    return 0;
}

// Función para elegir los nombres
void elegir_nombres(string &nombre_j1, string &nombre_j2)
{
    char confirmacion;

    do {
        cout << "CLUTCH" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << endl;
        cout << "Jugador 1 ingrese su nombre: " << endl;
        cin >> nombre_j1;
        cout << "Jugador 2 ingrese su nombre: " << endl;
        cin >> nombre_j2;
        cout << "¿Confirmar nombres? (S/N)" << endl;
        cin >> confirmacion;

        cout << "------------------------------------------------------------------------" << endl;
    } while (confirmacion != 's');
}

// Función para que tire el número de una carta aleatoriamente
string numero_aleatoreo(string numero_cartas[13])
{
    return numero_cartas[rand() % 13];
}

// Función para que tire el palo de una carta aleatoriamente
string palo_aleatoreo(string tipo_palo[4])
{
    return tipo_palo[rand() % 4];
}


//funcion para repartir las cartas al j1 y guardarlas en su corral
void repartir_cartasj1(string &nombre_j1, string corral_j1[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[])
{
    cout << "Cartas repartidas para el jugador " << nombre_j1 << endl;

    for (int x = 0; x < cantidad_repartida; x++)
    {
        corral_j1[x][0] = numero_aleatoreo(numero_cartas); // carga el Número de carta al corral
        corral_j1[x][1] = palo_aleatoreo(tipo_palo);      // carga el Palo al corral
        cout << corral_j1[x][0] << " " << corral_j1[x][1] << endl;//esto es para mostrar
    }
}


//funcion para repartir las cartas al j2 y guardarlas en su corral

void repartir_cartasj2(string &nombre_j2, string corral_j2[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[])
{
    cout << "Cartas repartidas para el jugador " << nombre_j2 << endl;

    for (int x = 0; x < cantidad_repartida; x++)
    {
        corral_j2[x][0] = numero_aleatoreo(numero_cartas); // carga el Número de carta al corral
        corral_j2[x][1] = palo_aleatoreo(tipo_palo);      // carga el Palo al corral
        cout << corral_j2[x][0] << " " << corral_j2[x][1] << endl;//esto es para mostrar
    }
}

