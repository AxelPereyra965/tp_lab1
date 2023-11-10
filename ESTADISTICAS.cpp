#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>


using namespace std;

// Declaración de funciones
void cargar_mazo(string mazo[][4], string numero_cartas[5], string tipo_palo[4]);
void elegir_nombres(string &nombre_j1, string&nombre_j2);
void repartir_cartas_j1(bool (&cartas_usando)[5][4], string nombre_j1, string corral_j1[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[], bool cartas_usando_j1 [5][2]);
void repartir_cartas_j2(bool (&cartas_usando)[5][4], string nombre_j2, string corral_j2[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[], bool cartas_usando_j2 [5][2]);
void empieza_primero(string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &nombre_j1, string &nombre_j2, string &INICIA_PARTIDA, string &carta_repetida);
void verificar_ganador(bool &B_CORTE_JUEGO, string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &lanzo_dado, string nombre_j1, string nombre_j2, string &nombre_ganador, int &ganar_partida, int &ganar_dado3, int &carta_mal_ubicada, bool &ganar_sin_sufrir_robo_j1, bool &ganar_sin_sufrir_robo_j2, int &ganar_sin_robo, bool &bandera_sin_pasar_deturnoj1, bool &bandera_sin_pasar_deturnoj2, int &ganar_sin_pasarturno);
bool comparar_cartas(string (&corral_j1)[5][2], string (&corral_j2)[5][2]);
void mostrar_ambos_corrales(string corral_j1[][2], string corral_j2[][2], string nombre_j1, string nombre_j2);
int lanzar_dado(const int caras_dado = 6);
//FUNCIONES DE OPCIONES DEL DADO
void OPCION_DADO_1(string (&mazo)[5][4], string numero_cartas[5], string tipo_palo[4], string (&corral_j1)[5][2], string (&corral_j2) [5][2], bool (&cartas_usando) [5][4], string &lanzo_dado, string nombre_j1, string nombre_j2);
void OPCION_DADO_2(string (&mazo)[5][4], string numero_cartas[5], string tipo_palo[4], string (&corral_j1)[5][2], string (&corral_j2) [5][2], bool (&cartas_usando) [5][4], string &lanzo_dado, string nombre_j1, string nombre_j2, bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2]);
void OPCION_DADO_3(string (&corral_j1)[5][2], string (&corral_j2)[5][2], string &lanzo_dado, string nombre_j1, string nombre_j2, bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2],bool &ganar_sin_sufrir_robo_j1, bool &ganar_sin_sufrir_robo_j2, bool &B_JUGADOR_BLOQUEADOR1, bool &B_JUGADOR_BLOQUEADOR2);
void OPCION_DADO_4(string (&corral_j1)[5][2], string (&corral_j2)[5][2], string &lanzo_dado, string nombre_j1, string nombre_j2 , bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2) [ 5][2] );
void OPcion_DADO_5(string (&corral_j1)[5][2], string (&corral_j2)[5][2], string &lanzo_dado, string nombre_j1, string nombre_j2, bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2], int cantidad_repartida, bool &B_JUGADOR_BLOQUEADOR1, bool &B_JUGADOR_BLOQUEADOR2, int &CONT_BLOQUEADAS1, int &CONT_BLOQUEADAS2);
void OPCION_DADO_6(string &lanzo_dado,string nombre_j1, string nombre_j2, string (&mazo)[5][4], string numero_cartas[5], string tipo_palo[4], string (&corral_j1)[5][2], string (&corral_j2) [5][2], bool (&cartas_usando) [5][4],bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2], int cantidad_repartida, bool &ganar_sin_sufrir_robo_j1, bool &ganar_sin_sufrir_robo_j2, bool &bandera_sin_pasar_deturnoj1, bool &bandera_sin_pasar_deturnoj2, bool &B_JUGADOR_BLOQUEADOR1, bool &B_JUGADOR_BLOQUEADOR2, int &CONT_BLOQUEADAS1, int &CONT_BLOQUEADAS2);
int main()
{
    const int cantidad_repartida = 5;
    const int caras_dado = 6;

    int opcion;
    int RONDAS = 1;
    int dado_j1, dado_j2;
    int ganar_partida=0;// aca se almacena el puntaje de ganar partida
    int ganar_dado3=0; // aca se almacena el puntaje por haber ganado con el dado 3
    int carta_mal_ubicada=0; // aca se almacena el puntaje de cartas mal ubicadas del jugador contrario
    int ganar_sin_robo=0;
    int ganar_sin_pasarturno=0; // aca almacena el puntaje de ganar sin pasar turno
    int CONT_BLOQUEADAS1 = 0; //contador de cartas bloqueadas para el jugador 1
    int CONT_BLOQUEADAS2 = 0; //contador de cartas bloqueadas para el jugador 2
    string nombre_j1, nombre_j2, INICIA_PARTIDA, carta_repetida;
    string numero_cartas[5] = {"10", "J", "Q", "K", "A"};
    string tipo_palo[4] = {"trebol", "corazon", "pica", "diamante"};
    string corral_j1[cantidad_repartida][2], corral_j2[cantidad_repartida][2];
    string mazo [5][4];
    string lanzo_dado; //nos sirve para saber a quien le toca lanzar
    string nombre_ganador; // aca se almacena el nombre del jugador que gane la partida
    bool B_CORTE_JUEGO = false; ///sirve para cortar cuando un jugador haya ganado
    bool cartas_bloqueadas_j1[cantidad_repartida][2]={false};
    bool cartas_bloqueadas_j2[cantidad_repartida][2]={false};//nos sirven para saber que carta esta bloqueada (cara 5 del dado)
    bool cartas_usando [5][4]={false}; //esta matriz nos sirve para no repetir carta
    bool cartas_usando_j1 [cantidad_repartida][2] = {false};
    bool cartas_usando_j2 [cantidad_repartida][2] = {false};
    bool ganar_sin_sufrir_robo_j1 = false; // sirve para saber si hubo robo del jugador 1
    bool ganar_sin_sufrir_robo_j2 = false; // sirve para saber si hubo robo del jugador 2
    bool bandera_sin_pasar_deturnoj1= false; // sirve paara saber si paso de turno el jugador 1
    bool bandera_sin_pasar_deturnoj2=false; // sirve para saber si paso de turno el jugador 2
    bool B_JUGADOR_BLOQUEADOR1 = false; //sirve en caso de haber bloqueado todo en la F5 a favor del jugador 1, entonces el J2 pierde los turnos
    bool B_JUGADOR_BLOQUEADOR2 = false; //sirve en caso de haber bloqueado todo en la F5 a favor del jugador 2, entonces el J1 pierde los turnos

    srand(time(NULL));

    do {
        cout << right << setw(49)<< "|"<< setw(15)<< "CLUTCH   "<< left << "    |" << endl;
        cout << right << setw(49)<< "|"<< setw(15)<< "-------------------"<< left << "|" << endl;
        cout << right << setw(49)<< "|"<< setw(11)<< "1 - JUGAR"<< left << "        |" << endl;
        cout << right << setw(45) << "MENU PRINCIPAL"<< right << setw(4)<< "|"<< setw(18)<< "2 - ESTADISTICAS"<< left << " |" << endl;
        cout << right << setw(49)<< "|"<< setw(14)<< "3 - CREDITOS"<< left << "     |" << endl;
        cout << right << setw(49)<< "|"<< setw(15)<< "-------------------"<< left << "|" << endl;
        cout << right << setw(49)<< "|"<< setw(11)<< "0 - SALIR"<< left << "        |" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                elegir_nombres(nombre_j1, nombre_j2);
                cout << "Los nombres son " << nombre_j1 << " y " << nombre_j2 << endl;
                cout << "CLUTCH" << endl;
                cout << "------------------------------------------------------------------------" << endl;

                cargar_mazo(mazo, numero_cartas, tipo_palo);
                repartir_cartas_j1(cartas_usando, nombre_j1, corral_j1, cantidad_repartida, numero_cartas, tipo_palo, cartas_usando_j1);
                cout << endl;
                repartir_cartas_j2(cartas_usando, nombre_j2, corral_j2, cantidad_repartida, numero_cartas, tipo_palo, cartas_usando_j2);
                cout << endl;
                empieza_primero(corral_j1, corral_j2, numero_cartas, nombre_j1, nombre_j2, INICIA_PARTIDA, carta_repetida);
                cout << "El jugador " << INICIA_PARTIDA << " sera el primero en tirar el dado" << endl;

                if (INICIA_PARTIDA == nombre_j1) {
                    dado_j1 = lanzar_dado();
                    cout << endl << endl;
                    cout << "                   RONDA #" << RONDAS << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "El jugador " << nombre_j1 << " saco un " << dado_j1 << endl;
                    lanzo_dado = nombre_j1;
                    switch(dado_j1){
                        case 1:
                        OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2);
                        break;
                        case 2:
                        OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2);
                        break;
                        case 3:
                        OPCION_DADO_3(corral_j1, corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2);
                        break;
                        case 4:
                        OPCION_DADO_4(corral_j1, corral_j2,lanzo_dado, nombre_j1, nombre_j2 ,cartas_bloqueadas_j1, cartas_bloqueadas_j2 );
                        break;
                        case 5:
                        OPcion_DADO_5(corral_j1,corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                        break;
                        case 6:
                        OPCION_DADO_6(lanzo_dado, nombre_j1, nombre_j2, mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                        break;
                         }
                        verificar_ganador(B_CORTE_JUEGO, corral_j1, corral_j2, numero_cartas, lanzo_dado, nombre_j1, nombre_j2, nombre_ganador, ganar_partida, ganar_dado3, carta_mal_ubicada, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, ganar_sin_robo, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, ganar_sin_pasarturno);
                        if(B_CORTE_JUEGO != true){
                            cout << "ya jugo su mano " << nombre_j1 << ", ahora sigue " << nombre_j2 << endl << endl;
                            mostrar_ambos_corrales(corral_j1, corral_j2, nombre_j1, nombre_j2);
                            lanzo_dado=nombre_j2;
                        }
                     }else{
                    dado_j2 = lanzar_dado();
                    cout << endl << endl;
                    cout << "                   RONDA #" << RONDAS << endl;
                    cout << "------------------------------------------------------------------------" << endl;
                    cout << "El jugador " << nombre_j2 << " saco un " << dado_j2 << endl;
                    lanzo_dado = nombre_j2;
                    switch(dado_j2){
                        case 1:
                        OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2);
                        break;
                        case 2:
                        OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2);
                        break;
                        case 3:
                        OPCION_DADO_3(corral_j1, corral_j2, lanzo_dado, nombre_j1, nombre_j2,cartas_bloqueadas_j1, cartas_bloqueadas_j2, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2);
                        break;
                        case 4:
                        OPCION_DADO_4(corral_j1, corral_j2,lanzo_dado, nombre_j1, nombre_j2 ,cartas_bloqueadas_j1, cartas_bloqueadas_j2 );
                        break;
                        case 5:
                        OPcion_DADO_5(corral_j1,corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                        break;
                        case 6:
                        OPCION_DADO_6(lanzo_dado, nombre_j1, nombre_j2, mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                        break;
                         }
                        verificar_ganador(B_CORTE_JUEGO, corral_j1, corral_j2, numero_cartas, lanzo_dado, nombre_j1, nombre_j2, nombre_ganador, ganar_partida, ganar_dado3, carta_mal_ubicada, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, ganar_sin_robo, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, ganar_sin_pasarturno);
                        if(B_CORTE_JUEGO != true){
                           cout << "ya jugo su mano " << nombre_j2 << ", ahora sigue " << nombre_j1 << endl << endl;
                            mostrar_ambos_corrales(corral_j1, corral_j2, nombre_j1, nombre_j2);
                            lanzo_dado=nombre_j1;
                        }
                     }
                     while(B_CORTE_JUEGO != true){
                        RONDAS ++;
                        if(lanzo_dado == nombre_j1){
                        dado_j1= lanzar_dado();
                        cout << endl << endl;
                        cout << "                   RONDA #" << RONDAS << endl;
                        cout << "------------------------------------------------------------------------" << endl;
                        cout << "Es el turno del jugador " << nombre_j1 << ", procedera a tirar el dado" << endl;
                        cout << "------------------------------------------------------------------------" << endl;
                        cout << "El jugador " << nombre_j1 << " saco un " << dado_j1 << endl;
                        cout << "------------------------------------------------------------------------" << endl;
                        switch(dado_j1){
                            case 1:
                            OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2);
                            break;
                            case 2:
                            OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2);
                            break;
                            case 3:
                            OPCION_DADO_3(corral_j1, corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2);
                            break;
                            case 4:
                            OPCION_DADO_4(corral_j1, corral_j2,lanzo_dado, nombre_j1, nombre_j2 ,cartas_bloqueadas_j1, cartas_bloqueadas_j2 );
                            break;
                            case 5:
                            OPcion_DADO_5(corral_j1,corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                            break;
                            case 6:
                            OPCION_DADO_6(lanzo_dado, nombre_j1, nombre_j2, mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                            break;
                             }
                             verificar_ganador(B_CORTE_JUEGO, corral_j1, corral_j2, numero_cartas, lanzo_dado, nombre_j1, nombre_j2, nombre_ganador, ganar_partida, ganar_dado3, carta_mal_ubicada, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, ganar_sin_robo, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, ganar_sin_pasarturno); ///VERIFICAMOS SI EL CORRAL ESTA ORDENADO TAL COMO SE REQUIERE O NO
                             if(B_CORTE_JUEGO != true){
                                cout << "ya jugo su mano " << nombre_j1 << ", ahora sigue " << nombre_j2 << endl << endl;
                                mostrar_ambos_corrales(corral_j1, corral_j2, nombre_j1, nombre_j2);
                                lanzo_dado=nombre_j2;
                             }
                            }else if(lanzo_dado == nombre_j2){
                            dado_j2 = lanzar_dado();
                            cout << endl << endl;
                            cout << "                   RONDA #" << RONDAS << endl;
                            cout << "------------------------------------------------------------------------" << endl;
                            cout << "Es el turno del jugador " << nombre_j2 << ", procedera a tirar el dado" << endl;
                            cout << "------------------------------------------------------------------------" << endl;
                            cout << "El jugador " << nombre_j2 << " saco un " << dado_j2 << endl;
                            cout << "------------------------------------------------------------------------" << endl;
                            switch(dado_j2){
                                case 1:
                                OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2);
                                break;
                                case 2:
                                OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2);
                                break;
                                case 3:
                                OPCION_DADO_3(corral_j1, corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2);
                                break;
                                case 4:
                                OPCION_DADO_4(corral_j1, corral_j2,lanzo_dado, nombre_j1, nombre_j2 ,cartas_bloqueadas_j1, cartas_bloqueadas_j2 );
                                break;
                                case 5:
                                OPcion_DADO_5(corral_j1,corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                                break;
                                case 6:
                                OPCION_DADO_6(lanzo_dado, nombre_j1, nombre_j2, mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                                break;
                                }
                                verificar_ganador(B_CORTE_JUEGO, corral_j1, corral_j2, numero_cartas, lanzo_dado, nombre_j1, nombre_j2, nombre_ganador, ganar_partida, ganar_dado3, carta_mal_ubicada, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, ganar_sin_robo, bandera_sin_pasar_deturnoj1, bandera_sin_pasar_deturnoj2, ganar_sin_pasarturno);
                                if(B_CORTE_JUEGO != true){
                                    cout << "ya jugo su mano " << nombre_j2 << ", ahora sigue " << nombre_j1 << endl << endl;
                                    mostrar_ambos_corrales(corral_j1, corral_j2, nombre_j1, nombre_j2);
                                    lanzo_dado=nombre_j1;
                                }
                            }
                        }
            case 2:

                int terminar;

                cout<<"CLUTCH"<<endl;
                cout<<"------------------------------------------------------------------------"<<endl;
                cout<<endl;
                cout<<"HITO                                                 "<<"JUGADOR "<<nombre_ganador<<endl;
                cout<<"------------------------------------------------------------------------"<<endl;
                cout<<"GANAR LA PARTIDA                                     " << ganar_partida  <<endl;
                cout<<"ROBO LA ULTIMA CARTA DEL JUGADOR RIVAL               " << ganar_dado3 <<endl;
                cout<<"CARMAS MAL UBICADAS DEL JUGADOR RIVAL X 4            " << carta_mal_ubicada <<endl;
                cout<<"SIN PASAR DE TURNO                                   " << ganar_sin_pasarturno <<endl;
                cout<<"SIN HABER SUFRIDO UN ROBO DEL RIVAL                  " << ganar_sin_robo <<endl;
                cout<<"------------------------------------------------------------------------"<<endl;
                cout<<"TOTAL            " << (ganar_partida+ ganar_dado3+ carta_mal_ubicada+ ganar_sin_robo + ganar_sin_pasarturno) <<endl;
                cout<<endl;
                cout<<"GANADOR: "<<nombre_ganador<<endl;
                cout<<endl;

                while(terminar != 0)
                {
                    cout<<"PRESIONAR 0 PARA CONTINUAR"<<endl;
                    cin>>terminar;
                }

            break;

            case 3:
                cout<<"                                                JUEGO DESARROLLADO POR: "<<endl;
                cout<<"                                                     PEREYRA AXEL"<<endl;
                cout<<"                                                     LUCAS JUAREZ"<<endl;
                cout<<"                                                   AYLIN PANIAGUA"<<endl;
                cout<<"                                               SANTIAGO PAULOVICH"<<endl;
                cout<<endl;

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
       cout << right <<setw(30)<< "CLUTCH" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << right << setw(50) << "Antes de comenzar deben registrar sus nombres" << endl;
        cout << endl;
        cout << right << setfill('*') << setw(30) << " JUGADOR 1" << left << " *********************" << endl;
        cin >> nombre_j1;
        cout << right << setfill('*') << setw(30) << " JUGADOR 2" << left << " *********************" << endl;
        cin >> nombre_j2;
        cout << right << setfill('*') << setw(40) << " PULSE 'S' PARA CONFIRMAR" << left << " ***************" << endl;
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


// Funcion para repartir cartas al jugador 1
void repartir_cartas_j1(bool (&cartas_usando)[5][4], string nombre_j1, string corral_j1[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[], bool cartas_usando_j1 [5][2])
{
    bool bandera, bandera_general = false; /// bandera general: anti-escalera ganadora al principio
    int detector_escalera = 0; ///cuenta la forma de ordenamiento del corral con respecto al numero_cartas

    cout << "Cartas repartidas para el jugador " << nombre_j1 << endl;

    while(bandera_general != true){  ///controlamos que en detector de escalera no cuenta 5, si cuenta 5 la bandera no se activa y reparte nuevamente
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
                cartas_usando_j1 [x][0] = true; //si esta en true, es porque sus cartas estan en uso
                cartas_usando_j1 [x][1] = true;
                cartas_usando[numero][palo]=true;
                bandera=true;
                }
                for(int y = 0 ; y < 5 ; y ++)
                {
                    if(corral_j1[x][0] == numero_cartas[x])
                    {
                        detector_escalera ++;                   /// linea 339 - 351: metodo para evitar tener todo ordenado de principio
                    }
                }
            }
        }
        if(!(detector_escalera == 5))
        {
        bandera_general = true;
        }
    }

    for(int x = 0; x < cantidad_repartida; x++)
    {
        cout << corral_j1[x][0] << " " << corral_j1[x][1] << endl;
    }

}

