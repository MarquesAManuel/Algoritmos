#ifndef lista_h
#define lista_h
#include <string>
using namespace std;
#include "registro.h"

namespace lista{
const int MAX = 100;
//Array del registro
typedef Alumno Alumnos[MAX];

//Lista y array juntos,con un contador
typedef struct
{
    Alumnos alumnos;
    int contador;
} ListaDeAlumnos;


void cargarLista(ListaDeAlumnos &listaDeAlumnos);//Funcion que carga toda la lista de la base al array
void guardarLista(ListaDeAlumnos &listaDeAlumnos);//Funcion que guarda en la base los cambios en el array
void agregarAlumno(ListaDeAlumnos &listaDeAlumnos);//Funcion para agregar alumnos
void borrarAlumno(ListaDeAlumnos &listaDeAlumnos, string nombre, string apellido);//Funcion para eliminar a un alumno
void mostrarLista(ListaDeAlumnos &listaDeAlumnos);//Muestra la liesta en pantalla
void ordenarDescendente(ListaDeAlumnos &listaDeAlumnos);//Ordena por nombre en orden descendente
void ordenarAscendente(ListaDeAlumnos &listaDeAlumnos);//Ordena por nombre en orden Ascendente

} //espacio de nombre lista

#endif //lista_h
