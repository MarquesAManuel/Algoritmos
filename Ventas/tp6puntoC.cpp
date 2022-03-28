#include<iostream>
using namespace std;

void sumarMatrices();
void multiplicarMatrices();
void transponerMatriz();
void puntoSilla();


int main()
{
    int opcion;
    cout << "Calculadora de matrices" << endl;
    cout << "1.Sumar matrices" << endl;
    cout << "2.Multiplicar matrices" << endl;
    cout << "3.Transponer matrices" << endl;
    cout << "4.Encontrar el punto de silla" << endl;
    cout << "0.Cerrar el programa" << endl;
    cin >> opcion;
    while (opcion != 0)
    {
        switch (opcion)
        {
            case 1:
            {
                sumarMatrices();
            }
            break;
            case 2:
            {
                multiplicarMatrices();
            }
            break;
            case 3:
            {
                transponerMatriz();
            }
            break;
            case 4:
            {
                puntoSilla();
            }
            break;
            default:
            {
                cout << "Opcion no disponible" << endl;
            }
        }
    cout << "Calculadora de Matrices" << endl;
    cout << "1.Sumar matrices" << endl;
    cout << "2.Multiplicar matrices" << endl;
    cout << "3.Transponer matrices" << endl;
    cout << "4.Encontrar el punto de silla" << endl;
    cout << "0.Cerrar el programa" << endl;
    cin >> opcion;
    }
    
    return 0; 
}

void sumarMatrices()
{
    int filas, columnas, j, i;
    cout<<"Suma de matrices "<<endl;
    cout<<"Ingrese numero de filas: ";
    cin>>filas;
    cout<<"Ingrese numero de columnas: ";
    cin>>columnas;
    cout<<"***********"<<endl;
    int mat1[filas][columnas], mat2[filas][columnas];
 
    cout<<"Llenado de matriz 1"<<endl;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
        cout<<"Ingrese numero: ";
        cin>>mat1[i][j];
        }
    }
    cout<<"\n";
    cout<<"***********"<<endl;
    cout<<"Llenado de matriz 2"<<endl;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            cout<<"Ingrese numero: ";
            cin>>mat2[i][j];
        }
    }
    cout<<"\n";
    cout<<"La matriz 1 es: "<<endl;
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            cout<<mat1[i][j]<<" ";
   
        }
        cout<<endl;
  
    }
    cout<<"\n";
    cout<<"La matriz dos es: "<<endl;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            cout<<mat2[i][j]<<" ";
   
        }
        cout<<endl;
  
    }
 
    cout<<"\n";
    cout<<"La suma de las dos matrices es:"<<endl;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            cout<<mat1[i][j]+mat2[i][j]<<" ";
   
        }
        cout<<endl;
  
    }

}

void multiplicarMatrices()
{
    //Pido medidas de las matrices
    int filaA, columA, filaB, columB, i, j, k;
    cout<<"Multiplicacion de matrices "<<endl;
    cout << "Ingrese el numero de filas de la primer matriz: " << endl;
    cin >> filaA;
    cout << "Ingrese el numero de columnas de la primer matriz: " <<endl;
    cin >> columA;

    cout << "Ingrese el numero de filas de la segunda matriz: " << endl;
    cin >> filaB;
    cout << "Ingrese el numero de columnas de la segunda matriz: " <<endl;
    cin >> columB;

    int mat1[filaA][columA], mat2[filaB][columB], producMat[filaA][columB];


    //Lleno la primer matriz con sus valores
    cout<<"\n";
    cout<<"***********"<<endl;
    cout<<"Llenado de matriz 1"<<endl;
    if(columA==filaB)
    {
        cout << "Introduzca los valores de la primer matriz: " << endl;
        for(i=0; i<filaA; i++)
        {
         for(j=0; j<columA; j++)
         {
            cout << "Ingrese numero: ";
            cin >> mat1[i][j];
         }

        }
    

        //Lleno la segunda matriz con sus valores
        cout<<"\n";
        cout<<"***********"<<endl;
        cout<<"Llenado de matriz 2"<<endl;
        
        cout << "Introduzca los valores de la segunda matriz: " << endl;
        for(i=0; i<filaB; i++)
        {
         for(j=0; j<columB; j++)
         {
            cout << "Ingrese numero: ";
            cin >> mat2[i][j];
         }

        }

        //Calculo el producto de las matrices
        for(i=0; i<filaA; i++)
        {
            for(j=0; j<columB; j++)
            {
                producMat[i][j]=0;
                for(k=0; k<columA; k++)
                {
                    producMat[i][j]+=mat1[i][k]*mat2[k][j];
                }
            }
        }

        for(i=0; i<filaA; i++)
        {
            for(j=0; j<columB; j++)
            {
                cout << producMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
     cout << "La multiplicacion de matrices no se puede realizar,la cantidad de columnas de A no es igual " << endl;
     cout << "a la cantidad de filas de la matriz B,por favor revise las matrices y vuelva a intentarlo." << endl;
    }

}

void transponerMatriz()
{
    int filas, columnas, i, j;
    cout<<"Transponer una matriz "<<endl;
    cout << "Ingrese el numero de filas de la matriz: " << endl;
    cin >> filas;
    cout << "Ingrese el numero de columnas de la matriz: " <<endl;
    cin >> columnas;

    int matr[filas][columnas];
    cout << "Introduzca los valores de la matriz: " << endl;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            cout << "Ingrese numero: ";
            cin >> matr[i][j];
        }

    }
    cout << "Matriz original: " << endl;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            cout << matr[i][j] << " ";
        }
        cout << "\n";

    }
    cout << "Matriz transpuesta: " << endl;
    for(i=0; i<columnas; i++)
    {
        for(j=0; j<filas; j++)
        {
            cout << matr[j][i] << " ";
        }
        cout << "\n";

    }



}

void puntoSilla()
{
    int filas, colum, i, j;

    cout << "Ingrese el numero de filas de la matriz: " << endl;
    cin >> filas;
    cout << "Ingrese el numero de columnas de la matriz: " <<endl;
    cin >> colum;

    int matr[filas][colum], maximoFilas[filas], minimoColum[colum];
    cout << "Introduzca los valores de la matriz: " << endl;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<colum; j++)
        {
            cout << "Ingrese numero: ";
            cin >> matr[i][j];
        }

    }

    for(i=0; i<filas; i++)
    {
        for(j=0; j<colum; j++)
        {
            if(matr[i][j] > maximoFilas[i])
            {
                maximoFilas[i] = matr[i][j];
            }
            if(matr[i][j] < minimoColum[j])
            {
                minimoColum[j] = matr[i][j];
            }
        }

    }

    for(i=0; i<filas; i++)
    {
        for(j=0; j<colum; j++)
        {
            if(maximoFilas[i] == minimoColum[j])
            {
                cout << "Punto de silla en: " << i << ", " << j << endl;
            }
        }

    }


}