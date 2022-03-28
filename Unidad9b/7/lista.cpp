#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "lista.h"

void pedirDatos()
{
    for(int i = 0; i < 3; i++)
    {
        fflush(stdin);
        cout << "Ingrese el nombre del alumno: ";
        cin.getline((pnt_alumno+i)->nombre, 30, '\n');
        cout << "Ingrese la edad del alumno: ";
        cin >> (pnt_alumno+i)->edad;
        cout << "Ingrese el promedio del alumno: ";
        cin >> (pnt_alumno+i)->promedio;
        cout << "\n";
    }
}

void mejorPromedio(Alumno *pnt_alumno)
{
    float mayor = 0.0;
    int pos = 0;

    for(int i = 0; i < 3; i++)
    {
        if((pnt_alumno+i)->promedio > mayor)
        {
            mayor = (pnt_alumno+i)->promedio;
            pos = i;
        }
    }

    cout << "\n El alumno con mejor promedio es:  \n";
    cout << "Nombre: " << (pnt_alumno+pos)->nombre << endl;
    cout << "Edad: " << (pnt_alumno+pos)->edad << endl;
    cout << "Promedio: " << (pnt_alumno+pos)->promedio <<endl;
}