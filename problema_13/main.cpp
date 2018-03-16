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

#define height 6 //altura de la imagen
#define width 8 //ancho de la imagen
#define lower 0 //minima luz de un punto de la imagen
#define upper 15 //maxima luz de un punto de la imagen
#define min_star 6 //minimo valor para que se considere una estrella

//prototipos de funciones
void matrix_reserve(int ** ,int,int);
void matrix_init_rand(int ** , int , int );
void matrix_print_int(int **,int, int );
void matrix_print_char(char **,int, int );
bool DoesItExist(int , int , int , int );
bool star(int ** , int , int , int , int );
void matrix_init_spaces(char ** , int , int );
int number_of_stars(int ** ,int , int );
void locate_stars(int ** ,char ** ,int, int );

int main()
{
    /*se creara un arreglo aleatorio para llenar la matriz de la imagen de la galaxia*/
    /* initialize random seed: */
    srand (time(NULL));


    int ** galaxy; /*La matriz de la galaxia*/
    char **stars; /*Matriz que guardara la posicion de las estrellas*/

    /*Reserva de las matrices:*/

    galaxy = new int * [height];//reservamos para apuntador 'rows' veces apuntadores a int
    for(int i=0;i<height;i++)
    {
        //a cada fila se le reserva 'columns' veces variables int
        *(galaxy+i)= new int [width];
    }

    stars = new char * [height];//reservamos para apuntador 'rows' veces apuntadores a int
    for(int i=0;i<height;i++)
    {
        //a cada fila se le reserva 'columns' veces variables char
        *(stars+i)= new char [width];
    }

    /* Se habia creado una funcion que reservaba una matriz pero tiene problemas */
    //matrix_reserve(galaxy, height, width); //esta funcion da problemas de segmentacion


    /*Inicializacion de la matriz galaxia con enteros aleatorios*/
    matrix_init_rand(galaxy,height,width);

    /*Inicializacion de la matriz que muestra la posicion de las estrellas*/
    matrix_init_spaces(stars,height,width);

    /*Se comienza la interaccion con el usuario*/

    std::cout<<"Se mostrara la matriz de la cantidad de luz en cada punto de la imagen:";
    line line

    /*Se muestra al usuario la matriz de la galaxia que se va a utilizar*/
    matrix_print_int(galaxy,height,width);
    line line

    /*Se muestra el numero de estrellas encontradas*/
    line line
    std::cout<<"Se han encontrado "<<number_of_stars(galaxy,height,width)<<" estrellas en la galaxia.";
    line line

    /*Se muestra la ubicacion de las estrellas*/
    std::cout<<"A continuacion se mostrara la ubicacion de las estrellas en la galaxia:";
    line line
    locate_stars(galaxy,stars,height,width);
    line line
    matrix_print_char(stars,height,width);
    line line
    return 0;
}

/*Funcion que reservaba una matriz de tamanyo rowsxcolums, pero da error de segmentacion*/
void matrix_reserve(int ** matrix,int rows,int columns)
{
        matrix = new int * [rows];//reservamos para apuntador 'rows' veces apuntadores a int
        for(int i=0;i<rows;i++)
        {
            //a cada fila se le reserva 'columns' veces variables int
            *(matrix+i)= new int [columns];
        }

}

/*Funcion que inicializa una matrix de enteros de tamanyo rowsxcolumns con numeros enteros aleatorios*/
void matrix_init_rand(int ** matrix, int rows, int columns)
{
        for (int i =0; i<rows;i++) //iteramos sobre cada fila
        {
            for (int j=0;j<columns;j++)//para cada fila iteramos las columnas
            {
                *(*(matrix + i)+j)=(rand() + lower)%(upper+1);//volvemos la posicion i j de la matriz un numero aleatorio
                /*la expresion (rand() + lower)%(upper+1) la saque de internet, aun no la entiendo del todo*/
            }
        }

}

/*Funcion que inicializa una matrix de caracteres de tamanyo rowsxcolumns con el caracter de espacio*/
void matrix_init_spaces(char ** matrix, int rows, int columns)
{
        for (int i =0; i<rows;i++) //iteramos sobre cada fila
        {
            for (int j=0;j<columns;j++)//para cada fila iteramos las columnas
            {
                *(*(matrix + i)+j)=' ';//volvemos la posicion i j de la matriz un numero aleatorio
            }
        }

}

/*
 * NOTA: Las dos funciones de inicializacion se pueden modificar para que se le pase
 * el valor de la inicializacion como un argumento.
 * Sin embargo en el caso de la inicializacion aleatoria no serviria porque llenaria la matriz
 * con el mismo numero aleatorio en todas sus posiciones
*/

/*Funcion que imprime una matriz de enteros de tamanyo rowsxcolumns*/

