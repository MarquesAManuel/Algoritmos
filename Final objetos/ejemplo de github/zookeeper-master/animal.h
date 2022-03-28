// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal 
{
  private:  //atributos
    string name; 
    int code;
  public:  //metodos
    void setName(string);
    string getName();
    void setCode(int);
    int getCode();
    virtual void comer();
    virtual void dormir();
    virtual void mostrar();

};

#endif
