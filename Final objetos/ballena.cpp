// ballena.cpp
#include <iostream>
#include <stdlib.h>
#include "ballena.h"
using namespace std;

Ballena::Ballena(string _nombre, int _codigo) :Mamifero(_nombre, _codigo)
{

};
void Ballena::talk()
{
    cout << "Whoooooooo" <<endl;
};
void Ballena::comer()
{
    cout << "La ballena ";
    Animal::comer();
    cout <<"plancton y algas" <<endl;
};
void Ballena::movimiento()
{
    cout << "La ballena nada" << endl;
}

void Ballena::mostrar()
{
    cout << "Ballena" <<endl;
    Animal::mostrar();
    Mamifero::nurse();
    Ballena::talk();
};
