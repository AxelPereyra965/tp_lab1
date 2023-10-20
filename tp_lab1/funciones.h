#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
using namespace std;

// Declaración de funciones
void cargar_mazo(string mazo[][4], string numero_cartas[5], string tipo_palo[4]);
void elegir_nombres(string &nombre_j1, string &nombre_j2);
string numero_aleatorio(string numero_cartas[5]);
string palo_aleatorio(string tipo_palo[4]);
void repartir_cartas_j1(bool (&cartas_usando)[5][4], string nombre_j1, string corral_j1[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);
void repartir_cartas_j2(bool (&cartas_usando)[5][4], string nombre_j2, string corral_j2[5][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);
void empieza_primero(string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &nombre_j1, string &nombre_j2, string &INICIA_PARTIDA, string &carta_repetida);
int lanzar_dado(const int caras_dado = 6);


#endif // FUNCIONES_H_INCLUDED
