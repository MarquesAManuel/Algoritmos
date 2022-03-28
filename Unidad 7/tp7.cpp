#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX = 100;
typedef struct
{
    string nombre, apellido, carrera, dni;
    int ano;
} Alumno;

typedef Alumno Alumnos[MAX];

typedef struct
{
    Alumnos alumnos;
    int contador;
} ListaDeAlumnos;

int i;
void cargarLista(ListaDeAlumnos &listaDeAlumnos);
void guardarLista(ListaDeAlumnos &listaDeAlumnos);
void agregarAlumno(ListaDeAlumnos &listaDeAlumnos);
void borrarAlumno(ListaDeAlumnos &listaDeAlumnos, string nombre, string apellido);
void mostrarLista(ListaDeAlumnos &listaDeAlumnos);
void ordenarDescendente(ListaDeAlumnos &listaDeAlumnos);
void ordenarAscendente(ListaDeAlumnos &listaDeAlumnos);
bool operator<(Alumno &alumnIzq, Alumno &alumnDer);
bool operator>(Alumno &alumnIzq, Alumno &alumnDer);

 //espacio de nombre lista


int main()
{
    ListaDeAlumnos listaDeAlumnos;
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

void cargarLista(ListaDeAlumnos &listaDeAlumnos)
{
    ifstream file;
    file.open("Alumnos.txt", ios::in);
    if(!file.is_open())
    {
        cout << "Error de apertura del archivo!" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file >> listaDeAlumnos.alumnos[listaDeAlumnos.contador].nombre;
            file.get();
            file >> listaDeAlumnos.alumnos[listaDeAlumnos.contador].apellido;
            file.get();
            file >> listaDeAlumnos.alumnos[listaDeAlumnos.contador].carrera;
            file.get();
            file >> listaDeAlumnos.alumnos[listaDeAlumnos.contador].dni;
            file >> listaDeAlumnos.alumnos[listaDeAlumnos.contador].ano;

            if((!listaDeAlumnos.alumnos[listaDeAlumnos.contador].nombre.empty())&&(!listaDeAlumnos.alumnos[listaDeAlumnos.contador].apellido.empty())&&(!listaDeAlumnos.alumnos[listaDeAlumnos.contador].carrera.empty())&&(!listaDeAlumnos.alumnos[listaDeAlumnos.contador].dni.empty())&&(listaDeAlumnos.alumnos[listaDeAlumnos.contador].ano != 0))
            {
                listaDeAlumnos.contador++;
            }
        }
    }
    file.close(); 
}

void guardarLista(ListaDeAlumnos &listaDeAlumnos)
{
    ofstream file;
    file.open("Alumnos.txt", ios::in);
    if(file.is_open())
    {
        for(i = 0; i < listaDeAlumnos.contador; i++)
        {
            file << listaDeAlumnos.alumnos[i].nombre<< " " << listaDeAlumnos.alumnos[i].apellido<< " " << listaDeAlumnos.alumnos[i].carrera<< " " << listaDeAlumnos.alumnos[i].dni<< " " << listaDeAlumnos.alumnos[i].ano<<endl;
        }
    }
    file.close();
}

void mostrarLista(ListaDeAlumnos &listaDeAlumnos)
{
    string nombre, apellido, carrera, dni;
    int ano;
    cout << "Listado de estudiantes: " << endl;
    for(i = 0; i < listaDeAlumnos.contador; i++)
    {
        nombre = listaDeAlumnos.alumnos[i].nombre;
        apellido = listaDeAlumnos.alumnos[i].apellido;
        carrera = listaDeAlumnos.alumnos[i].carrera;
        dni = listaDeAlumnos.alumnos[i].dni;
        ano = listaDeAlumnos.alumnos[i].ano;
        cout << "Alumno: " << nombre << " " << apellido << ". DNI: " << dni << " De la carrera: " << carrera << " año: " << ano << endl;
        cout << endl;
    }
}

void agregarAlumno(ListaDeAlumnos &listaDeAlumnos)
{
    if(listaDeAlumnos.contador < MAX)
    {
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(cin, listaDeAlumnos.alumnos[listaDeAlumnos.contador].nombre);
        cout << "Ingrese el apellido del alumno: ";
        getline(cin, listaDeAlumnos.alumnos[listaDeAlumnos.contador].apellido);
        cout << "Ingrese la carrera del alumno: ";
        getline(cin, listaDeAlumnos.alumnos[listaDeAlumnos.contador].carrera);
        cout << "Ingrese el numero de DNI del alumno: ";
        getline(cin, listaDeAlumnos.alumnos[listaDeAlumnos.contador].dni);
        cout << "Ingrese en que ano de la carrera esta el alumno: ";
        cin >> listaDeAlumnos.alumnos[listaDeAlumnos.contador].ano;
        listaDeAlumnos.contador = (listaDeAlumnos.contador + 1);

    }
    else
    {
        cout << "Maximo de alumnos en la lista alcanzado (100!)" << endl;
    }
}

void borrarAlumno(ListaDeAlumnos &listaDeAlumnos, string nombre, string apellido)
{
    int pos = 0;
    for(i = 0; i < listaDeAlumnos.contador; i++)
    {
        if((listaDeAlumnos.alumnos[i].nombre == nombre)&&(listaDeAlumnos.alumnos[i].apellido == apellido))
        {
            pos = i;
            for(i = pos; i < listaDeAlumnos.contador -1; i++)
            {
                listaDeAlumnos.alumnos[i] = listaDeAlumnos.alumnos[i+1];
            }
            listaDeAlumnos.contador = (listaDeAlumnos.contador -1);
            cout << "Alumno eliminado correctamente!" << endl;
        }
    }
}

void ordenarDescendente(ListaDeAlumnos &listaDeAlumnos)
{
    for(int i = 1; i < listaDeAlumnos.contador; i++)
    {
        int pos = i;
        while((pos > 0) && (listaDeAlumnos.alumnos[pos -1] < listaDeAlumnos.alumnos[pos]))
        {
            Alumno tmp;
            tmp = listaDeAlumnos.alumnos[pos];
            listaDeAlumnos.alumnos[pos] = listaDeAlumnos.alumnos[pos -1];
            listaDeAlumnos.alumnos[pos -1] = tmp;
            pos--;
        }
        
    }
}
void ordenarAscendente(ListaDeAlumnos &listaDeAlumnos)
{
    for(int i = 1; i < listaDeAlumnos.contador; i++)
    {
        int pos = i;
        while((pos > 0) && (listaDeAlumnos.alumnos[pos -1] > listaDeAlumnos.alumnos[pos]))
        {
            Alumno tmp;
            tmp = listaDeAlumnos.alumnos[pos];
            listaDeAlumnos.alumnos[pos] = listaDeAlumnos.alumnos[pos -1];
            listaDeAlumnos.alumnos[pos -1] = tmp;
            pos--;
        }
        
    }
}



bool operator<(Alumno alumnIzq, Alumno alumnDer)
{
    return(alumnIzq.nombre < alumnDer.nombre);
}
bool operator>(Alumno alumnIzq, Alumno alumnDer)
{
    return(alumnIzq.nombre > alumnDer.nombre);
}