// Funcion para repartir cartas al jugador 2
void repartir_cartas_j2(bool (&cartas_usando)[5][4], string nombre_j2, string corral_j2[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[], bool cartas_usando_j2 [5][2])
{
    bool bandera, bandera_general = false;
    int detector_escalera = 0;;


    cout << "Cartas repartidas para el jugador " << nombre_j2 << endl;

while(bandera_general != true){
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
                cartas_usando_j2 [x][0] = true; //si esta en true, es porque sus cartas estan en uso
                cartas_usando_j2 [x][1] = true;
                cartas_usando[numero][palo]=true;
                bandera=true;
                }
                for(int y = 0 ; y < 5 ; y ++)
                {
                    if(corral_j2[x][0] == numero_cartas[x])
                    {
                        detector_escalera ++;
                    }
                }
            }
        }
        if(!(detector_escalera == 5))
        {
        bandera_general = true;
        }
    }
    for(int x = 0; x < cantidad_repartida; x++)
    {
        cout << corral_j2[x][0] << " " << corral_j2[x][1] << endl;
    }
}

// Funcion para decidir quien empieza primero
void empieza_primero(string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &nombre_j1, string &nombre_j2, string &INICIA_PARTIDA, string &carta_repetida)
{
    bool BANDERA_PRIMERIZO = false;
    int I = 5, CONT_J1, CONT_J2;

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
            I--;
        }
    }
}

