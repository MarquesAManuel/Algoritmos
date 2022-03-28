#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
#include "lista.h"

void pedirfrase()
{
    cout << "Escriba una oracion: " << endl;
    cin.getline(frase,25,'\n');

    strupr(frase);

}

int contarvocales(char *letra)
{
    int cont = 0;
    while(*letra)
    {
        switch(*letra)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': cont++;
        }
        letra++;
    }

    return cont;
}