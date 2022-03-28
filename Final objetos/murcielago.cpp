// murcielago.cpp
#include <iostream>
#include <stdlib.h>
#include "murcielago.h"
using namespace std;

Murcielago::Murcielago(string _nombre, int _codigo) :Mamifero(_nombre, _codigo)
{

};
void Murcielago::talk()
{
    cout << "Skreee" <<endl;
};
void Murcielago::comer()
{
    cout << "El murcielago ";
    Animal::comer();
    cout <<"insectos" <<endl;
};
void Murcielago::movimiento()
{
    cout << "El muercielago vuela" << endl;
}

void Murcielago::mostrar()
{
    cout << "Murcielago" <<endl;
    Animal::mostrar();
    Mamifero::nurse();
    Murcielago::talk();
};
