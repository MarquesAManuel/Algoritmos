// leonmarino.cpp
#include <iostream>
#include <stdlib.h>
#include "leonmarino.h"
using namespace std;

LeonMarino::LeonMarino(string _nombre, int _codigo) :Mamifero(_nombre, _codigo)
{

};
void LeonMarino::talk()
{
    cout << "Ow ow ow" <<endl;
};
void LeonMarino::comer()
{
    cout << "El leon marino ";
    Animal::comer();
    cout <<"pescados" <<endl;
};
void LeonMarino::movimiento()
{
    cout << "El leon marino se arrastra y nada" << endl;
}

void LeonMarino::mostrar()
{
    cout << "LeonMarino" <<endl;
    Animal::mostrar();
    Mamifero::nurse();
    LeonMarino::talk();
};
