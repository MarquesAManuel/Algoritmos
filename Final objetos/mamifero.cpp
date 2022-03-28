// mamifero.cpp
#include <iostream>
#include <stdlib.h>
#include "mamifero.h"
using namespace std;

Mamifero::Mamifero(string _nombre, int _codigo) : Animal(_nombre, _codigo)
{

};
void Mamifero::nurse() const
{
    cout << "Se reproduce mediante el parto" <<endl;
};