// animal.cpp
#include <iostream>
#include <stdlib.h>
#include "animal.h"
using namespace std;

Animal::Animal(string _nombre, int _codigo)
{
    nombre = _nombre;
    codigo = _codigo;
};
void Animal::comer()
{
    cout << "esta comiendo ";
};
void Animal::dormir()
{
    cout << nombre << " se acosto a dormir " << endl;
}
void Animal::mostrar()
{
    cout << "Nombre del animal: " << nombre <<endl;
    cout << "Codigo de la jaula: " << codigo <<endl;
};