// Funcion para lanzar un dado aleatorio
int lanzar_dado(const int caras_dado)
{
    return rand() % caras_dado + 1;
}

// Funcion para verificar si existe el jugador ganador en cada vuelta
void verificar_ganador(bool &B_CORTE_JUEGO, string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &lanzo_dado, string nombre_j1, string nombre_j2, string &nombre_ganador, int &ganar_partida, int &ganar_dado3, int &carta_mal_ubicada, bool &ganar_sin_sufrir_robo_j1, bool &ganar_sin_sufrir_robo_j2, int &ganar_sin_robo, bool &bandera_sin_pasar_deturnoj1, bool &bandera_sin_pasar_deturnoj2, int &ganar_sin_pasarturno){
    int CONTADOR = 0;

    if(lanzo_dado == nombre_j1){

        for(int x = 0 ; x < 5 ; x ++){ //recorre el corral y si estan todas las cartas ordenadas suma
            if(corral_j1[x][0] == numero_cartas[x]){
                CONTADOR ++;
            }
        }
        if(CONTADOR == 5){ //si estan todas ordenadas entra al for y hace las estadisticas
            for(int x = 0 ; x < 5 ; x ++){ //carta mal ubicada
            if(corral_j2[x][0] != numero_cartas[x]){
                carta_mal_ubicada+=5;
            }
            }
            if(lanzar_dado()==3){ //ganar robando una carta
            ganar_dado3+=10;
        }
        if (ganar_sin_sufrir_robo_j2== false){ //ganar si no te robaron
            ganar_sin_robo+=5;
        }
        if(bandera_sin_pasar_deturnoj1==false){ //ganar sin pasar de turno (dado 6, case 6)
            ganar_sin_pasarturno+=10;
        }

            cout << nombre_j1 << " LOGRO ORDENAR EL MAZO EN ESCALERA, ES EL GANADOR!!" << endl;
            cout << "------------------------------------------" << endl;
            cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
            cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
            cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl;
            cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
            cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
            cout << "------------------------------------------" << endl;
            nombre_ganador = nombre_j1;
            ganar_partida+=15;
            B_CORTE_JUEGO = true;
        }
    }else if(lanzo_dado == nombre_j2){


        for(int x = 0 ; x < 5 ; x ++){
            if(corral_j2[x][0] == numero_cartas[x]){
                CONTADOR ++;
            }
        }
        if(CONTADOR == 5){
            for(int x = 0 ; x < 5 ; x ++){
            if(corral_j1[x][0] != numero_cartas[x]){
                carta_mal_ubicada+=5;
            }
            }

            if(lanzar_dado()==3){
            ganar_dado3+=10;
        }
        if (ganar_sin_sufrir_robo_j1== false){
            ganar_sin_robo+=5;
        }
        if(bandera_sin_pasar_deturnoj2==false){
            ganar_sin_pasarturno+=10;
        }

            cout << nombre_j2 << " LOGRO ORDENAR EL MAZO EN ESCALERA, ES EL GANADOR!!" << endl;
            cout << "------------------------------------------" << endl;
            cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
            cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
            cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl;
            cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
            cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
            cout << "------------------------------------------" << endl;
            nombre_ganador = nombre_j2;
            ganar_partida+=15;
            B_CORTE_JUEGO = true;
        }
    }
}

// Funcion para evitar la repeticion de cartas en la funcion 1 y 2
bool comparar_cartas(string (&corral_j1)[5][2], string (&corral_j2)[5][2])
{

            for(int x = 0 ; x < 5 ; x ++){

                if((corral_j1[x][0] == corral_j2 [x][0])&&(corral_j1[x][1] == corral_j2 [x][1])){
                    return true;
                }else{
                    return false;
                }
            }
}

