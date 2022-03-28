#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "lista.h"


int main()
{
    pedirDatos();
    sumarMatrices(pnt_matriz1, pnt_matriz2, filas, columnas);
    mostrarResultado(pnt_matriz1, filas, columnas);
    liberarMemoria();

    return 0;
}
