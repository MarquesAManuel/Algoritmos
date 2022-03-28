//leonmarino.h
#ifndef LEONMARINO_H
#define LEONMARINO_H

#include <iostream>
#include <stdlib.h>
#include "mamifero.h"
using namespace std;

class LeonMarino : public Mamifero
{
    public:
    LeonMarino(string, int);
    virtual void talk();
    virtual void comer();
    virtual void mostrar();
    virtual void movimiento();
};

#endif