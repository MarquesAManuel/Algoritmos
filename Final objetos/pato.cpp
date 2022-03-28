// pato.cpp
#include <iostream>
#include <stdlib.h>
#include "pato.h"
using namespace std;

Pato::Pato(string _nombre, int _codigo) :Oviparo(_nombre, _codigo)
{

};
void Pato::talk()
{
    cout << "Cuack" <<endl;
};
void Pato::comer()
{
    cout << "El pato ";
    Animal::comer();
    cout <<"lombrices,peces,semillas" <<endl;
};
void Pato::movimiento()
{
    cout << "El pato nada y vuela" << endl;
}

void Pato::mostrar()
{
    cout << "Pato" <<endl;
    Animal::mostrar();
    Oviparo::layEggs();
    Pato::talk();
};
