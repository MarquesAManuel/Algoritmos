//pato.h
#ifndef PATO_H
#define PATO_H

#include <iostream>
#include <stdlib.h>
#include "oviparo.h"
using namespace std;

class Pato : public Oviparo
{
    public:
    Pato(string, int);
    virtual void talk();
    virtual void comer();
    virtual void mostrar();
    virtual void movimiento();
};

#endif