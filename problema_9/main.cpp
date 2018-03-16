/*
Problema 9. Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa
debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma seria 087+512+395=994.
Nota: la salida del programa debe ser:
Original: 87512395.
Suma: 994.
*/
#include <iostream>
#define max 37

//prototipos de las funciones utilizadas
int sum_each_n(int , char *);
int str_to_int( char *, int ,int);
int pow(int ,int );
int str_size (char *);
void str_copy(char *, char *);
void zeros_to_left(char * ,char *,int);

int main()
{
    //numero entre el que se va a subdividir la cadena, lo inicializamos en 1
    int n=1;

    //definicion de los strings a trabajar

    //char str[]="87512395";
    char * str2; //str2 guardara el string con tantos ceros a la izquierda como se necesite

    char * str; //str guarda el string original

    //reserva de espacio para los strings
    str=new char[max];
    str2=new char[max];

    //Se pide al usuario la cadena de caracteres numericos original a trabajar
    std::cout << "Ingrese una cadena de caracteres numericos" <<std::endl;
    std::cin.getline(str,max);
    std::cout<<std::endl;

    //std::cout<<str_size(str)<<std::endl; //esto era para el debug

    //Se pide al usuario el numero entre el que sea va a subdividir la cadena
    std::cout << "Ingrese el numero entre el que se desea subdividir la cadena" <<std::endl;
    std::cin>>n;
    std::cout<<std::endl;

    //se procesa el string original (str) para volverlo el string con tantos ceros a la izquierda como se necesite
    zeros_to_left(str,str2,n);

    //std::cout<<std::endl<<str2<<std::endl; //para debug
    //std::cout<<std::endl<<str_to_int(str2,3,5)<<std::endl; //para debug

    //se imprimen los resultados al usuario
    std::cout<<std::endl<<"Original: "<<str<<std::endl<<"Suma: "<<sum_each_n(n,str2)<<std::endl;
    return 0;
}


//funciones auxiliares

//retorna el tamanyo de una cadena de caracteres
int str_size (char * a){
    //recorremos el string buscando el fin de string (\0)
    //cada vez que no lo encontremos el tamanyo aumenta en 1
    int i=0; //recorre la posicion del string

    while(*(a+i)!='\0')
        {
            i++;
        }

    return i;
}

//copia un string a otro
void str_copy(char * source, char * target)
{
    int i=0;//contador que recorre ambos strings de manera simultanea

    while(1)
    {
        *(target+i)=*(source+i); //copia elemento i de source a elemento i de target
        if(*(source+i)=='\0'){break;} //esto ocurre cuando ya se copio el fin de string, en ese momento solo falta salir del while
        i++;//incrementamos la posicion
    }
}

/*
 * funcion que dada una cadena de caracteres source, primero averigua cuantas posiciones le debe agregar para que
 * esta cadena sea divisible exactamente por n, dicho numero de posiciones se llamara 'pos'
 * ya sabiendo esto llena los primeros 'pos' lugares (desde 0 hasta pos-1) del string target con puros ceros
 * luego a partir de la posicion pos (que es la que viene despues del ultimo cero) copia el string original al
 * string target
*/
void zeros_to_left(char * source,char *target,int n)
{
    int pos=0;//definicion e inicializacion del numero de lugares

    //buscamos el minimo pos que asegura que el tamanyo del string sea divisible exactamente por n
    //para ello comenzamos con pos=0 y vemos si es divisible, sino aumentamos en 1 'pos'.
    //y asi sucesivamente hasta encontrar el minimo 'pos' que cumple la condicion

    while((str_size(source)+pos)%n!=0)
    {
        pos++;
    }

    //std::cout<<pos; //para debug

    //ahora llenamos con ceros las primeras 'pos' posiciones: desde 0 hasta pos-1

    int i=0;//contador que recorre el arreglo target
    int j=pos;//contador que averigua cuando ya se llenan las 'pos' posiciones de puro ceros

    //mientras no se agoten las pos posiciones que tenemos que llenar
    while(j>0)
    {
        *(target +i)='0';//igualamos el elemento actual del arreglo a 0
        i++;//pasamos al siguiente elemento
        j--;//decrecemos j en 1, cuando lleguemos a j=1 se habran llenado pos posiciones (por eso pos debe ser j>0)
    }

    //copia del arreglo original a las posiciones siguientes

    //usamos un offset en el apuntador del target y a partir de ahi copiamos
    //como target+pos-1 es las 'pos' posicion entonces las 'pos +1' posicion es pos (esto ocurre porque los arreglos empiezan en cero)
    str_copy(source, target + pos);
}

