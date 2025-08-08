#ifndef TORNEO_H
#define TORNEO_H

#include <iostream>
#include <vector> //Para guardar los equipos en un vector
#include <algorithm> //Para usar shuffle y mezcle los equipos
#include <ctime> //Para usar time y crear una semilla para la mezcla de equipos aleatoriamente
#include <windows.h> //Para usar gotoxy. Creando cuadros y flechas
#include <conio.h> //Para hacer unas pausas en el programa con getch()
#include <fstream> //Para manejar archivos
#include <limits> //Para usar numeric_limits y limpie el buffer
#include <string> //La uso para leer una cadena en la parte de inscripcion
#include <sstream> //lo uso en partidos para leer un gol del archivo que esta como string
//y parasarlo a int.

#include <mysql.h>
#include <mysqld_error.h>
using namespace std;

// Variables globales
extern int numEquipos;
extern vector<string> equipos;
extern string entradaDeEquipos;
extern int golA, golB;
extern string ruta;
extern string nombreArchivo;

extern MYSQL* obj;

// Prototipos de funciones
void crearTorneo();
void inscribirEquipos();
void inscribirJug();
void sorteo();
void mezclar(vector<int> &v);
void menu();
void instrucciones();
void menuDeJuego();
void limpiarBuffer();
void conectar_base();

//Prototipo de funciones para que se jueguen los partidos
void partidoOctavos();
void partidoCuartos();
void partidoSemis();
void semiFinal2();
void partidoFinal();
void ganador();

int pedirTorneo();

//Prototipo de funciones utiles para la parte grafica
//como cuadros y flechas
void gotoxy(int x, int y);
void cuadro(int x1, int y1, int x2, int y2);
void flechas (int Fx1, int Fy1, int Fx2, int Fy2,int Fx3);
void flechasInversa (int Fx1, int Fy1, int Fx2, int Fy2,int Fx3);
void barraDeCarga(int x, int y);

//Prototipo de funciones que contiene los cuadros y flechas
void octavosFinal();
void cuartosFinal();
void semiFinal();
void Final();

//Prototipo de funciones para manejo de archivos
//void crearTorneo();
//void mezclarEquipos();

#endif
