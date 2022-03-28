#include <iostream>
#include <string.h>
using namespace std;
#include "lista.h"

void punto1()
{
    for(int i = 0; i < 10; i++)
    {
        int *puntero;
        puntero = &array1[i];
        if(*puntero % 2 == 0)
        {
            cout << "El numero " << *puntero << " en la direccion de memoria: " << puntero << ". Es par" << endl;
        }
        else
        {
            cout << "El numero " << *puntero << " en la direccion de memoria: " << puntero << ". Es impar" << endl;
        }

    }
}