void mostrar_ambos_corrales(string corral_j1[][2], string corral_j2[][2], string nombre_j1, string nombre_j2)
{
            cout << setfill(' ');
            cout << "------------------------------------------" << endl;
            cout << "|" << "             MAZO DE "<< nombre_j1 << "                 " << endl;
            cout << "------------------------------------------" << endl;
            cout << setw(15) << "|"<< setw(3) << corral_j1 [0][0] << " " << corral_j1 [0][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j1 [1][0] << " " << corral_j1 [1][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j1 [2][0] << " " << corral_j1 [2][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j1 [3][0] << " " << corral_j1 [3][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j1 [4][0] << " " << corral_j1 [4][1] <<endl;
            cout << "|"<< endl;
            cout << "------------------------------------------" << endl;
            cout << "|" << "             MAZO DE "<< nombre_j2 << "                 " << endl;
            cout << "------------------------------------------" << endl;
            cout << setw(15) << "|"<< setw(3) << corral_j2 [0][0] << " " << corral_j2 [0][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j2 [1][0] << " " << corral_j2 [1][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j2 [2][0] << " " << corral_j2 [2][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j2 [3][0] << " " << corral_j2 [3][1] <<endl;
            cout << setw(15) << "|"<< setw(3) << corral_j2 [4][0] << " " << corral_j2 [4][1] <<endl;
            cout << "------------------------------------------" << endl;
}

//funcion dado 1
void OPCION_DADO_1(string (&mazo)[5][4], string numero_cartas[5], string tipo_palo[4], string (&corral_j1)[5][2], string (&corral_j2) [5][2], bool (&cartas_usando) [5][4], string &lanzo_dado, string nombre_j1, string nombre_j2){
    int CARTA = 0, NEW_NUM = 0, NEW_PALO;
    bool CORTE_CAMBIO_CARTA = false, BANDERA_FUNCION_COMPARAR = false;
    string CARTA_INTERCAMBIADA_NUMERO, CARTA_INTERCAMBIADA_PALO, CARTA_ACTUAL, PALO_ACTUAL;


    if(lanzo_dado == nombre_j1){
    cout << endl;
    cout << "OPCION #1: EL JUGADOR " << nombre_j1 << " PODRA INTERCAMBIAR UNA CARTA DE SU CORRAL POR UNA DEL MAZO, SUERTE!!" << endl;
    cout << "===================================================================================================" << endl;

    cout << "   SELECCION DE CARTAS PARA INTERCAMBIO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl; ///MAZO ANTES DE CAMBIO DE CARTA
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;
    CARTA_INTERCAMBIADA_NUMERO = corral_j1[CARTA - 1][0];//la carta elegida del corral se guarda en esta auxiliar
    CARTA_INTERCAMBIADA_PALO = corral_j1[CARTA - 1][1];

     //pregunto si la carta elegida esta en el mazo
      for(int x = 0 ; x < 5 ; x ++){

        for(int y = 0 ; y < 4 ; y ++){ //palo
            if(corral_j1[CARTA - 1][0] == mazo[x][y] && corral_j1 [CARTA - 1][1] == mazo[x][y]){
                cartas_usando[x][y] = false; //si no esta en el mazo aca pones en falso la posicion de la carta (osea pones la carta en el mazo)
            }
        }
    }
    while(CORTE_CAMBIO_CARTA != true){
        NEW_NUM = rand() % 5; //genero una carta random (para que sea la que saque del maso)
        NEW_PALO = rand() % 4;

        if(cartas_usando [NEW_NUM][NEW_PALO] == false){ //pregunto si la carta random se puede usar
            corral_j1 [CARTA - 1][0] = numero_cartas[NEW_NUM];
            corral_j1 [CARTA - 1][1] = tipo_palo[NEW_PALO];
            CARTA_ACTUAL = numero_cartas[NEW_NUM]; ///VARIABLES PARA PODER MOSTRARLO EN EL COUT, YA QUE NO PUEDO MOSTRAR LA MATRIZ DEL CORRAL DIRECTAMENTE
            PALO_ACTUAL = tipo_palo [NEW_PALO];
            BANDERA_FUNCION_COMPARAR = comparar_cartas(corral_j1, corral_j2); // LLAMADO DE LA FUNCION ANTI-REPETICION
            if(!BANDERA_FUNCION_COMPARAR){
                cartas_usando[NEW_NUM][NEW_PALO] = true; //CONDICION DE CORTE DE WHILE
                CORTE_CAMBIO_CARTA = true;
            }else{
                cartas_usando[NEW_NUM][NEW_PALO] = false;
            }
        }
    }

    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
        
////////////HASTA ACA LA OPCION J1, AHORA EMPIEZA LA OPCION DEL J2/////////////////////////////
    }else if(lanzo_dado == nombre_j2){
    cout << endl;
    cout << "OPCION #1: EL JUGADOR " << nombre_j2 << " PODRA INTERCAMBIAR UNA CARTA DE SU CORRAL POR UNA DEL MAZO, SUERTE!!" << endl;
    cout << "===================================================================================================" << endl;

    cout << "   SELECCION DE CARTAS PARA INTERCAMBIO" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
    cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
    cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl; ///MAZO ANTES DE CAMBIO DE CARTA
    cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
    cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;
    CARTA_INTERCAMBIADA_NUMERO = corral_j2[CARTA - 1][0];//la carta elegida del corral se guarda en esta auxiliar
    CARTA_INTERCAMBIADA_PALO = corral_j2[CARTA - 1][1];

      for(int x = 0 ; x < 5 ; x ++){//pregunto si la carta elegida esta en el mazo

        for(int y = 0 ; y < 4 ; y ++){//palo
            if(corral_j2[CARTA - 1][0] == mazo[x][y] && corral_j2 [CARTA - 1][1] == mazo[x][y]){
                cartas_usando[x][y] = false;//si no esta en el mazo aca pones en falso la posicion de la carta (osea pones la carta en el mazo)
            }
        }
    }
    while(CORTE_CAMBIO_CARTA != true){
        NEW_NUM = rand() % 5;//genero una carta random (para que sea la que saque del maso)
        NEW_PALO = rand() % 4;
        if(cartas_usando [NEW_NUM][NEW_PALO] == false){//pregunto si la carta random se puede usar
            corral_j2 [CARTA - 1][0] = numero_cartas[NEW_NUM];
            corral_j2 [CARTA - 1][1] = tipo_palo[NEW_PALO];
            CARTA_ACTUAL = numero_cartas[NEW_NUM]; ///VARIABLES PARA PODER MOSTRARLO EN EL COUT, YA QUE NO PUEDO MOSTRAR LA MATRIZ DEL CORRAL DIRECTAMENTE
            PALO_ACTUAL = tipo_palo [NEW_PALO];
            BANDERA_FUNCION_COMPARAR = comparar_cartas(corral_j1, corral_j2);
            if(!BANDERA_FUNCION_COMPARAR){
                cartas_usando[NEW_NUM][NEW_PALO] = true;
                CORTE_CAMBIO_CARTA = true;
            }else{
                cartas_usando[NEW_NUM][NEW_PALO] = false;
            }
        }
    }

    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
    
    }
}

//funcion dado 2
void OPCION_DADO_2(string (&mazo)[5][4], string numero_cartas[], string tipo_palo[], string (&corral_j1)[5][2], string (&corral_j2) [5][2], bool (&cartas_usando) [5][4], string &lanzo_dado, string nombre_j1, string nombre_j2, bool (&cartas_bloqueadas_j2)[5][2],  bool (&cartas_bloqueadas_j1)[5][2]){
    int CARTA , NEW_NUM , NEW_PALO;
    bool CORTE_CAMBIO_CARTA = false, BANDERA_FUNCION_COMPARAR = false, BANDERA_BLOQUEADA=false;
    string CARTA_INTERCAMBIADA_NUMERO, CARTA_INTERCAMBIADA_PALO, CARTA_ACTUAL, PALO_ACTUAL;



    if(lanzo_dado == nombre_j1){
    if(cartas_bloqueadas_j2){
        cout << nombre_j2 << " logro bloquear todas sus cartas, por lo tanto " << nombre_j1 << " no tendra derecho a realizar esta accion, su turno queda anulado, lo sentimos!!" << endl;
    }else{
    cout << endl;
    cout << "OPCION #2: EL JUGADOR " << nombre_j1 << " PODRA INTERCAMBIAR UNA CARTA DEL CORRAL CONTRARIO POR UNA DEL MAZO, SUERTE!!" << endl;
    cout << "===================================================================================================" << endl;

    cout << "SELECCION DEL MAZO DEL CONTRARIO (" << nombre_j2 << ")" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
    cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
    cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl; ///MAZO ANTES DE CAMBIO DE CARTA
    cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
    cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;

    while(BANDERA_BLOQUEADA != true){

        if(cartas_bloqueadas_j2[CARTA -1][0] == true && cartas_bloqueadas_j2[CARTA - 1][1] == true  ){ //si la carta esta bloqueada

            cout<<"Esta carta esta bloqueada por la acción del dado 5, por favor elija otra carta: ";
               cout << "SELECCION DEL MAZO DEL CONTRARIO (" << nombre_j2 << ")" << endl;
            cout << "------------------------------------------" << endl;
            cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
            cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
            cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl; ///vuelve a mostrar las opciones hasta que se elija una que no este bloqueada
            cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
            cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
            cout << "------------------------------------------" << endl;
            cin >> CARTA;

        }else{
            BANDERA_BLOQUEADA=true;
        }
    }

    CARTA_INTERCAMBIADA_NUMERO = corral_j2[CARTA - 1][0]; //creas una carta auxiliar
    CARTA_INTERCAMBIADA_PALO = corral_j2[CARTA - 1][1];

    for(int x = 0 ; x < 5 ; x ++){ //aca se pregunta si la carta esta en el mazo

        for(int y = 0 ; y < 4 ; y ++){
            if(corral_j2[CARTA - 1][0] == mazo[x][y] && corral_j2 [CARTA - 1][1] == mazo[x][y]){
                cartas_usando[x][y] = false;
            }
        }
    }

    while(CORTE_CAMBIO_CARTA != true){ //una bandera para que la carta que te toco no sea repetida
        NEW_NUM = rand() % 5; //genero una carta del mazo
        NEW_PALO = rand() % 4;
        if(cartas_usando [NEW_NUM][NEW_PALO] == false){ //pregunto si la carta esta libre para usar
            corral_j2 [CARTA - 1][0] = numero_cartas[NEW_NUM]; //hace el intercambio
            corral_j2 [CARTA - 1][1] = tipo_palo[NEW_PALO];
            CARTA_ACTUAL = numero_cartas[NEW_NUM];
            PALO_ACTUAL = tipo_palo [NEW_PALO];
            BANDERA_FUNCION_COMPARAR = comparar_cartas(corral_j1, corral_j2);
            if(!BANDERA_FUNCION_COMPARAR){ //si la funcion retorna un true el codigo se repite hasta tener una carta que se pueda usar
                cartas_usando[NEW_NUM][NEW_PALO] = true;
                CORTE_CAMBIO_CARTA = true;
            }else{
                cartas_usando[NEW_NUM][NEW_PALO] = false; //esto es por si retorna falso
            }
        }
    }
    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
    
    }
////////////HASTA ACA LA OPCION J1, AHORA EMPIEZA LA OPCION DEL J2/////////////////////////////
    }else if(lanzo_dado == nombre_j2){
    if(cartas_bloqueadas_j1){
        cout << nombre_j1 << " logro bloquear todas sus cartas, por lo tanto " << nombre_j2 << " no tendra derecho a realizar esta accion, su turno queda anulado, lo sentimos!!" << endl;
    }else{
    cout << endl;
    cout << "OPCION #2: EL JUGADOR " << nombre_j2 << " PODRA INTERCAMBIAR UNA CARTA DEL CORRAL CONTRARIO POR UNA DEL MAZO, SUERTE!!" << endl;
    cout << "===================================================================================================" << endl;
    cout << "SELECCION DEL MAZO DEL CONTRARIO (" << nombre_j1 << ")" << endl;
    cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl; //
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;
    cin >> CARTA;

    while(BANDERA_BLOQUEADA != true){

        if(cartas_bloqueadas_j1[CARTA -1][0] == true && cartas_bloqueadas_j1[CARTA - 1][1] == true  ){ //si la carta esta bloqueada

            cout<<"Esta carta esta bloqueada por la acción del dado 5, por favor elija otra carta: ";
               cout << "SELECCION DEL MAZO DEL CONTRARIO (" << nombre_j2 << ")" << endl;
            cout << "------------------------------------------" << endl;
            cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
            cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
            cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl; ///vuelve a mostrar las opciones hasta que se elija una que no este bloqueada
            cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
            cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
            cout << "------------------------------------------" << endl;
            cin >> CARTA;

        }else{
            BANDERA_BLOQUEADA=true;
        }
    }
    CARTA_INTERCAMBIADA_NUMERO = corral_j1[CARTA - 1][0];
    CARTA_INTERCAMBIADA_PALO = corral_j1[CARTA - 1][1];

    for(int x = 0 ; x < 5 ; x ++){

        for(int y = 0 ; y < 4 ; y ++){
            if(corral_j1[CARTA - 1][0] == mazo[x][y] && corral_j1 [CARTA - 1][1] == mazo[x][y]){
                cartas_usando[x][y] = false;
            }
        }
    }

    while(CORTE_CAMBIO_CARTA != true){
        NEW_NUM = rand() % 5;
        NEW_PALO = rand() % 4;
        if(cartas_usando [NEW_NUM][NEW_PALO] == false){
            corral_j1 [CARTA - 1][0] = numero_cartas[NEW_NUM];
            corral_j1 [CARTA - 1][1] = tipo_palo[NEW_PALO];
            CARTA_ACTUAL = numero_cartas[NEW_NUM];
            PALO_ACTUAL = tipo_palo [NEW_PALO];
            BANDERA_FUNCION_COMPARAR = comparar_cartas(corral_j1, corral_j2);
            if(!BANDERA_FUNCION_COMPARAR){
                cartas_usando[NEW_NUM][NEW_PALO] = true;
                CORTE_CAMBIO_CARTA = true;
            }else{
                cartas_usando[NEW_NUM][NEW_PALO] = false;
            }
        }
    }
    cout << "la carta intercambiada fue " << CARTA_INTERCAMBIADA_NUMERO << " de " << CARTA_INTERCAMBIADA_PALO;
    cout << ", que fue cambiada por " << CARTA_ACTUAL << " de " << PALO_ACTUAL << endl;
    cout << endl;
    
    }
    }
}


// FUNCION PARA LA CARA 3 DEL dado

void OPCION_DADO_3(string (&corral_j1)[5][2], string (&corral_j2)[5][2], string &lanzo_dado, string nombre_j1, string nombre_j2, bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2], bool &ganar_sin_sufrir_robo_j1, bool &ganar_sin_sufrir_robo_j2, bool &B_JUGADOR_BLOQUEADOR1, bool &B_JUGADOR_BLOQUEADOR2)
{
    int carta;
    int carta_intercambiada;
    string numero_carta, numero_palo;
    string carta_elegida[2];
    bool bandera_carta_bloqueada= false;

    if(lanzo_dado==nombre_j2){
        if(B_JUGADOR_BLOQUEADOR1){
        cout << nombre_j1 << " logro bloquear todas sus cartas, por lo tanto " << nombre_j2 << " no tendra derecho a realizar esta accion, su turno queda anulado, lo sentimos!!" << endl;
        }else{
        ganar_sin_sufrir_robo_j1=true; //esto es parte de la estadistica
        cout << endl;
        cout << " OPCION #3: EL JUGADOR "<< nombre_j2 << " ELIGIRA UNA CARTA DEL PROPIO CORRAL Y LA INTERCAMBIARA POR UNA CARTA DEL CORRAL CONTRARIO " << endl;
        cout << "===================================================================================================" << endl;

        cout << "   SELECCIONE UNA CARTA PARA INTERCAMBIO  " << endl;
        cout << "------------------------------------------" << endl;
        cout << "#1 : " << corral_j2[0][0] << " " << corral_j2[0][1] << endl;
        cout << "#2 : " << corral_j2[1][0] << " " << corral_j2[1][1] << endl;
        cout << "#3 : " << corral_j2[2][0] << " " << corral_j2[2][1] << endl; /// MAZO ANTES DE CAMBIO DE CARTA
        cout << "#4 : " << corral_j2[3][0] << " " << corral_j2[3][1] << endl;
        cout << "#5 : " << corral_j2[4][0] << " " << corral_j2[4][1] << endl;
        cout << "------------------------------------------" << endl;
        cin >> carta;

        numero_carta = corral_j2[carta - 1][0]; //se guarda el numero de la carta elegida
        numero_palo = corral_j2[carta - 1][1]; // aca el palo de la carta

        carta_elegida[0] = numero_carta;
        carta_elegida[1] = numero_palo; // aca esos datos se guardan en la carta elegida para intercambio (auxiliar)

        cout << "  SELECCIONE POR QUE CARTA DESEA INTERCAMBIARLA DEL CORRAL DE "<< nombre_j1 << endl;
         cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl;
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;

        cout << "------------------------------------------" << endl;
        cin >> carta_intercambiada;//la carta del corral contrario

        while(bandera_carta_bloqueada==false){

            if((cartas_bloqueadas_j1[carta_intercambiada-1][0]==false && cartas_bloqueadas_j1[carta_intercambiada-1][1]== false)){// aca pregunta si la segunda carta elegida No esta bloqueada


                cartas_bloqueadas_j2[carta-1][0]=false;// si la carta del otro no esta bloqueada yo se la doy, pero al yo cambiarla para mi se desbloquea
                cartas_bloqueadas_j2[carta-1][1]=false;
                bandera_carta_bloqueada=true;
            }

        else {

                    cout << " ESTA CARTA ESTA BLOQUEADA, ELIGA OTRA POR FAVOR " << endl;

                    cout << "  SELECCIONE POR QUE CARTA DESEA INTERCAMBIARLA DEL CORRAL DE "<< nombre_j1 << endl;
         cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j1 [0][0] << " " << corral_j1 [0][1] << endl;
    cout << "#2 : " << corral_j1 [1][0] << " " << corral_j1 [1][1] << endl;
    cout << "#3 : " << corral_j1 [2][0] << " " << corral_j1 [2][1] << endl;
    cout << "#4 : " << corral_j1 [3][0] << " " << corral_j1 [3][1] << endl;
    cout << "#5 : " << corral_j1 [4][0] << " " << corral_j1 [4][1] << endl;
    cout << "------------------------------------------" << endl;

        cout << "------------------------------------------" << endl;
        cin >> carta_intercambiada;//la carta de tu corral
        bandera_carta_bloqueada=false;

                }
            }

        corral_j2[carta - 1][0] = corral_j1[carta_intercambiada - 1][0]; // en tu corral guardas la carta que elegiste del otro
        corral_j2[carta - 1][1] = corral_j1[carta_intercambiada - 1][1];


        corral_j1[carta_intercambiada - 1][0] = carta_elegida[0]; // en el corral del otro guardo la carta elegida (auxiliar)
        corral_j1[carta_intercambiada - 1][1] = carta_elegida[1];



        cout << "-----------------------------------------------------" << endl;
        cout << "Se intercambio la carta #" << carta << " por la #" << carta_intercambiada << endl;
        cout << "------------------------------------------------------" << endl;
        cout << endl;

        }
    }

    else
    {
        if(B_JUGADOR_BLOQUEADOR2){
        cout << nombre_j2 << " logro bloquear todas sus cartas, por lo tanto " << nombre_j1 << " no tendra derecho a realizar esta accion, su turno queda anulado, lo sentimos!!" << endl;
        }else{
        ganar_sin_sufrir_robo_j2=true;
        cout << endl;
        cout << "OPCION #3: EL JUGADOR " << nombre_j1 << " ELEGIR UNA CARTA DEL PROPIO CORRAL E INTERCAMBIARLA POR UNA CARTA DEL CORRAL CONTRARIO " << endl;
        cout << "===================================================================================================" << endl;

        cout << "   SELECCIONE UNA CARTA PARA INTERCAMBIO  " << endl;
        cout << "------------------------------------------" << endl;
        cout << "#1 : " << corral_j1[0][0] << " " << corral_j1[0][1] << endl;
        cout << "#2 : " << corral_j1[1][0] << " " << corral_j1[1][1] << endl;
        cout << "#3 : " << corral_j1[2][0] << " " << corral_j1[2][1] << endl;
        cout << "#4 : " << corral_j1[3][0] << " " << corral_j1[3][1] << endl;
        cout << "#5 : " << corral_j1[4][0] << " " << corral_j1[4][1] << endl;
        cout << "------------------------------------------" << endl;
        cin >> carta;
        numero_carta = corral_j1[carta - 1][0];
        numero_palo = corral_j1[carta - 1][1];

        carta_elegida[0] = numero_carta;
        carta_elegida[1] = numero_palo; // aca se guarda la carta elegida para intercambio

        cout << "  SELECCIONE POR QUE CARTA DESEA INTERCAMBIARLA DEL CORRAL CONTRARIO  " << endl;
        cout << "------------------------------------------" << endl;
        cout << "#1 : " << corral_j2[0][0] << " " << corral_j2[0][1] << endl;
        cout << "#2 : " << corral_j2[1][0] << " " << corral_j2[1][1] << endl;
        cout << "#3 : " << corral_j2[2][0] << " " << corral_j2[2][1] << endl;
        cout << "#4 : " << corral_j2[3][0] << " " << corral_j2[3][1] << endl;
        cout << "#5 : " << corral_j2[4][0] << " " << corral_j2[4][1] << endl;
        cout<<endl;

        cout << "------------------------------------------" << endl;
        cin >> carta_intercambiada;

        while(bandera_carta_bloqueada==false){

            if((cartas_bloqueadas_j2[carta_intercambiada-1][0]==false && cartas_bloqueadas_j2[carta_intercambiada-1][1]== false)){   // aca pregunta si la segunda carta elegida No esta bloqueada


                cartas_bloqueadas_j1[carta-1][0]=false;
                cartas_bloqueadas_j1[carta-1][1]=false;
                bandera_carta_bloqueada=true;
            }

        else {

                    cout << " ESTA CARTA ESTA BLOQUEADA, ELIGA OTRA POR FAVOR " << endl;

                    cout << "  SELECCIONE POR QUE CARTA DESEA INTERCAMBIARLA DEL CORRAL DE "<< nombre_j2 << endl;
         cout << "------------------------------------------" << endl;
    cout << "#1 : " << corral_j2 [0][0] << " " << corral_j2 [0][1] << endl;
    cout << "#2 : " << corral_j2 [1][0] << " " << corral_j2 [1][1] << endl;
    cout << "#3 : " << corral_j2 [2][0] << " " << corral_j2 [2][1] << endl;
    cout << "#4 : " << corral_j2 [3][0] << " " << corral_j2 [3][1] << endl;
    cout << "#5 : " << corral_j2 [4][0] << " " << corral_j2 [4][1] << endl;
    cout << "------------------------------------------" << endl;

        cout << "------------------------------------------" << endl;
        cin >> carta_intercambiada;//la carta del corral contrario
        bandera_carta_bloqueada=false;

                }
            }

        corral_j1[carta - 1][0] = corral_j2[carta_intercambiada - 1][0]; // intercambio de la primera carta seleccionada
        corral_j1[carta - 1][1] = corral_j2[carta_intercambiada - 1][1];


         corral_j2[carta_intercambiada - 1][0] = carta_elegida[0]; // intercambio de la segunda carta por la auxiliar
        corral_j2[carta_intercambiada - 1][1] = carta_elegida[1];


        cout << "-----------------------------------------------------" << endl;
        cout << "Se intercambio la carta #" << carta << " por la #" << carta_intercambiada << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << endl;

        }
    }
}


//funcion para la cara 4 del dado
void OPCION_DADO_4(string (&corral_j1)[5][2], string (&corral_j2)[5][2], string &lanzo_dado, string nombre_j1, string nombre_j2, bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2])
{

    int CARTA; // la carta que se eligio para intercambiar
    int CARTA_INTERCAMBIO; // la carta por la que se va a intercambiar
    string NUMERO_CARTA, NUMERO_PALO;
    string CARTA_ELEGIDA[2]; // carta auxiliar para el intercambio

    if (lanzo_dado == nombre_j2) // pregunto quien lanzo el dado en la ronda anterior para saber quien sigue
    {
        cout << endl;
        cout << "OPCION #4: EL JUGADOR " << nombre_j2 << " PODRA INTERCAMBIAR DOS CARTAS DE SU PROPIO CORRAL" << endl;
        cout << "===================================================================================================" << endl;

        cout << "   SELECCIONE UNA CARTA PARA INTERCAMBIO  " << endl;
        cout << "------------------------------------------" << endl;
        cout << "#1 : " << corral_j2[0][0] << " " << corral_j2[0][1] << endl;
        cout << "#2 : " << corral_j2[1][0] << " " << corral_j2[1][1] << endl;
        cout << "#3 : " << corral_j2[2][0] << " " << corral_j2[2][1] << endl; /// MAZO ANTES DE CAMBIO DE CARTA
        cout << "#4 : " << corral_j2[3][0] << " " << corral_j2[3][1] << endl;
        cout << "#5 : " << corral_j2[4][0] << " " << corral_j2[4][1] << endl;
        cout << "------------------------------------------" << endl;
        cin >> CARTA;
        NUMERO_CARTA = corral_j2[CARTA - 1][0]; //la carta elegida
        NUMERO_PALO = corral_j2[CARTA - 1][1];

        CARTA_ELEGIDA[0] = NUMERO_CARTA;
        CARTA_ELEGIDA[1] = NUMERO_PALO; // aca se guarda la carta elegida para intercambio (carta auxiliar)

        cout << "  SELECCIONE POR QUE CARTA DESEA INTERCAMBIARLA  " << endl;
        cout << "------------------------------------------" << endl;
        cin >> CARTA_INTERCAMBIO;

        corral_j2[CARTA - 1][0] = corral_j2[CARTA_INTERCAMBIO - 1][0]; // intercambio de la primera carta seleccionada
        corral_j2[CARTA - 1][1] = corral_j2[CARTA_INTERCAMBIO - 1][1];

        corral_j2[CARTA_INTERCAMBIO - 1][0] = CARTA_ELEGIDA[0]; // intercambio de la segunda carta por la auxiliar
        corral_j2[CARTA_INTERCAMBIO - 1][1] = CARTA_ELEGIDA[1];

        //aca se desarrolla los intercambios de posiciones de los bloqueos

        // el 1ro por si la primer carta esta bloqueada y la segunda no
        // el 2do por si la segunda esta bloqueada y la primera no

        if ((cartas_bloqueadas_j1[CARTA - 1][0] == true && cartas_bloqueadas_j1[CARTA - 1][1]== true)) //pregunto si la primer carta elegida esta bloqueada
        {
            if((cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][0] == false && cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][1]== false))//pregunto si la segunda carta elegida no esta bloqueada
            {

                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][0]=true;//la nueva posicion de la primer carta carta se bloquea
                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][1]=true;

                cartas_bloqueadas_j1[CARTA-1][0]=false; //la nueva posicion de la segunda carta se desbloquea
                cartas_bloqueadas_j1[CARTA-1][1]=false;
            }
        }else if((cartas_bloqueadas_j1[CARTA - 1][0] == false && cartas_bloqueadas_j1[CARTA - 1][1]== false)) //pregunto si la primer carta elegida no esta bloqueada
        {
            if((cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][0] == true && cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][1]== true))//pregunto si la segunda carta elegida esta bloqueada
            {

                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][0]=false;//la nueva posicion de la primer carta se desbloquea
                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][1]=false;

                cartas_bloqueadas_j1[CARTA-1][0]=true; //la nueva posicion de la segunda carta se bloquea
                cartas_bloqueadas_j1[CARTA-1][1]=true;
            }
        }

        cout << "-----------------------------------------------------" << endl;
        cout << "Se intercambio la carta #" << CARTA << " por la #" << CARTA_INTERCAMBIO << endl;
        cout << "------------------------------------------------------" << endl;
        cout << endl;

    }
    else
    {
        cout << endl;
        cout << "OPCION #4: EL JUGADOR " << nombre_j1 << " PODRA INTERCAMBIAR DOS CARTAS DE SU PROPIO CORRAL" << endl;
        cout << "===================================================================================================" << endl;

        cout << "   SELECCIONE UNA CARTA PARA INTERCAMBIO  " << endl;
        cout << "------------------------------------------" << endl;
        cout << "#1 : " << corral_j1[0][0] << " " << corral_j1[0][1] << endl;
        cout << "#2 : " << corral_j1[1][0] << " " << corral_j1[1][1] << endl;
        cout << "#3 : " << corral_j1[2][0] << " " << corral_j1[2][1] << endl;
        cout << "#4 : " << corral_j1[3][0] << " " << corral_j1[3][1] << endl;
        cout << "#5 : " << corral_j1[4][0] << " " << corral_j1[4][1] << endl;
        cout << "------------------------------------------" << endl;
        cin >> CARTA;
        NUMERO_CARTA = corral_j1[CARTA - 1][0];
        NUMERO_PALO = corral_j1[CARTA - 1][1];

        CARTA_ELEGIDA[0] = NUMERO_CARTA;
        CARTA_ELEGIDA[1] = NUMERO_PALO; // aca se guarda la carta elegida para intercambio

        cout << "  SELECCIONE POR QUE CARTA DESEA INTERCAMBIARLA  " << endl;
        cout << "------------------------------------------" << endl;
        cin >> CARTA_INTERCAMBIO;

        corral_j1[CARTA - 1][0] = corral_j1[CARTA_INTERCAMBIO - 1][0]; // intercambio de la primera carta seleccionada
        corral_j1[CARTA - 1][1] = corral_j1[CARTA_INTERCAMBIO - 1][1];

        corral_j1[CARTA_INTERCAMBIO - 1][0] = CARTA_ELEGIDA[0]; // intercambio de la segunda carta por la auxiliar
        corral_j1[CARTA_INTERCAMBIO - 1][1] = CARTA_ELEGIDA[1];

        //aca se desarrolla los intercambios de posiciones de los bloqueos

        // el 1ro por si la primer carta esta bloqueada y la segunda no
        // el 2do por si la segunda esta bloqueada y la primera no

        if ((cartas_bloqueadas_j1[CARTA - 1][0] == true && cartas_bloqueadas_j1[CARTA - 1][1]== true)) //pregunto si la primer carta elegida esta bloqueada
        {
            if((cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][0] == false && cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][1]== false))//pregunto si la segunda carta elegida no esta bloqueada
            {

                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][0]=true;//la nueva posicion de la primer carta carta se bloquea
                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][1]=true;

                cartas_bloqueadas_j1[CARTA-1][0]=false; //la nueva posicion de la segunda carta se desbloquea
                cartas_bloqueadas_j1[CARTA-1][1]=false;
            }
        }else if((cartas_bloqueadas_j1[CARTA - 1][0] == false && cartas_bloqueadas_j1[CARTA - 1][1]== false)) //pregunto si la primer carta elegida no esta bloqueada
        {
            if((cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][0] == true && cartas_bloqueadas_j1[CARTA_INTERCAMBIO - 1][1]== true))//pregunto si la segunda carta elegida esta bloqueada
            {

                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][0]=false;//la nueva posicion de la primer carta se desbloquea
                cartas_bloqueadas_j1[CARTA_INTERCAMBIO-1][1]=false;

                cartas_bloqueadas_j1[CARTA-1][0]=true; //la nueva posicion de la segunda carta se bloquea
                cartas_bloqueadas_j1[CARTA-1][1]=true;
            }
        }

        cout << "-----------------------------------------------------" << endl;
        cout << "Se intercambio la carta #" << CARTA << " por la #" << CARTA_INTERCAMBIO << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << endl;

    }
}

