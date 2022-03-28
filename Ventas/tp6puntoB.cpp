#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
    const int Filas = 40;
    const int Columnas = 2;
    typedef string tOraciones [Filas][Columnas];
    tOraciones oraciones;
    string frase,palabra,largo;
    int contador = 0;

    cout << "Ingrese una frase: ";
    getline(cin,frase);
    for (char x : frase) 
    {
        if ((x == ' ') || (x == ','))
        {
            oraciones[contador][0] = palabra;
            largo = (to_string(palabra.length()));
            oraciones[contador][1] = largo;
            cout << "Palabra: " << oraciones[contador][0] << " /Cantidad de letras: " << oraciones[contador][1] << endl;
            contador++;
            palabra = "";
        }
        else {
            palabra = palabra + x;
        }
    }
    oraciones[contador][0] = palabra;
    largo = (to_string(palabra.length()));
    oraciones[contador][1] = largo;
    cout << "Palabra: " << oraciones[contador][0] << " /Cantidad de letras: " << oraciones[contador][1] << endl;
    contador++;


    cin.get();
    return 0;
}