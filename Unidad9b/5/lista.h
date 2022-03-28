#ifndef lista_h
#define lista_h
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void pedirDatos();
void sumarMatrices(int **, int **, int , int );
void mostrarResultado(int **, int, int);
void liberarMemoria();

int **pnt_matriz1, **pnt_matriz2, filas, columnas;

#endif
