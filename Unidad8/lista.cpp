#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "lista.h"

void lista::cargarLista(ListaDeAlumnos &listaDeAlumnos)
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

void lista::guardarLista(ListaDeAlumnos &listaDeAlumnos)
{
    ofstream file;
    file.open("Alumnos.txt", ios::in);
    if(file.is_open())
    {
        for(int i = 0; i < listaDeAlumnos.contador; i++)
        {
            file << listaDeAlumnos.alumnos[i].nombre<< " " << listaDeAlumnos.alumnos[i].apellido<< " " << listaDeAlumnos.alumnos[i].carrera<< " " << listaDeAlumnos.alumnos[i].dni<< " " << listaDeAlumnos.alumnos[i].ano<<endl;
        }
    }
    file.close();
}



void lista::agregarAlumno(ListaDeAlumnos &listaDeAlumnos)
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

void lista::borrarAlumno(ListaDeAlumnos &listaDeAlumnos, string nombre, string apellido)
{
    int pos = 0;
    for(int i = 0; i < listaDeAlumnos.contador; i++)
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
void lista::mostrarLista(ListaDeAlumnos &listaDeAlumnos)
{
    string nombre, apellido, carrera, dni;
    int ano;
    cout << "Listado de estudiantes: " << endl;
    for(int i = 0; i < listaDeAlumnos.contador; i++)
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


void lista::ordenarDescendente(ListaDeAlumnos &listaDeAlumnos)
{
    Alumno tmp;
    for(int i = 0; i < listaDeAlumnos.contador - 1; i++)
    {
        for(int j = listaDeAlumnos.contador - 1; j > i; j--)
        {
            if(listaDeAlumnos.alumnos[j] < listaDeAlumnos.alumnos[j - 1])
            {
                tmp = listaDeAlumnos.alumnos[j];
                listaDeAlumnos.alumnos[j] = listaDeAlumnos.alumnos[j - 1];
                listaDeAlumnos.alumnos[j - 1] = tmp;
            }
        }
    }
    
}
void lista::ordenarAscendente(ListaDeAlumnos &listaDeAlumnos)
{
    Alumno tmp;
    for(int i = 0; i < listaDeAlumnos.contador - 1; i++)
    {
        for(int j = listaDeAlumnos.contador - 1; j > i; j--)
        {
            if(listaDeAlumnos.alumnos[j] > listaDeAlumnos.alumnos[j - 1])
            {
                tmp = listaDeAlumnos.alumnos[j];
                listaDeAlumnos.alumnos[j] = listaDeAlumnos.alumnos[j - 1];
                listaDeAlumnos.alumnos[j - 1] = tmp;
            }
        }
    }
}




