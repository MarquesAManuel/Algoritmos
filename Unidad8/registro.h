#ifndef registro_h
#define registro_h
#include <string>
using namespace std;

namespace lista{
//Estructura para los datos individuales de la lista
typedef struct 
{
    string nombre, apellido, carrera, dni;
    int ano;
} Alumno;

bool operator>(Alumno opIzq, Alumno opDer);//Sobrecarga de operador para comparar por los nombres
bool operator<(Alumno opIzq, Alumno opDer);//Otra sorbecarga de operador para comparar por los nombres

} //espacio de nombre lista

#endif //registro_h