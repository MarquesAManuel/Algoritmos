//cocodrilo.h
#ifndef COCODRILO_H
#define COCODRILO_H

#include <iostream>
#include <stdlib.h>
#include "oviparo.h"
using namespace std;

class Cocodrilo : public Oviparo
{
    public:
    Cocodrilo(string, int);
    virtual void talk();
    virtual void comer();
    virtual void mostrar();
    virtual void movimiento();
};

#endif