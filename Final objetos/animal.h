// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <stdlib.h>
using namespace std;

//Animal
class Animal
{
    private: //aributos
        string nombre;
        int codigo;
    public: //metodos
        Animal(string, int);
        virtual void comer();
        virtual void dormir();
        virtual void mostrar();
};

#endif