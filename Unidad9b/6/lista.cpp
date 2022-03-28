#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "lista.h"




void pedirDatos()
{
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin>> columnas;

    pnt_matriz1 = new int *[filas];
    for(int i = 0; i < filas; i++)
    {
        pnt_matriz1[i] = new int [columnas];
    }

    cout <<"Ingrese los valores de la primer matriz: ";
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout << "Ingrese un numero[" <<i<<"]["<<j<<"]: ";
            cin >> *(*(pnt_matriz1+i)+j);
        }
    }


}


void mostrarResultado(int **pnt_matriz1, int filas, int columnas)
{
    cout << "La matriz transpuesta es: " << endl;
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout << *(*(pnt_matriz1+j)+i) << " ";
        }
        cout << "\n";
    }
}

void liberarMemoria()
{
    for(int i = 0; i < filas; i++)
    {
        delete[] pnt_matriz1[i];
    }
    delete[] pnt_matriz1;

}