/*
Problema 1. Se necesita un programa que permita determinar la mínima combinación de billetes y monedas para
una cantidad de dinero determinada. Los billetes en circulación son de $50.000, $20.000, $10.000, $5.000, $2.000
y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el número de billetes
y monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas
disponibles no se puede lograr la cantidad deseada, el sistema deberá decir lo que resta para lograrla. Use arreglos
y ciclos para realizar el programa.
Ejemplo: si se ingresa 47810, el programa debe imprimir:
50000 : 0
20000: 2
10000 : 0
5000: 1
2000 : 1
1000: 0
500 : 1
200: 1
100 : 1
50: 0
Faltante: 10
*/

#include <iostream>
#define Nb 6 //numero de billetes
#define Nm 4 //numero de monedas
using namespace std;

int main()
{
    //Uso matrices de dimension numero_billetes*2. Se guarda en formato: [billete_i, cantidad del billete_i]
    //se escoje un orden descendente de monedas para que el algoritmo de la cantidad de billetes y monedas mas optimo

    int bill[Nb+Nm][2]={{50000,0},
                     {20000,0},
                     {10000,0},
                     {5000,0},
                     {2000,0},
                     {1000,0},
                     {500,0},
                     {200,0},
                     {100,0},
                     {50,0}};
    float money=0;
    cout<<"Ingrese la cantidad de dinero que desea:"<<endl;
    cin>>money;
    cout<<endl;

    for(int i=0;i<Nb+Nm;i++)
    {
        //basicamente se hace la asignacion: cantidad de billetes_i = money / billete_i
        //la division es un float / integer por lo que lo hace de manera entera

        //uso la siguiente notacion para acostumbrarme a ella...
        //*(*(bill+i)+1) recorre la 2da columna con la cantidad de billetes y monedas
        //(*(*(bill+i)+0)) recorre la 1ra columna con el valor de los billetes y monedas

        *(*(bill+i)+1)= money/(*(*(bill+i)+0));

        //imprimimos billete_i:cantidad de billete_i
        cout<<(*(*(bill+i)+0))<<" : "<<*(*(bill+i)+1)<<endl;

        //calculamos el resto parcial para repartirlo en los siguientes billetes y monedas
        //se hace la asignacion: money=money-billete_i*cantidad_de_billete_i
        money=money-(*(*(bill+i)+1))*(*(*(bill+i)+0));

        //otra forma de calcular el resto pero solo funciona para enteros: money=money%(*(*(bill+i)+0)); este no sirve ya que money es un float
        //resto parcial para ver el funcionamiento del algoritmo
        //cout<<"dinero restante: "<<money<<endl;
    }

    //imprimimos lo faltante que es money al final del for
    cout<<"Faltante: "<<money<<endl;
    return 0;
}
