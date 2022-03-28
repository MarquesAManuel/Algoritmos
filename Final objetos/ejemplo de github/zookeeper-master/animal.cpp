// animal.cpp
#include <iostream>
#include "animal.h"
#include <string>
using namespace std;

void Animal::setName(string animalName){
  name = animalName; 
};

string Animal::getName() {
  return name;
};

void Animal::setCode(int animalCode){
  code = animalCode;
};

string Animal::getCode() {
  return code;
};

void Animal::mostrar()
{
    cout << "Nombre: " << getName() <<endl;
    cout << "Codigo: " << getCode() <<endl;
};

void::Animal::comer()
{
    cout << "Come " <<endl;
}

void::Animal::dormir()
{
    cout << "Duerme en " <<endl;
}
