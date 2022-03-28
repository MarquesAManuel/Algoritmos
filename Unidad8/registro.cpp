#include <iostream>
#include <string>
using namespace std;
#include "registro.h"

bool lista::operator<(Alumno opIzq, Alumno opDer)
{
    return (opIzq.nombre < opDer.nombre);
}
bool lista::operator>(Alumno opIzq, Alumno opDer)
{
    return (opIzq.nombre > opDer.nombre);
}