//funcion para la cara 5 del dado
void OPcion_DADO_5(string (&corral_j1)[5][2], string (&corral_j2)[5][2], string &lanzo_dado, string nombre_j1, string nombre_j2, bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2], int cantidad_repartida, bool &B_JUGADOR_BLOQUEADOR1, bool &B_JUGADOR_BLOQUEADOR2, int &CONT_BLOQUEADAS1, int &CONT_BLOQUEADAS2)
{

    int CARTA; // la carta que se eligio para bloquear
    bool bandera = false;


    if (lanzo_dado == nombre_j2) // pregunto quien lanzo el dado en la ronda anterior para saber quien sigue
    {
        if(B_JUGADOR_BLOQUEADOR2 == true){ ///cuando entre nuevamente se topara con esa bandera en true, indicando que ya bloqueo todas sus cartas este jugador
            cout << "jugador " << nombre_j2 << " bendecido con el poder del bloqueo, sigue el jugador " << nombre_j1 << endl;
            bandera = true;
        }else
        {

        cout << endl;
        cout << "OPCION #5: EL JUGADOR " << nombre_j2 << " PODRA BLOQUEAR UNA CARTA DEL CORRAL" << endl;
        cout << "===================================================================================================" << endl;

        while(bandera!=true)
        {
            cout << "   SELECCIONE UNA CARTA PARA BLOQUEAR  " << endl;
            cout << "------------------------------------------" << endl;
            cout << "#1 : " << corral_j2[0][0] << " " << corral_j2[0][1] << endl;
            cout << "#2 : " << corral_j2[1][0] << " " << corral_j2[1][1] << endl;
            cout << "#3 : " << corral_j2[2][0] << " " << corral_j2[2][1] << endl;
            cout << "#4 : " << corral_j2[3][0] << " " << corral_j2[3][1] << endl;
            cout << "#5 : " << corral_j2[4][0] << " " << corral_j2[4][1] << endl;
            cout << "------------------------------------------" << endl;
            cin >> CARTA;

            if ((cartas_bloqueadas_j2[CARTA - 1][0]== false && cartas_bloqueadas_j2[CARTA - 1][1]== false)) //pregunto si esa carta ya esta bloqueada
            {
                    cartas_bloqueadas_j2[CARTA-1][0]=true; //bloqueo de carta
                    cartas_bloqueadas_j2[CARTA-1][1]=true;
                    bandera=true;
                    CONT_BLOQUEADAS2 ++; ///cuento la carta que fue bloqueada
                    cout<<"la carta n#"<<CARTA<<" fue bloqueada"<<endl;
                    if(CONT_BLOQUEADAS2 == 5 && B_JUGADOR_BLOQUEADOR2 == false){ ///cuando cuente 5 veces CONT_BLOQUEADAS se desbloqueara esta seccion
                    cout << "felicidades, usted logro bloquear todas sus cartas, tendra un plus secreto..." << endl;
                    B_JUGADOR_BLOQUEADOR2 = true; ///le dara la ventaja al jugador 2 de que no le puedan tocar las cartas
                    }

            }else
            {
                    cout<<"esta carta ya esta bloqueada, por favor elija otra"<<endl;
            }
         }

        }
      }
      else
      {
        if(B_JUGADOR_BLOQUEADOR1 == true){ ///cuando entre nuevamente se topara con esa bandera en true, indicando que ya bloqueo todas sus cartas este jugador
            cout << "jugador " << nombre_j1 << " bendecido con el poder del bloqueo, sigue el jugador " << nombre_j2 << endl;
            bandera = true;
        }else
        {
        cout << endl;
        cout << "OPCION #5: EL JUGADOR " << nombre_j1 << " PODRA BLOQUEAR UNA CARTA DEL CORRAL" << endl;
        cout << "===================================================================================================" << endl;

        while(bandera!=true)
        {

            cout << "   SELECCIONE UNA CARTA PARA BLOQUEAR  " << endl;
            cout << "------------------------------------------" << endl;
            cout << "#1 : " << corral_j1[0][0] << " " << corral_j1[0][1] << endl;
            cout << "#2 : " << corral_j1[1][0] << " " << corral_j1[1][1] << endl;
            cout << "#3 : " << corral_j1[2][0] << " " << corral_j1[2][1] << endl;
            cout << "#4 : " << corral_j1[3][0] << " " << corral_j1[3][1] << endl;
            cout << "#5 : " << corral_j1[4][0] << " " << corral_j1[4][1] << endl;
            cout << "------------------------------------------" << endl;
            cin >> CARTA;


            if ((cartas_bloqueadas_j1[CARTA - 1][0]== false && cartas_bloqueadas_j1[CARTA - 1][1]== false)) //pregunto si es carta ya esta bloqueada
            {
                    cartas_bloqueadas_j1[CARTA-1][0]=true;
                    cartas_bloqueadas_j1[CARTA-1][1]=true;
                    bandera=true;
                    CONT_BLOQUEADAS1 ++;
                    cout<<"la carta n#"<<CARTA<<" fue bloqueada"<<endl;
                    if(CONT_BLOQUEADAS1 == 5 && B_JUGADOR_BLOQUEADOR1 == false){ ///cuando cuente 5 veces CONT_BLOQUEADAS se desbloqueara esta seccion
                    cout << "felicidades, usted logro bloquear todas sus cartas, tendra un plus secreto..." << endl;
                    B_JUGADOR_BLOQUEADOR1 = true; ///le dara la ventaja al jugador 1 de que no le puedan tocar las cartas
                    }

            }else
            {
                    cout<<"esta carta ya esta bloqueada, por favor elija otra"<<endl;
            }
         }
        }
      }
}

