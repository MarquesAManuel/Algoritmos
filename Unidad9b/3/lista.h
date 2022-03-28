#ifndef lista_h
#define lista_h
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;


void pedirDatos();
void ordenar(int *, int);
void mostrar(int *p1, int cantidad);
void borrar();

int cantidad, *p1;

#endif