//menuanimales.cpp
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "menuanimales.h"
using namespace std;

Animal *vector[5];
int contador = 0;

//Cada una de estas secciones es una funcion especifica para gregar los datos de cada animal
void agregarCocodrilo()
{
    string nombre;
    int codigo;
    char aux;

    cin.ignore();
    cout<< "Ingrese el nombre del animal: ";
    getline(cin,nombre);
    cout<< "Ingrese el codigo de jaula: ";
    cin>> codigo;
    Animal *animal = new Cocodrilo(nombre,codigo);
    vector[contador] = animal;
    contador++;

}
void agregarPelicano()
{
    string nombre;
    int codigo;
    char aux;

    cin.ignore();
    cout<< "Ingrese el nombre del animal: ";
    getline(cin,nombre);
    cout<< "Ingrese el codigo de jaula: ";
    cin>> codigo;
    Animal *animal = new Pelicano(nombre,codigo);
    vector[contador] = animal;
    contador++;


}
void agregarPato()
{
    string nombre;
    int codigo;
    char aux;

    cin.ignore();
    cout<< "Ingrese el nombre del animal: ";
    getline(cin,nombre);
    cout<< "Ingrese el codigo de jaula: ";
    cin>> codigo;
    Animal *animal = new Pato(nombre,codigo);
    vector[contador] = animal;
    contador++;


}
void agregarMurcielago()
{
    string nombre;
    int codigo;
    char aux;

    cin.ignore();
    cout<< "Ingrese el nombre del animal: ";
    getline(cin,nombre);
    cout<< "Ingrese el codigo de jaula: ";
    cin>> codigo;
    Animal *animal = new Murcielago(nombre,codigo);
    vector[contador] = animal;
    contador++;


}
void agregarBallena()
{
    string nombre;
    int codigo;
    char aux;

    cin.ignore();
    cout<< "Ingrese el nombre del animal: ";
    getline(cin,nombre);
    cout<< "Ingrese el codigo de jaula: ";
    cin>> codigo;
    Animal *animal = new Ballena(nombre,codigo);
    vector[contador] = animal;
    contador++;


}
void agregarLeonMarino()
{
    string nombre;
    int codigo;
    char aux;

    cin.ignore();
    cout<< "Ingrese el nombre del animal: ";
    getline(cin,nombre);
    cout<< "Ingrese el codigo de jaula: ";
    cin>> codigo;
    Animal *animal = new LeonMarino(nombre,codigo);
    vector[contador] = animal;
    contador++;


}
//Aca termina la seccion de agregar animales


//Y aca empieza la de manejar los datos y mostrar acciones por pantalla,la primera muestra informacion en general de los animales
void mostrarDatos()
{
    for(int i=0; i < contador; i++)
    {
        cout << "/********************************************/" <<endl;
        vector[i]-> mostrar();
        cout << "/********************************************/" <<endl;
    }
}
//La segunda los alimenta
void alimentar()
{
    for(int i=0; i < contador; i++)
    {
        cout << "/********************************************/" <<endl;
        vector[i]-> comer();
        cout << "/********************************************/" <<endl;
    }
}
//Y la tercera los manda a dormir
void dormir()
{
    for(int i=0; i < contador; i++)
    {
        cout << "/********************************************/" <<endl;
        vector[i]-> dormir();
        cout << "/********************************************/" <<endl;
    }
}
//Ultima funcion para limpiar la memoria una vez terminamos
void limpiarMemoria()
{
     for(int i=0; i < 5; i++)
    {
        delete[] vector[i];
    }
}