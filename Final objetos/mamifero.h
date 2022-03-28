// mamifero.h
#ifndef MAMIFERO_H
#define MAMIFERO_H

#include <iostream>
#include <stdlib.h>
#include "animal.h"
using namespace std;

class Mamifero : public Animal
{
    public:
       Mamifero(string, int);
       virtual void nurse() const;
};

#endif