void matrix_print_int(int ** matrix,int rows, int columns)
{
    for (int i =0; i<rows;i++)//iteramos sobre cada fila
    {
        for (int j=0;j<columns;j++)//para cada fila imprimimos las columnas
        {
            /*
             * Se trata de imprimir la matriz con el formato correcto de tal manera que quede recta
             * Ejemplo:
             *
             * Sin formato correcto
             * 10 11
             * 1 2
             *
             * Con formato correcto:
             * 10 11
             *  1  2
             *
             * Si el numero es de dos digitos (es mayor a 9 ya que los aleatorios que creamos son menores o iguales a 15 se imprime un solo espacio.
             * En otro caso el numero debe ser de un digito segun la condicion ya dada de los aleatorios generados, se imprimen dos espacios
             *
             * Falta crear funcion que devuelva tantos espacios como sean necesarios segun el orden del numero
             */
            if(*(*(matrix + i)+j)>9){std::cout<<*(*(matrix + i)+j)<<" ";}
            else {std::cout<<*(*(matrix + i)+j)<<"  ";}

        }
        line//al terminar una fila imprimimos un salto de linea para imprimir la siguiente
    }
}

/*Funcion que imprime una matriz de caracteres de tamanyo rowsxcolumns*/

void matrix_print_char(char ** matrix,int rows, int columns)
{
    for (int i =0; i<rows;i++)//iteramos sobre cada fila
    {
        for (int j=0;j<columns;j++)//para cada fila imprimimos las columnas
        {
            std::cout<<*(*(matrix + i)+j)<<" ";
        }
        line//al terminar una fila imprimimos un salto de linea para imprimir la siguiente
    }
}

/*
 * Decidi no ignorar los bordes de la foto, por eso necesito esta funcion. para saber si el elemento i,j de la matriz existe.
 */
bool DoesItExist(int i, int j, int rows, int columns)
{
    bool exist;
    /*
	Basicamente el elemento i,j existe si se cumplen las siguientes dos condiciones:
	0<=i<rows (de 0 a rows-1)
	0<=j<columns (de 0 a columns-1)
    */
    exist=(0<= i && i<rows)&&(0<=j && j<columns);
    return exist;
}

/*
	Esta funcion realiza el promedio del punto ij sumado con los puntos inmeadiatamente alreadedor de el en forma de cruz(si existen).
	Ejemplo:
	b	
      d a c ---> (a+b+c+d+e)/5, en caso de que este en una esquina ignora ese numero, para lograr eso pregunta si el punto ij existe en la matriz y lo suma si existe.
	e
*/
bool star(int ** matrix, int i, int j, int rows, int columns)
{
    float sum=0; /*Acumula la suma, siempre que el elemento exista, se le suma el elemento, sino no hace nada*/

    if(DoesItExist(i,j,rows,columns)){sum=sum+*(*(matrix+i)+j);} //punto medio

    if(DoesItExist(i,j-1,rows,columns)){sum=sum+*(*(matrix+i)+j-1);} //punto izquierda

    if(DoesItExist(i,j+1,rows,columns)){sum=sum+*(*(matrix+i)+j+1);} //punto derecha

    if(DoesItExist(i-1,j,rows,columns)){sum=sum+*(*(matrix+i-1)+j);} //punto arriba

    if(DoesItExist(i+1,j,rows,columns)){sum=sum+*(*(matrix+i+1)+j);} //punto abajo

    sum=sum/5;//se divide para obtener el promedio

    if (sum>min_star){return true;} //si el promedio es mayor que el minimo requerido entonces el punto ij es una estrella
    else{return false;}
}

/*
	Esta funcion retorna cuantas estrellas hay en la matriz de entrada
*/
int number_of_stars(int ** matrix,int rows, int columns)
{
    int N=0;//numero de estrellas
	
    //iteramos sobre todos los elementos de la matriz

    for (int i =0; i<rows;i++)//iteramos sobre cada fila
    {
        for (int j=0;j<columns;j++)//para cada fila iteramos las columnas
        {
            if(star(matrix,i,j,rows,columns)){N++;} //preguntamos si el punto actual es una estrella , en ese caso aumentamos el contador
        }

    }
    return N;
}

/* 
	Funcion que dada una matriz de entrada (source) rowsxcolumns de la galaxia, ubica en otra del mismo tamanyo (target) las posiciones de las estrellas
	marca con 'x' las estrellas y con '_' los puntos que no son estrellas.
*/
void locate_stars(int ** source,char ** target,int rows, int columns)
{

    for (int i =0; i<rows;i++)//iteramos sobre cada fila
    {
        for (int j=0;j<columns;j++)//para cada fila iteramos las columnas
        {
            if(star(source,i,j,rows,columns)){*(*(target+i)+j)='x';}//si el punto ij de source es una estrella entonces llena el punto ij del target con 'x'
            else {*(*(target+i)+j)='_';} //si no es una estrella el punto ij entonces se llena con '_'
        }

    }
}
