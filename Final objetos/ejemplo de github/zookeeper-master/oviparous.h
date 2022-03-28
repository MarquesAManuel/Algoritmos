// oviparous.h
#ifndef OVIPAROUS_H
#define OVIPAROUS_H

#include "animal.h"
#include <string>
using namespace std;

class oviparous : public Animal
{
  public:
    Oviparous();
    virtual void layEggs() const;
};

#endif