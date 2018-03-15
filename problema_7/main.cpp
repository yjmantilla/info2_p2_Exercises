/*
Problema 7. Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
Ejemplo: se recibe bananas debe mostrar bans.
Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.
*/

#include <iostream>
#define max 37

//prototipos de las funciones utilizadas
bool find_char(char , char * );
void unrepeat_char(char * , char * );

int main()
{
    char * str; //string a insertar por el usuario
    char * norepeat; //string que genera el programa sin caracteres repetidos

    //reservamos memorias para no tener errores de segmentacion
    str= new char[max];
    norepeat= new char[max];


    std::cout << "Inserte una cadena de caracteres para reducirla:" <<std::endl;

    //usuario inserta el string
    std::cin.getline(str,max);

    //se genera el string sin caracteres repetidos
    unrepeat_char(str,norepeat);

    //se muestra el resultado en consola
    std::cout<<std::endl<<"Original: "<<str<<". Sin Repetidos: "<<norepeat<<"."<<std::endl;
    return 0;
}

/*
 * este procedimiento tiene como entrada dos apuntadores a arreglos de tipo char
 * uno es el string dado por el usuario y el otro es el string generado
 * basicamente lo que hace ver si cada una de las letras del string original se encuentra en el generado
 * si no se encuentra lo agrega, de lo contrario pasa al siguiente
*/
void unrepeat_char(char * source, char * target)
{
 int i=0;//contador que recorre el string original
 int j=0;//contador que recorre el string generado

 while(1)
 {
     if(!find_char(*(source+i),target))//aqui preguntamos si el caracter actual del string original se encuentra en el generado
     //si lo anterior es falso, lo copiamos en el generado
     {
         *(target+j)=*(source+i); //elemento actual del generado = elemento aun no repetido del original
         j++;//pasamos al siguiente elemento del generado
     }

     //verificamos si llegamos al fin del original, en ese caso colocamos un fin de string en el generado
     if(*(source+i)=='\0'){*(target+j)='\0';break;}

    i++;//pasamos al siguiente elemento del original
 }
}

/*
 * Esta funcion tiene como parametros un caracter y un puntero de cadena de caracteres
 * Basicamente retorna true si logra conseguir el caracter en la cadena
 * y false si no lo consigue
*/
bool find_char(char tofind, char * string)
{
    int i=0;//contador que recorre la cadena de caracteres

    while(1)
    {
        if(*(string+i)==tofind){return true;} //ya con encontrarlo una vez retornamos true, no nos interesa cuantas veces aparece
        if (*(string+i)=='\0'){return false;} //si hemos llegado al fin de string y aun no lo hemos encontrado entonces no estaba ahi, retornamos false
        i++;//pasamos al siguiente elemento de la cadena
    }
}
