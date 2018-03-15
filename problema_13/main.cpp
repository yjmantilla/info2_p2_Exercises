/*
Problema 13. Se tiene una fotografía digitalizada de una porción de la galaxia NGC 1300 que está ubicada a
61.000.000 de años luz del planeta Tierra. La representación digital de la imagen está constituida por una matriz
de números enteros; en la cual, cada uno representa la cantidad de luz en ese punto de la imagen, así:

0 3 4 0 0 0 6 8
5 13 6 0 0 0 2 3
2 6 2 7 3 0 10 0
0 0 4 15 4 1 6 0
0 0 7 12 6 9 10 4
5 0 6 10 6 4 8 0

Se puede determinar si el elemento a i,j de la matriz representa una estrella si se cumple que:
(a i,j + a i,j−1 + a i,j+1 + a i−1,j + a i+1,j)/5 > 6

Elabore y pruebe una función que reciba un puntero a la matriz de enteros como argumento y que retorne el número
de estrellas encontradas en la imagen. Ignore las posibles estrellas que puedan existir en los bordes de la matriz.

*/

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

# define line std::cout<<std::endl;

#define height 6
#define width 8
#define lower 0
#define upper 15
#define star 6

void matrix_reserve(int ** ,int,int);
void matrix_init(int ** , int , int );
void matrix_print(int **,int, int );


int main()
{
    /* initialize random seed: */
    srand (time(NULL));


    int ** galaxy;

    galaxy = new int * [height];//reservamos para apuntador 'rows' veces apuntadores a int
    for(int i=0;i<height;i++)
    {
        //a cada fila se le reserva 'columns' veces variables int
        *(galaxy+i)= new int [width];
    }

    //matrix_reserve(galaxy, height, width);
    matrix_init(galaxy,height,width);
    matrix_print(galaxy,height,width);



    return 0;
}

//por alguna razon esta funcion produce error de segmentacion
void matrix_reserve(int ** matrix,int rows,int columns)
{
        matrix = new int * [rows];//reservamos para apuntador 'rows' veces apuntadores a int
        for(int i=0;i<rows;i++)
        {
            //a cada fila se le reserva 'columns' veces variables int
            *(matrix+i)= new int [columns];
        }

}

void matrix_init(int ** matrix, int rows, int columns)
{
        for (int i =0; i<rows;i++) //iteramos sobre cada fila
        {
            for (int j=0;j<columns;j++)//para cada fila iteramos los asientos
            {
                *(*(matrix + i)+j)=(rand() + lower)%(upper+1);//volvemos la posicion i j de la matriz un numero aleatorio
            }
        }


}

void matrix_print(int ** matrix,int rows, int columns)
{
    for (int i =0; i<rows;i++)//iteramos sobre cada fila
    {
        for (int j=0;j<columns;j++)//para cada fila imprimimos los asientos
        {
            if(*(*(matrix + i)+j)>9){std::cout<<*(*(matrix + i)+j)<<" ";}
            else {std::cout<<*(*(matrix + i)+j)<<"  ";}

        }
        line//al terminar una fila imprimimos un salto de linea para imprimir la siguiente
    }
}
