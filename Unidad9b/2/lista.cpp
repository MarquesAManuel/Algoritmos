#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include "lista.h"

void pedirDatos()
{
    cout << "Cuantos numeros quiere comparar?: ";
    cin >> cantidad;

    p1 = new int[cantidad];

    for(int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese un numero [" << i << "]: ";
        cin >>*(p1+i);
    }
}

void ordenar(int *p1, int cantidad)
{
    int tmp;

    for(int i = 0; i < cantidad; i++)
    {
        for(int j = 0; j < cantidad -1; j++)
        {
            if(*(p1+j) > *(p1+j+1))
            {
                tmp = *(p1+j);
                *(p1+j) = *(p1+j+1);
                *(p1+j+1) = tmp;
            }
        }
    }
    cout << "El menor elemento del vector es: " << *p1 << endl;
}

void borrar()
{
    delete [] p1;
}