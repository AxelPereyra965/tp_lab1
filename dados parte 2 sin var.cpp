#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Declaraci�n de funciones
void cargar_mazo(string mazo[][4], string numero_cartas[5], string tipo_palo[4]);
void OPCION_DADO_1(string mazo[][4], string numero_cartas[5], string tipo_palo[4], string corral_j1[5][2], string corral_j2 [5][2], bool cartas_usando [5][4], string J1_O_J2, string nombre_j1, string nombre_j2);
void elegir_nombres(string &nombre_j1, string &nombre_j2);
string numero_aleatorio(string numero_cartas[5]);
string palo_aleatorio(string tipo_palo[4]);
void repartir_cartas_j1(bool (&cartas_usando)[5][4], string nombre_j1, string corral_j1[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);
void repartir_cartas_j2(bool (&cartas_usando)[5][4], string nombre_j2, string corral_j2[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);
void empieza_primero(string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &nombre_j1, string &nombre_j2, string &INICIA_PARTIDA, string &carta_repetida);
int lanzar_dado(const int caras_dado = 6);

int main()
{
    const int cantidad_repartida = 5;
    const int caras_dado = 6;

    int opcion;
    int dado_j1, dado_j2;
    string nombre_j1, nombre_j2, INICIA_PARTIDA, J1_O_J2, carta_repetida;
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
                cout << "El jugador " << INICIA_PARTIDA << " ser� el primero en tirar el dado" << endl;

                if (INICIA_PARTIDA == nombre_j1) {
                    dado_j1 = lanzar_dado();
                    cout << "El jugador " << nombre_j1 << " sac� un " << dado_j1 << endl;
                    J1_O_J2 = nombre_j1;  
                    dado_j1 = 1;     ///CAMBIAR UNO POR VARIABLE QUE SIGA POR EL DADO
                    if(dado_j1 == 1){
                        OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, J1_O_J2, nombre_j1, nombre_j2);
                    }if(dado_j1 == 2){
                        OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, J1_O_J2, nombre_j1, nombre_j2);
                    }
                } else {
                    dado_j2 = lanzar_dado();
                    cout << "El jugador " << nombre_j2 << " sac� un " << dado_j2 << endl;
                    J1_O_J2 = nombre_j2;
                    dado_j2 = 1;     ///CAMBIAR UNO POR VARIABLE QUE SIGA POR EL DADO
                    if(dado_j2 == 1){
                        OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, J1_O_J2, nombre_j1, nombre_j2);
                    }
                    if(dado_j2 == 2){
                        OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, J1_O_J2, nombre_j1, nombre_j2);
                    }
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

// Funcion para obtener un n�mero de carta aleatorio
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

void OPCION_DADO_1(string mazo[][4], string numero_cartas[5], string tipo_palo[4], string corral_j1[5][2], string corral_j2 [5][2], bool cartas_usando [5][4], string J1_O_J2, string nombre_j1, string nombre_j2){
    int CARTA = 0, NEW_NUM = 0, NEW_PALO;
    bool CORTE_CAMBIO_CARTA = false;
    string CARTA_INTERCAMBIADA_NUMERO, CARTA_INTERCAMBIADA_PALO, CARTA_ACTUAL, PALO_ACTUAL;

    cout << endl;
    cout << "OPCION #1: EL JUGADOR " << J1_O_J2 << " PODRA INTERCAMBIAR UNA CARTA DE SU CORRAL POR UNA DEL MAZO, SUERTE!!" << endl;
    cout << "===================================================================================================" << endl;

    if(J1_O_J2 == nombre_j1){
    cout << "   SELECCION DE CARTAS PARA INTERCAMBIO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl; ///MAZO ANTES DE CAMBIO DE CARTA
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;
    CARTA_INTERCAMBIADA_NUMERO = corral_j1[CARTA - 1][0];
    CARTA_INTERCAMBIADA_PALO = corral_j1[CARTA - 1][1];

    for(int x = 0 ; x < 5 ; x ++){

        for(int y = 0 ; y < 4 ; y ++){
            if(corral_j1[CARTA - 1][0] == mazo[x][y]){
                cartas_usando[x][y] = false;
            }
        }
    }
    while(CORTE_CAMBIO_CARTA != true){
        NEW_NUM = rand() % 5;
        NEW_PALO = rand() % 4;
        if(cartas_usando [NEW_NUM][NEW_PALO] == false){
            corral_j1 [CARTA - 1][0] = numero_cartas[NEW_NUM - 1];
            corral_j1 [CARTA - 1][1] = tipo_palo[NEW_PALO - 1];
            CARTA_ACTUAL = numero_cartas[NEW_NUM - 1]; ///VARIABLES PARA PODER MOSTRARLO EN EL COUT, YA QUE NO PUEDO MOSTRAR LA MATRIZ DEL CORRAL DIRECTAMENTE
            PALO_ACTUAL = tipo_palo [NEW_PALO - 1];
            CORTE_CAMBIO_CARTA = true;
        }
    }
    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
    cout << "   MAZO ACTUAL DEL JUGADOR " << J1_O_J2 << endl;
    cout << "-----------------------------------------" << endl;
    cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
    cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl; ///MAZO DESPUES DE CAMBIAR CARTA
    cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl;
    cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
    cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
    cout << "------------------------------------------" << endl;
////////////HASTA ACA LA OPCION J1, AHORA EMPIEZA LA OPCION DEL J2/////////////////////////////
    }else if(J1_O_J2 == nombre_j2){
    cout << "   SELECCION DE CARTAS PARA INTERCAMBIO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
    cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
    cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl;
    cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
    cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;
    CARTA_INTERCAMBIADA_NUMERO = corral_j2[CARTA - 1][0];
    CARTA_INTERCAMBIADA_PALO = corral_j2[CARTA - 1][1];

    for(int x = 0 ; x < 5 ; x ++){

        for(int y = 0 ; y < 4 ; y ++){
            if(corral_j2[CARTA - 1][0] == mazo[x][y]){
                cartas_usando[x][y] = false;
            }
        }
    }

    while(CORTE_CAMBIO_CARTA != true){
        NEW_NUM = rand() % 5;
        NEW_PALO = rand() % 4;
        if(cartas_usando [NEW_NUM][NEW_PALO] == false){
            corral_j2 [CARTA - 1][0] = numero_cartas[NEW_NUM - 1];
            corral_j2 [CARTA - 1][1] = tipo_palo[NEW_PALO - 1];
            CARTA_ACTUAL = numero_cartas[NEW_NUM - 1];
            PALO_ACTUAL = tipo_palo [NEW_PALO - 1];
            CORTE_CAMBIO_CARTA = true;
        }
    }
    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
    cout << "   MAZO ACTUAL DEL JUGADOR " << J1_O_J2 << endl;
    cout << "-----------------------------------------" << endl;
    cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
    cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
    cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl;
    cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
    cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    }
}

