#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
#include "lista.h"

int main()
{
    pedirfrase();
    cout << "El numero de vocales que tiene la frase es de: " << contarvocales(frase) << endl;

    return 0;
}

