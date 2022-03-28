// oviparo.cpp
#include <iostream>
#include <stdlib.h>
#include "oviparo.h"
using namespace std;

Oviparo::Oviparo(string _nombre, int _codigo) : Animal(_nombre, _codigo)
{

};
void Oviparo::layEggs() const
{
    cout << "Pone huevos para reproducirse" <<endl;
};
