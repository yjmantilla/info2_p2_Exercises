/*
Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).
Nota: un ejemplo de visualización de una sección de la sala es el siguiente:

+ + + +
- - + +
- - - -

Donde + representa los asientos reservados y - representa los asientos disponibles.


*/

#include <iostream>
# define rows 15
# define spots 20
# define line std::cout<<std::endl;
void print_cine(char **);
void init_cine(char **);
int itoindex(int);
int ctoindex(char);
void cancel(char, int, char **);
void reserve(char, int, char **);
void ask_spot(char & , int & );

int main()
{
    //creacion del cine, se representa como un arreglo de tamanyo rows x spots
    char **cine;
    cine = new char * [rows];//reservamos para apuntador cine 'rows' veces apuntadores a char
    for(int i=0;i<rows;i++)
    {
        //a cada fila se le reserva 'spots' veces variables char
        *(cine+i)= new char [spots];
    }

    init_cine(cine);
    int opc;
    while(1)
    {
    std::cout<<"Bienvenidos a Cines Unidos o Cinex o lo que sea, presione que desea hacer";
    line
    std::cout<<"1:Visualizar cine.";
    line
    std::cout<<"2.Reservar asiento.";
    line
    std::cout<<"3.Cancelar asiento.";
    line
    std::cout<<"4.Salir";
    line
    line
    std::cout<<"Ingrese su opcion:";
    line
    std::cin>>opc;
    line

    switch(opc)
    {
        case 1:
        {
            print_cine(cine);
            line
            break;
        }
        case 2:
        {
            line
            char c='A'; int i=1;
            ask_spot(c,i);
            line
            reserve(c,i,cine);
            break;
        }

        case 3:
        {
            line
            char c='A'; int i=1;
            ask_spot(c,i);
            line
            cancel(c,i,cine);
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            std::cout << "Error, vuelva a intentar:";
            line
            break;
        }
    }

    }

    return 0;
}


//funcion que inicializa todos los asientos del cine en asientos disponibles

void init_cine(char ** array)
{
    for (int i =0; i<rows;i++) //iteramos sobre cada fila
    {
        for (int j=0;j<spots;j++)//para cada fila iteramos los asientos
        {
            *(*(array + i)+j)='-';//volvemos la posicion i j de la matriz '-'
        }
    }
}

//funciones que permiten convertir la nomenclatura del cine a nomenclatura de C++ (de arreglos)

int ctoindex(char c)
{
    return (c-65);//65 es A en ascii
    //la idea es mapear A----->0
    //                  B----->1
    //y asi sucesivamente, luego lo que se hace es restar el offset de 65 para obtener el indice correspondiente
}

int itoindex(int i)
{
    //los asientos se numeran desde 1 y como el primer asiento para el arreglo es 0 se mapea
    //1---->0
    //2---->1
    //y asi sucesivamente
    //entonces se resta el offset de 1 para obtener el indice correspondiente
    return (i-1);
}


//funcion que dado un fila (en letras mayusculas) y el numero del asiento, lo cancela
void cancel(char row, int spot, char ** array)
{
    if(*(*(array + ctoindex(row))+itoindex(spot))=='+')
    {
        *(*(array + ctoindex(row))+itoindex(spot))='-';
        line std::cout<<"Asiento cancelado!";line line
    }
    else
    {line;std::cout<<"Error, este asiento aun no ha sido reservado";line;line;}
}

//funcion que dado un fila (en letras mayusculas) y el numero del asiento, lo reserva
void reserve(char row, int spot, char ** array)
{
    if(*(*(array + ctoindex(row))+itoindex(spot))=='-')
    {
        *(*(array + ctoindex(row))+itoindex(spot))='+';
        line std::cout<<"Asiento reservado!";line line
    }
    else
    {line std::cout<<"Error, este asiento ya fue reservado";line;line;}
            line
}

//funcion que imprime la representacion bidimensional del cine
void print_cine(char ** array)
{
    line
    std::cout<<"Filas disponibles desde A hasta ";
    std::cout<<(char) (rows + 65 - 1 );
    line
    std::cout<<("Asientos disponibles en cada fila desde 1 hasta ");
    std::cout<<spots;
    line
    line
    for (int i =0; i<rows;i++)//iteramos sobre cada fila
    {
        for (int j=0;j<spots;j++)//para cada fila imprimimos los asientos
        {
            std::cout<<*(*(array + i)+j)<<" ";
        }
        line//al terminar una fila imprimimos un salto de linea para imprimir la siguiente
    }
}

//funcion que pregunta por la fila y el numero del asiento sobre el que se desea trabajar y lo pasa por referencia
//nota: se deberia chequear si la fila y asiento existen pero por simplicidad deje el programa asumiendo que el usuario no coloca valores extraños
void ask_spot(char &c, int &i)
{
    line
    while(1)
    {
    std::cout<<"Ingrese fila del asiento:";
    line

    std::cin>>c;

    if (65<=c && c <65+rows) {break;}
    }

    while(1)
    {
    line
    std::cout<<"Ingrese numero del asiento:";
    line
    std::cin>>i;
    if (1<=i && i <=spots) {break;}
    }
    line
}
