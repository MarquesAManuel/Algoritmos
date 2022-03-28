#include <iostream>
using namespace std;
#include "lista.h"
#include "registro.h"

int main()
{
    lista::ListaDeAlumnos listaDeAlumnos;
    string nombre, apellido;
    int opcion;
    listaDeAlumnos.contador = 0;
    cargarLista(listaDeAlumnos);
    do
    {
        cout << "1 - Agregar un alumno" << endl;
        cout << "2 - Borrar a un alumno" << endl;
        cout << "3 - Mostrar la lista" << endl;
        cout << "4 - Ordenar la lista" << endl;
        cout << "0 - Salir" << endl;
        cin >> opcion;
        switch(opcion)
        {
            case 1:
                agregarAlumno(listaDeAlumnos);
                break;
            case 2:
                cout << "Ingrese el nombre del alumno que desee eliminar: ";
                cin >> nombre;
                cout << "Ingrese el apellido del alumno que desee eliminar: ";
                cin >> apellido;
                borrarAlumno(listaDeAlumnos, nombre, apellido);
                break;
            case 3:
                mostrarLista(listaDeAlumnos);
                break;
            case 4:
                cout << "5 - Por nombres descendente" << endl;
                cout << "6 - Por nombres ascendente" << endl;
                cin >> opcion;
                switch(opcion)
                    case 5:
                    ordenarDescendente(listaDeAlumnos);
                    break;
                    case 6:
                    ordenarAscendente(listaDeAlumnos);
                    break;
                break;
                    
            case 0:
                guardarLista(listaDeAlumnos);
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (opcion != 0);
    
    return 0;
}