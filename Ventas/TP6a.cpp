#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int MaxProduct = 50;
const int STOCK = 2;
typedef int tStock[MaxProduct][STOCK];
typedef struct
{
    tStock stock;
    double pre;
} tProducto;
typedef tProducto tArray[MaxProduct];
typedef struct
{
    tArray producto;
    int cont = 0;
}tLista;
tLista lista;
tProducto producto;
ifstream leerLista(string path);
void mostrarLista();
void maxProducto();
void eliminarProducto();
ofstream guardarCambios(string path);
void closeFile(ifstream& file);



int main()
{
    int opcion;
    ifstream readFile = leerLista("ventas.txt");
    cout << "Menu lista de almacen" << endl;
    cout << "1.Ver la lista de productos" << endl;
    cout << "2.Para ver el producto de mayor valor en el listado" << endl;
    cout << "3.Para eliminar un producto del listado" << endl;
    cout << "0.Cerrar el programa" << endl;
    cin >> opcion;
    while (opcion != 0)
    {
        switch (opcion)
        {
            case 1:
            {
                mostrarLista();
            }
            break;
            case 2:
            {
                maxProducto();
            }
            break;
            case 3:
            {
                eliminarProducto();
            }
            break;
            default:
            {
                cout << "Opcion no disponible" << endl;
            }
        }
    cout << "Menu lista de almacen" << endl;
    cout << "1.Ver la lista de productos" << endl;
    cout << "2.Para ver el producto de mayor valor en el listado" << endl;
    cout << "3.Para eliminar un producto del listado" << endl;
    cout << "0.Cerrar el programa" << endl;
    cin >> opcion;
    }
    ofstream editFile = guardarCambios("ventas.txt");

    closeFile(readFile);


    return 0;
}

ifstream leerLista(string path)
{
    int codigo,unidades;
    double precio;
    int maximo = 0;
    ifstream archivo;

    archivo.open("ventas.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo " << endl;
    }
    else
    {
        archivo >> codigo >> precio >> unidades;
        while ((codigo != -1) && (lista.cont < 50))
        {
            lista.producto[maximo].stock[maximo][0] = codigo;
            lista.producto[maximo].pre = precio;
            lista.producto[maximo].stock[maximo][1] = unidades;
            maximo++;
            lista.cont++;
            archivo >> codigo >> precio >> unidades;
        }   
    }
    return archivo;
}

void mostrarLista()
{
    int codigo,unidades;
    double precio;
    cout << "\t\t LISTA DE PRODUCTOS " << endl;
    for (int i = 0; i < lista.cont; i++)
    {
        codigo = lista.producto[i].stock[i][0];
        precio = lista.producto[i].pre;
        unidades = lista.producto[i].stock[i][1];
        cout << "Codigo: " << codigo << " Precio: " << precio << "$ Unidades disponibles: " << unidades << endl;
        cout << endl;
    }
}

void maxProducto()
{
    double valor = 0;
    int i, cod;
    for(int i = 0; i < lista.cont; i++)
    {
        if (((lista.producto[i].stock[i][1] * lista.producto[i].pre) > valor && lista.producto[i].stock[i][0] != -1) )
        {
            valor = (lista.producto[i].stock[i][1] * lista.producto[i].pre);
            cod = lista.producto[i].stock[i][0];
        }
        
    }

    cout << "El producto con mas valor en el almacen es" << endl;
    cout << "Codigo: " << cod << " Con un valor total de: " << valor << "$" << endl;
}

void eliminarProducto()
{
    int i, n, idAborrar;
    cout << "Ingrese el codigo del producto que desea eliminar: " << endl;
    cin >> idAborrar;
    for(i = 0; i <= lista.cont; i++)
    {
        if(lista.producto[i].stock[i][0] == idAborrar)
        {
            cout << "Producto eliminado " << endl;
            for(i ; i < lista.cont - 1; i++)
            {
                lista.producto[i].stock[i][0] = lista.producto[i + 1].stock[i + 1][0];
                lista.producto[i].stock[i][1] = lista.producto[i + 1].stock[i + 1][1];
                lista.producto[i].pre = lista.producto[i + 1].pre;
            }
            lista.cont--;
        }
    }
}

ofstream guardarCambios(string path)
{
    ofstream archivo;
    int i = 0;

    archivo.open("ventas.txt");

    while((lista.producto[i].stock[i][0] != -1) && (i < lista.cont))
    {
        archivo << lista.producto[i].stock[i][0] << " " << lista.producto[i].pre << " " << lista.producto[i].stock[i][1] << endl;
        i ++;
    }
    archivo << -1;
    return archivo;
}

void closeFile(ifstream& file)
{
    
    if (file.is_open())
    {
        file.close();
    }
    
}