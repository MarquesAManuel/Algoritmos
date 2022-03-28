//murcielago.h
#ifndef MURCIELAGO_H
#define MURCIELAGO_H

#include <iostream>
#include <stdlib.h>
#include "mamifero.h"
using namespace std;

class Murcielago : public Mamifero
{
    public:
    Murcielago(string, int);
    virtual void talk();
    virtual void comer();
    virtual void mostrar();
    virtual void movimiento();
};

#endif