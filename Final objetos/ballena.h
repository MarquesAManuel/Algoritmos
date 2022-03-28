//ballena.h
#ifndef BALLENA_H
#define BALLENA_H

#include <iostream>
#include <stdlib.h>
#include "mamifero.h"
using namespace std;

class Ballena : public Mamifero
{
    public:
    Ballena(string, int);
    virtual void talk();
    virtual void comer();
    virtual void mostrar();
    virtual void movimiento();
};

#endif