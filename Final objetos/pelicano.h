//pelicano.h
#ifndef PELICANO_H
#define PELICANO_H

#include <iostream>
#include <stdlib.h>
#include "oviparo.h"
using namespace std;

class Pelicano : public Oviparo
{
    public:
    Pelicano(string, int);
    virtual void talk();
    virtual void comer();
    virtual void mostrar();
    virtual void movimiento();
};

#endif