//funcion cara 6 del dado
void OPCION_DADO_6(string &lanzo_dado,string nombre_j1, string nombre_j2, string (&mazo)[5][4], string numero_cartas[5], string tipo_palo[4], string (&corral_j1)[5][2], string (&corral_j2) [5][2], bool (&cartas_usando) [5][4],bool (&cartas_bloqueadas_j1)[5][2], bool (&cartas_bloqueadas_j2)[5][2], int cantidad_repartida, bool &ganar_sin_sufrir_robo_j1, bool &ganar_sin_sufrir_robo_j2, bool &bandera_sin_pasar_deturnoj1, bool &bandera_sin_pasar_deturnoj2, bool &B_JUGADOR_BLOQUEADOR1, bool &B_JUGADOR_BLOQUEADOR2, int &CONT_BLOQUEADAS1, int &CONT_BLOQUEADAS2)
{
    int SELECTOR_ACCIONES;
    bool bandera = false;

    if(lanzo_dado == nombre_j2){
            cout << endl << setfill(' ');
            cout << setw(6) << "|"<< "OPCION #6: EL JUGADOR " << nombre_j2 << setw(72) << " TENDRA EL PODER DE ELEGIR TODAS LAS OPCIONES ANTERIORES... O PASAR" << left << "|" << endl;
            cout << "|" << "====================================================================================================" << left << "|" << endl;
            cout << setw(28) << "|" << setw(73) << "         SELECCIONE UNA ACCION  " << left << "|" << endl;
            cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#1 : Elegir una carta de tu propio corral y robar una carta del mazo" << left << "|" << endl;;
            cout << setw(14)<< "|" << setw(87) << "#2 : Elegir una carta del corral CONTRARIO y reemplazarla por una del mazo" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#3 : Elegir una carta del corral propio e intercambiarla por una del contrario" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#4 : Intercambiar dos cartas del propio corral" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#5 : Bloquear una carta del corral (carta no elegible para la accion 2 y 3)" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#6 : Pasar de turno" << left << "|" << endl;
            cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
            cin >> SELECTOR_ACCIONES;

            switch(SELECTOR_ACCIONES){
                case 1:
                OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2);
                break;
                case 2:
                OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2);
                break;
                case 3:
                OPCION_DADO_3(corral_j1, corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2);
                break;
                case 4:
               OPCION_DADO_4(corral_j1, corral_j2,lanzo_dado, nombre_j1, nombre_j2 ,cartas_bloqueadas_j1, cartas_bloqueadas_j2 );
                break;
                case 5:
                OPcion_DADO_5(corral_j1,corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                break;
                case 6:
                bandera_sin_pasar_deturnoj2=true;
                    cout << nombre_j2 << " PASO EL TURNO, SIGUE " << nombre_j1 << endl;
                break;
                default:
                while(SELECTOR_ACCIONES < 1 || SELECTOR_ACCIONES > 6){
                    cout << endl;
                    cout << "OPCION INCORRECTA, ELIJA SOLO LAS SIGUIENTES: " << endl << endl;
                    cout << setw(28) << "|" << setw(73) << "         SELECCIONE UNA ACCION  " << left << "|" << endl;
                    cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#1 : Elegir una carta de tu propio corral y robar una carta del mazo" << left << "|" << endl;;
                    cout << setw(14)<< "|" << setw(87) << "#2 : Elegir una carta del corral CONTRARIO y reemplazarla por una del mazo" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#3 : Elegir una carta del corral propio e intercambiarla por una del contrario" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#4 : Intercambiar dos cartas del propio corral" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#5 : Bloquear una carta del corral (carta no elegible para la accion 2 y 3)" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#6 : Pasar de turno" << left << "|" << endl;
                    cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
                    cin >> SELECTOR_ACCIONES;
                }
                break;
            }
    }else{
           cout << endl << setfill(' ');
            cout << setw(6) << "|"<< "OPCION #6: EL JUGADOR " << nombre_j1 << setw(72) << " TENDRA EL PODER DE ELEGIR TODAS LAS OPCIONES ANTERIORES... O PASAR" << left << "|" << endl;
            cout << "|" << "====================================================================================================" << left << "|" << endl;
            cout << setw(28) << "|" << setw(73) << "         SELECCIONE UNA ACCION  " << left << "|" << endl;
            cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#1 : Elegir una carta de tu propio corral y robar una carta del mazo" << left << "|" << endl;;
            cout << setw(14)<< "|" << setw(87) << "#2 : Elegir una carta del corral CONTRARIO y reemplazarla por una del mazo" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#3 : Elegir una carta del corral propio e intercambiarla por una del contrario" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#4 : Intercambiar dos cartas del propio corral" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#5 : Bloquear una carta del corral (carta no elegible para la accion 2 y 3)" << left << "|" << endl;
            cout << setw(14)<< "|" << setw(87) << "#6 : Pasar de turno" << left << "|" << endl;
            cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
            cin >> SELECTOR_ACCIONES;

            switch(SELECTOR_ACCIONES){
                case 1:
                OPCION_DADO_1(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2);
                break;
                case 2:
                OPCION_DADO_2(mazo, numero_cartas, tipo_palo, corral_j1, corral_j2, cartas_usando, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2);
                break;
                case 3:
                OPCION_DADO_3(corral_j1, corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, ganar_sin_sufrir_robo_j1, ganar_sin_sufrir_robo_j2, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2);
                break;
                case 4:
               OPCION_DADO_4(corral_j1, corral_j2,lanzo_dado, nombre_j1, nombre_j2 ,cartas_bloqueadas_j1, cartas_bloqueadas_j2 );
                break;
                case 5:
                OPcion_DADO_5(corral_j1,corral_j2, lanzo_dado, nombre_j1, nombre_j2, cartas_bloqueadas_j1, cartas_bloqueadas_j2, cantidad_repartida, B_JUGADOR_BLOQUEADOR1, B_JUGADOR_BLOQUEADOR2, CONT_BLOQUEADAS1, CONT_BLOQUEADAS2);
                break;
                case 6:
                bandera_sin_pasar_deturnoj1=true;
                    cout << nombre_j1 << "PASO EL TURNO, SIGUE " << nombre_j2 << endl;
                break;
                default:
                while(SELECTOR_ACCIONES < 1 || SELECTOR_ACCIONES > 6){
                    cout << endl;
                    cout << "OPCION INCORRECTA, ELIJA SOLO LAS SIGUIENTES: " << endl << endl;
                    cout << setw(28) << "|" << setw(73) << "         SELECCIONE UNA ACCION  " << left << "|" << endl;
                    cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#1 : Elegir una carta de tu propio corral y robar una carta del mazo" << left << "|" << endl;;
                    cout << setw(14)<< "|" << setw(87) << "#2 : Elegir una carta del corral CONTRARIO y reemplazarla por una del mazo" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#3 : Elegir una carta del corral propio e intercambiarla por una del contrario" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#4 : Intercambiar dos cartas del propio corral" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#5 : Bloquear una carta del corral (carta no elegible para la accion 2 y 3)" << left << "|" << endl;
                    cout << setw(14)<< "|" << setw(87) << "#6 : Pasar de turno" << left << "|" << endl;
                    cout << setw(19) << "|" << setw(82) << "------------------------------------------------------------------" << left << "|" << endl;
                    cin >> SELECTOR_ACCIONES;
                }
                break;
            }
    }

}
