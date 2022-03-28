#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "lista.h"
using namespace std;

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
    
    pnt_matriz2 = new int *[filas];
    for(int i = 0; i < filas; i++)
    {
        pnt_matriz2[i] = new int [columnas];
    }
    
    
    
    cout <<"Ingrese los valores de la segunda matriz: ";
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout << "Ingrese un numero[" <<i<<"]["<<j<<"]: ";
            cin >> *(*(pnt_matriz2+i)+j);
        }
    }


}

void sumarMatrices(int **pnt_matriz1, int **pnt_matriz2, int filas, int columnas)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            *(*(pnt_matriz1+i)+j) += *(*(pnt_matriz2+i)+j);
        }
    }
}

void mostrarResultado(int **pnt_matriz1, int filas, int columnas)
{
    cout << "El resultado de la suma es: " << endl;
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout << *(*(pnt_matriz1+i)+j) << " ";
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

    for(int i = 0; i < filas; i++)
    {
        delete[] pnt_matriz2[i];
    }
    delete[] pnt_matriz2;
}