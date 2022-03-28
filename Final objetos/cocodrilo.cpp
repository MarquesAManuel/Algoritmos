// cocodrilo.cpp
#include <iostream>
#include <stdlib.h>
#include "cocodrilo.h"
using namespace std;

Cocodrilo::Cocodrilo(string _nombre, int _codigo) :Oviparo(_nombre, _codigo)
{

};
void Cocodrilo::talk()
{
    cout << "Rawr XD" <<endl;
};
void Cocodrilo::comer()
{
    cout << "El cocodrilo ";
    Animal::comer();
    cout <<"carne de res" <<endl;
};
void Cocodrilo::movimiento()
{
    cout << "El cocodrilo repta" << endl;
}

void Cocodrilo::mostrar()
{
    cout << "Cocodrilo" <<endl;
    Animal::mostrar();
    Oviparo::layEggs();
    Cocodrilo::talk();
};
