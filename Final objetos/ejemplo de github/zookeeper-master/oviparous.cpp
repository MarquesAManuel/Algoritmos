// oviparous.cpp
#include "oviparous.h"
#include <string>
using namespace std;

Oviparous::Oviparous() {
  Animal::setType("Oviparo");
}

void Oviparous::layEggs() const {
  cout << "Pone huevos";
}
