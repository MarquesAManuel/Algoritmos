#ifndef lista_h
#define lista_h
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Alumno
{
    char nombre[30];
    int edad;
    float promedio;
}alumno[3], *pnt_alumno = alumno;

void pedirDatos();
void mejorPromedio(Alumno *);

#endif