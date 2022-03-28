#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;

const int MaxProd = 100;

typedef enum
{
    AddP = 1,
    RemoveP,
    ListP
} tSelector;

typedef struct
{
    int id;
    double precio;
    int unidades;
} tProducto;

typedef tProducto tLista[MaxProd + 1]; //el "+1" es para poder tener siempre la posicion del sentinela incluso con el total de productos

void Load(tLista &Lista);
void Save(tLista Lista);
int NumOfProd(tLista Lista);
void Opt(int o, tLista &Lista);
void Add(tLista &Lista);
void Remove(tLista &Lista);
double MaxFact(tLista Lista);
int ProdMaxFact(tLista Lista);
void List(tLista Lista);

int main() //Programa que trabaja con lista de productos con identificacion y valor
{
    int option;
    char exit;
    tLista Lista;
    Load(Lista);
    do
    {
        do
        {
            system("cls");
            cout << "Almacen AyED I" << endl;
            cout << "Seleccione la operación que desea: " << endl;
            cout << "1 - Agregar producto" << endl;
            cout << "2 - Eliminar producto" << endl;
            cout << "3 - Listado producto" << endl;
            cout << "Opcion [1-3]: ";
            cin >> option;
        } while (option != 1 && option != 2 && option != 3);
        Opt(option, Lista);
        cout << " " << endl;
        cout << "Desea realizar otra accion? [S/N] " << endl;
        cin >> exit;
    } while (exit != 'N' && exit != 'n');
    Save(Lista);
    return 0;
}

void Opt(int o, tLista &Lista) //Selector de operación
{
    system("cls");
    switch (o)
    {
    case AddP:
    {
        Add(Lista);
    }
    break;
    case RemoveP:
    {
        Remove(Lista);
    }
    break;
    case ListP:
    {
        List(Lista);
    }
    break;
    }
}

int NumOfProd(tLista Lista)
{
    int i, n;
    for (i = 0; i <= MaxProd; i++)
    {
        if (Lista[i].id == 0)
        {
            n = i - 1;
            i = MaxProd + 1;
        }
    }
    return n;
}

void Load(tLista &Lista) //Cargo los productos de un txt en el array
{
    int i;
    ifstream txt;
    txt.open("Productos.txt");
    if (!txt.is_open())
    {
        while ((!txt.eof()) && (i < 100))
        {
            txt >> Lista[i].id;       //codigo de barra
            txt >> Lista[i].precio;   //precio del producto
            txt >> Lista[i].unidades; //numero de unidades
            i++;
        }
    }
    else
    {
        cout << "No se encontro un archivo para cargar datos" << endl;
    }
    txt.close();
}

void Save(tLista Lista) //Guarda los productos del array en un txt
{
    ofstream txt;
    txt.open("Productos.txt");
    if (txt.is_open())
    {
        for (int i = 0; i < NumOfProd(Lista); i++)
        {
            if (Lista[i].id == Lista[i - 1].id)
            {
                i = NumOfProd(Lista);
            }
            else
            {
                txt << Lista[i].id << " ";
                txt << Lista[i].precio << " ";
                txt << Lista[i].unidades << endl;
            }
        }
    }
    txt.close();
}

void Add(tLista &Lista) //Se agrega un producto
{
    int i = NumOfProd(Lista), identification, unit, check;
    if (i < MaxProd)
    {
        cout << "Ingrese el codigo id del producto: ";
        cin >> identification;
        for (int n = 0; n = i; n++)
        {
            if (identification == Lista[i].id)
            {
                cout << "Ingrese la cantidad de producto que se vendio: ";
                cin >> unit;
                Lista[i].unidades = Lista[i].unidades + unit;
            }
            else
            {
                check++;
            }
        }
        if (check == i)
        {
            Lista[i + 1].id = identification;
            cout << "Ingrese el precio unitario del producto: ";
            cin >> Lista[i + 1].precio;
            cout << "Ingrese la cantidad de productos que se vendio: ";
            cin >> Lista[i + 1].unidades;
        }
    }
    else
    {
        cout << "No se puede agregar productos ya que se completo la lista" << endl;
    }
}

void Remove(tLista &Lista) //Se borra un producto
{
    int i, n, Delete_id;
    cout << "Ingrese el codigo del producto a eliminar: ";
    cin >> Delete_id;
    for (i = 0; i <= NumOfProd(Lista); i++)
    {
        if (Lista[i].id == Delete_id)
        {
            cout << "Producto eliminado" << endl;
            for (n = i; n < NumOfProd(Lista); n++)
            {
                Lista[i].id = Lista[i + 1].id;
                Lista[i].precio = Lista[i + 1].precio;
                Lista[i].unidades = Lista[i + 1].unidades;
            }
        }
    }
    Lista[NumOfProd(Lista)].id = 0;
    Lista[NumOfProd(Lista)].precio = 0;
    Lista[NumOfProd(Lista)].unidades = 0;
}

double MaxFact(tLista Lista) //Maximo valor facturado
{
    double max;
    for (int i = 0; i = NumOfProd(Lista); i++)
    {
        if (Lista[i].precio * Lista[i].unidades > max)
        {
            max = Lista[i].precio * Lista[i].unidades;
        }
    }
    return max;
}

int ProdMaxFact(tLista Lista) //id de maxima facturacion
{
    int product;
    double max;
    for (int i = 0; i = NumOfProd(Lista); i++)
    {
        if ((Lista[i].precio * Lista[i].unidades) > max)
        {
            product = Lista[i].id;
        }
    }
    return product;
}

void List(tLista Lista) //Suministra la lista de productos en pantalla
{
    double total;
    cout << "Lista de productos vendidos" << endl;
    cout << setw(15) << "id" << setw(8) << "precio" << setw(10) << "unidades" << endl;
    for (int i = 0; i = NumOfProd(Lista); i++)
    {
        cout << setw(15) << Lista[i].id << setw(8) << Lista[i].precio << setw(10) << Lista[i].unidades << endl;
        total = total + (Lista[i].precio * Lista[i].unidades);
    }
    cout << "Total facturado: $" << total << endl;
    cout << " " << endl;
    cout << "El producto que mas facturo es: " << ProdMaxFact(Lista) << endl;
    cout << "Total: $" << MaxFact(Lista) << endl;
}