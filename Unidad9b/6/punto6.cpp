#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "lista.h"

int main()
{
    pedirDatos();
    mostrarResultado(pnt_matriz1, filas, columnas);
    liberarMemoria();

    return 0;
}