//funcion que retorna 'a' elevado a la potencia 'b', toma en consideracion cuando b es 0
int pow(int a,int b)
    {
        int potencia=a;
        if (b==0){return 1;}
        else
        {
        for(int i=1;i<b;i++)
            {
                    potencia=potencia*a;
            }
        return potencia;
        }
    }

//funcion intermedia que convirtia un string numerico completo a un entero
/*int str_to_int( char * s)
{
    int i=0;
    int N=0;
    while(1)
    {
        if(*(s+i)=='\0'){break;}
        N=N+((*(s+i)-48)*pow(10,str_size(s)-1-i));
        //std::cout<<*(s+i)<<"*"<<pow(10,str_size(s)-1-i)<<"  "<<N<<std::endl;
        i++;
    }
    return N;
}
*/

/*
 * funcion que dado un apuntador al primer elemento de un string 's' y  dos posiciones del string 'a' y 'b'
 * retorna el entero que se forma en el sub-string que se forma desde la posicion a+1 (indice a) hasta la posicion b+1 (indice b)
 *Ejemplo 123456789
 * para a=3 y b=5 se obtendra 456
*/
int str_to_int( char * s,int a,int b)
{
    //
    int i=a;//contador que recorre el arreglo desde la posicion a , (que es el a+1 digito del numero)
    int N=0;//N guardara la conversion a entero

    while(1)
    {
        if(i==b+1){break;}//cuando i ya se encuentra sobre la posicion siguiente a 'b' entonces termina (este es el b+2 digito del numero )

        //basicamente se convierte primero el contenido del elemento a un entero, debido a eso se agrega un offset de -48 debido a la codificacion ascii
        //una vez obtenido el numero se multiplica por el valor de posicion que este tiene. es decir se multiplica por la potencia de 10 correspondiente
        //experimentalmente se obtuvo que la potencia correcta se obtenia de la resta de b con i
        //ejemplo si tengo 123456789
        //posiciones:      012345678
        //aislamos 456: empezamos en a=3 (el 4) hasta b=5 (el 6)
        //el 4 debe quedar multiplicado por 100, esto es 6-4, de esta manera se obtiene que el patron es b-i

        N=N+((*(s+i)-48)*pow(10,b-i));
        //std::cout<<*(s+i)<<"*"<<pow(10,b-i)<<"  "<<N<<std::endl;

        i++;//se pasa a la siguiente posicion
    }
    return N;
}


/*
 *funcion que suma los enteros dados por sub arreglos de un string 's' cada intervalo de n caracteres
*/
int sum_each_n(int n, char * s)
{
    int sum=0;//guardara la suma
    int cycle=1;//contador que permite recorrer la subdivision del string. Si dividimos el string en n partes se deben hacer n ciclos de suma
    //los siguientes contadores i ,j son las posiciones extremas de los subarreglos que se obtienen al subdividir el arreglo de entrada 's'
    //en el primer ciclo nos encontramos con la primer subdivision, esta corresponde al substring desde la posicion 0 hasta la n-1
    int j=n-1;
    int i=0;

    while(1)
    {

    //primero chequeamos si ya hemos terminado todos los ciclos necesarios
    //esto ocurre cuando el contador ciclo supero el resultado de dividir el tamanyo del arreglo 's' entre el numero n que lo subdividio
    if(cycle>(str_size(s)/n)){break;}

    //sumamos la conversion a entero del substring formado desde la posicion i a la j a la suma acumulada
    sum= sum+ str_to_int(s,i,j);

    //std::cout<<sum<<std::endl;  //para debug

    //para pasar a la siguiente subdivision agregamos n a los contadores de posiciones
    j=j+n;
    i=i+n;

    //finalmente agregamos 1 al contador de ciclos
    cycle++;
    }

    //retornamos la suma
    return sum;
}


/*
 * Me di cuenta que este problema se podia resolver mas facilmente en la parte de hacer la suma
 * ya con el string con ceros a la izquierda se empezaba desde la primera posicion
 * se crea un acumulador de suma y dado el n que subdivide el string se empieza por la izquierda a iterar la cadena
 * se crea un contador ciclo que se resetee cada vez que hayamos sumado n numeros
 * luego con ese contador se crea la suma de la siguiente manera
 * ciclo=n;
 * sum= aij*pow(10,ciclo-1); ciclo--;
 * cuando ciclo es igual a cero se resetea ciclo=n;
 * de tal manera que si el numero es 123456 quedaria y n=3:
 * 1*100+2*10+3 --> se resetea ciclo
 * 4*100+5*10+6 --> se resetea ciclo
 * y asi sucesivamente hasta cumplir que que haya echo esto tamanyo_cadena/n veces
 * esto asumiendo que se resolvio el problema de convertir el caracter a entero
 *
 * de esta forma no es necesario crear sub-strings

*/
