#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "menuanimales.h"
using namespace std;



int main()
{
    
    //variables para manejarnos en el menu
    bool abrirSesion = true;
    char opcion;
    int animalSelect,menuSelect;
    int salir = 0;
    
    
    while(abrirSesion)
    {
        //menu principal
        cout << "Bienvenido al sistema del Zoo" <<endl;
        cout << "(a) - Agregar un animal" << endl;
        cout << "(b) - Mostrar lista de animales" << endl;
        cout << "(x) - Salir" << endl;
        cin >> opcion;
        cout << "\n" <<endl;
        switch (opcion)
        {
         case 'a':
            do
            {
                //menu para agregar animales
                cout << "Selecciona que animal quiere agregar " <<endl;
                cout << "(1) Cocodrilo" <<endl;
                cout << "(2) Pelicano" <<endl;
                cout << "(3) Pato" <<endl;
                cout << "(4) Murcielago" <<endl;
                cout << "(5) Ballena" <<endl;
                cout << "(6) Leon Marino" <<endl;
                cout << "(0) Volver al menu" <<endl;
                cin >> animalSelect;

                cout << "\n" <<endl;
                switch (animalSelect)
                {
                    case 1:
                    agregarCocodrilo();
                    break;
                    case 2:
                    agregarPelicano();
                    break;
                    case 3:
                    agregarPato();
                    break;
                    case 4:
                    agregarMurcielago();
                    break;
                    case 5:
                    agregarBallena();
                    break;
                    case 6:
                    agregarLeonMarino();
                    break;
                    case 0:
                    cout << "Volviendo al menu" <<endl;
                    salir = 1;
                    break;
                    default:
                    cout << "Opcion no valida" <<endl;
                    break;
                }
            } while (salir != 1);
            
            
         break;

         case 'b':
         salir = 0;
         do
            {
             //menu de acciones con los animales
             cout << "Selecciona que quiere hacer en el menu " <<endl;
             cout << "(1) Alimentar a los animales" <<endl;
             cout << "(2) Acostarlos a dormir" <<endl;
             cout << "(3) Mostrar planilla completa" <<endl;
             cout << "(0) Salir" <<endl;
             cin >> menuSelect;
             cout << "\n" <<endl;

             switch (menuSelect)
                {
                 case 1:
                 alimentar();
                 break;
                 case 2:
                 dormir();
                 break;
                 case 3:
                 mostrarDatos();
                 break;
                 case 0:
                 cout << "Volviendo al menu" <<endl;
                 salir = 1;
                 break;
                 default:
                 cout << "Opcion no valida" <<endl;
                 break;
                }

            } while (salir != 1);
         
         break;

         case 'x':
           cout << "Saliendo" <<endl;
           limpiarMemoria();
           abrirSesion = false;
         break;
        
         default:
           cout <<"Opcion no valida" <<endl;
         break;
        }
    }
    

    system("pause");
    return 0;
    
}