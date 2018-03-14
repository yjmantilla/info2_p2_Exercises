/*
Problema 3. Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
de prueba.

El programa de prueba muestra varias comparaciones de string y dice si son iguales (1) o diferentes (0)
*/


#include <iostream>

//prototipos de funciones
int str_size (char * );
bool str_cmp( char * , char * );
void str_print(char * );

int main()
{
    //definicion de strings a comparar
    char str1[]= "hello world!";
    char str2[]= "hello world!";
    char str3[]= "hello world";
    char str4[]= "1234";
    char str5[]= "hello world?";

    //comparacion de los strings
    //1:true, 0:false
    std::cout<<str1<<" vs "<<str2<<std::endl<<"comparacion dio: "<<str_cmp(str1,str2);
    std::cout<<std::endl<<std::endl;

    std::cout<<str1<<" vs "<<str3<<std::endl<<"comparacion dio: "<<str_cmp(str1,str3);
    std::cout<<std::endl<<std::endl;

    std::cout<<str1<<" vs "<<str4<<std::endl<<"comparacion dio: "<<str_cmp(str1,str4);
    std::cout<<std::endl<<std::endl;

    std::cout<<str1<<" vs "<<str5<<std::endl<<"comparacion dio: "<<str_cmp(str1,str5);
    std::cout<<std::endl<<std::endl;

    return 0;
}


//funciones

//funcion de comparacion

bool str_cmp( char * a, char * b)
{
    //comenzamos asumiendo que los strings son iguales
    //cmp dice si la comparacion dio que eran iguales o distintos los strings
    bool cmp = true;

    //contador que permite recorrer el string
    int i=0;


    while(1)
    {
        //comparamos posiciones semejantes del string, si son distintas cambiamos cmp a false
        //y salimos del ciclo, ya con eso basta para que sean distintas
        if(*(a+i)!=*(b+i)){cmp = false;break;}

        //para debug:  std::cout<<cmp<<std::endl;

        //lo siguiente permite salir del cmp cuando los strings se acaban al recorrerlos
        if(*(a+i)=='\0'||*(b+i)=='\0'){break;}

        /*
         De la manera en que se implemento la funcion no es necesario saber el tamanyo de los strings.
         Se dan 2 casos posibles:
         1)son de igual tamanyo: al finalizar el loop se dice si son iguales o no y se sale por el ultimo if en caso de que sean iguales
         2)son de distinto tamanyo: la funcion va a comparar un \0 con otro caracter lo cual hara que sean distintos
         y ademas se saldra del ciclo
        */

        //pasamos a la siguiente posicion del arreglo
        i++;
    }

    return cmp;

}


//las siguientes funciones no fueron utilizadas pero las deje definidas por si se necesitan despues

//funcion que dice el tamanyo de un string

int str_size (char * a){
    //recorremos el string buscando el fin de string (\0)
    //cada vez que no lo encontremos el tamanyo aumenta en 1
    int i=0; //recorre la posicion del string

    int size=0;// da el tamanyo

    //nota: se puede prescindir de size ya que este es igual a i, pero lo deje por completitud
    while(*(a+i)!='\0')
        {
            size++;
            //std::cout<<size<<std::endl;
            i++;
        }

    return size;
}

//funcion que imprime un string
void str_print(char * a)
{

    int i=0; //contador que recorre el string
    while(*(a+i)!='\0') //mientras el string no se haya acabado
        {
            std::cout<<*(a+i); //imprimimos el caracter actual
            i++;//pasamos al siguiente
        }
}
