// oviparo.h
#ifndef OVIPARO_H
#define OVIPARO_H

#include <iostream>
#include <stdlib.h>
#include "animal.h"
using namespace std;

class Oviparo : public Animal
{
    public:
       Oviparo(string, int);
       virtual void layEggs() const;
};

#endif