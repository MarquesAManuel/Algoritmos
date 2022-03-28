#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// int x = 5, y = 12, z;
// int *p1, *p2, *p3;
// p1 = &x;
// p2 = &y;
// z = *p1 * *p2;
// p3 = &z;
// (*p3)++;
// p1 = p3;
// cout << *p1 << " " << *p2 << " " << *p3;//va a devolver 61 12 61, ya que antes de mostrar por pantalla,igualamos a p1 con p3
// //van a devolver el mismo resultado.

// int dato = 5;
// int *p1, p2; //el int p2 no esta declarado como puntero de tipo int ya que no tiene el *.
// p1 = &dato;
// p2 = p1;
// cout << *p2;

// double d = 5.4, e = 1.2, f = 0.9;
// double *p1, *p2, *p3;
// p1 = &d;
// (*p1) = (*p1) + 3;
// p2 = &e;
// (*p3) = (*p1) + (*p2);
// cout << *p1 << " " << *p2 << " " << *p3; //El problema es que a p3 no le estamos asignando ningun espacio de memoria
// //y no sabemos que dato estamos remplazando cuando le asignamos un valor,la forma correcta seria crear un int sin valor
// // y asignarle un espacio de memoria para p3 y despues usarlo.

// const int m = 8;
// const int *const p = &m;

// cout << *p; //Declaramos un int constante igual a 8 y despues creamos un puntero del tipo constante int y que ademas sea un puntero constante
// //asi no pueden ser cambiados ni a quien apunta el puntero ni el valor que contiene.

typedef struct {
string nombre;
double sueldo;
int edad;
} tRegistro;

void funcion(tRegistro *reg, double *irpf, int *edad);


int main()
{




return 0;
}

void funcion(tRegistro *reg, double *irpf, int *edad)
{
    const double tipo = 0.18;
    double a = 0;
    int b = 0;
    reg.edad++;
    irpf = &a;
    edad = &b;
    *irpf = reg.sueldo * tipo;
    *edad = reg.edad;
}