void OPCION_DADO_2(string mazo[][4], string numero_cartas[], string tipo_palo[], string corral_j1[5][2], string corral_j2 [5][2], bool cartas_usando [5][4], string J1_O_J2, string nombre_j1, string nombre_j2){
    int CARTA , NEW_NUM , NEW_PALO;
    bool CORTE_CAMBIO_CARTA = false;
    string CARTA_INTERCAMBIADA_NUMERO, CARTA_INTERCAMBIADA_PALO, CARTA_ACTUAL, PALO_ACTUAL;

    cout << endl;
    cout << "OPCION #1: EL JUGADOR " << J1_O_J2 << " PODRA INTERCAMBIAR UNA CARTA DEL CORRAL CONTRARIO POR UNA DEL MAZO, SUERTE!!" << endl;
    cout << "===================================================================================================" << endl;

    if(J1_O_J2 == nombre_j1){
    cout << "   SELECCION DE CARTAS PARA INTERCAMBIO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
    cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
    cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl; ///MAZO ANTES DE CAMBIO DE CARTA
    cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
    cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;
    CARTA_INTERCAMBIADA_NUMERO = corral_j2[CARTA - 1][0];
    CARTA_INTERCAMBIADA_PALO = corral_j2[CARTA - 1][1];

    while(CORTE_CAMBIO_CARTA != true){
        NEW_NUM = rand() % 5;
        NEW_PALO = rand() % 4;
        if(cartas_usando [NEW_NUM][NEW_PALO] == false){
            corral_j2 [CARTA - 1][0] = numero_cartas[NEW_NUM - 1];
            corral_j2 [CARTA - 1][1] = tipo_palo[NEW_PALO - 1];
            CARTA_ACTUAL = numero_cartas[NEW_NUM - 1]; 
            PALO_ACTUAL = tipo_palo [NEW_PALO - 1];
            CORTE_CAMBIO_CARTA = true;
        }
    }
    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
    cout << "   MAZO ACTUAL DEL JUGADOR CONTRARIO" << J1_O_J2 << endl;
    cout << "-----------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl; 
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl;
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;
////////////HASTA ACA LA OPCION J1, AHORA EMPIEZA LA OPCION DEL J2/////////////////////////////
    }else if(J1_O_J2 == nombre_j2){
    cout << "   SELECCION DE CARTAS PARA INTERCAMBIO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl; //
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;
    CARTA_INTERCAMBIADA_NUMERO = corral_j1[CARTA - 1][0];
    CARTA_INTERCAMBIADA_PALO = corral_j1[CARTA - 1][1];


    while(CORTE_CAMBIO_CARTA != true){
        NEW_NUM = rand() % 5;
        NEW_PALO = rand() % 4;
        if(cartas_usando [NEW_NUM][NEW_PALO] == false){
            corral_j1 [CARTA - 1][0] = numero_cartas[NEW_NUM - 1];
            corral_j1 [CARTA - 1][1] = tipo_palo[NEW_PALO - 1];
            CARTA_ACTUAL = numero_cartas[NEW_NUM - 1];
            PALO_ACTUAL = tipo_palo [NEW_PALO - 1];
            CORTE_CAMBIO_CARTA = true;
        }
    }
    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
    cout << "   MAZO ACTUAL DEL JUGADOR CONTRARIO" << J1_O_J2 << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl; 
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    }
}