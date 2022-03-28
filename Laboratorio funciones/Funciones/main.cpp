#include <iostream>
using namespace std;
#include <cmath>

// Prototipos de las funciones (excepto main())
// Etapa I - Definicion de Prototipos de Funciones.
// noten los parámetros que son los tipos declarados en el prototipo
bool par(int num);
bool letra(char car);
int suma(int num);
double formula(int x, int y);


int main() {
   int numero, sum, x, y;
   char caracter;
   double f;
   cout << "Entero: ";
   cin >> numero;
   //Cuando se realiza una llamada a la función, los "valores" pasados se denominan argumentos
   //En es te caso la Funcion se llama "par" y el argumento pasado es "numero"
   if (par(numero)) {
      cout << "Par";
   }
       else {
      cout << "Impar";
   }
   cout << endl;
   if (numero > 1) {
      cout << "Sumatorio de 1 a " << numero << ": "
           << suma(numero) << endl;
   }
   cout << "Carácter: ";
   cin >> caracter;
   if (!letra(caracter)) {
      cout << "no ";
   }
   cout << "es una letra" << endl;
   cout << "f(x, y) = " << formula(x, y) << endl;
   // Los argumentos pueden llamarse igual o no que los parámetros

   return 0;
}
    // Implementación de las funciones propias
    // noten la implementacion separada de la deficion y el uso

bool par(int num) {
   bool esPar;

   if (num % 2 == 0) {
      esPar = true;
   }
   else {
      esPar = false;
   }

   return esPar;
}
bool letra(char car) {
   bool esLetra;
   if ((car >= 'a') && (car <= 'z') || (car >= 'A') && (car <= 'Z')) {
      esLetra = true;
   }
   else {
      esLetra = false;
   }
   return esLetra;
}

int suma(int num) {
   int sum = 0, i = 1;
   while (i < num) {
      sum = sum + i;
      i++;
   }
   return sum;
}
double formula(int x, int y) {
   double f;

   f = 2 * pow(x, 5) + sqrt(pow(x, 3) / pow(y, 2))
         / abs(x * y) - cos(y);

   return f;
}
