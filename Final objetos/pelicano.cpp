// pelicano.cpp
#include <iostream>
#include <stdlib.h>
#include "pelicano.h"
using namespace std;

Pelicano::Pelicano(string _nombre, int _codigo) :Oviparo(_nombre, _codigo)
{

};
void Pelicano::talk()
{
    cout << "Chaja" <<endl;
};
void Pelicano::comer()
{
    cout << "El pelicano ";
    Animal::comer();
    cout <<"peces" <<endl;
};
void Pelicano::movimiento()
{
    cout << "El pelicano vuela" <<endl;
}

void Pelicano::mostrar()
{
    cout << "Pelicano" <<endl;
    Animal::mostrar();
    Oviparo::layEggs();
    Pelicano::talk();

};