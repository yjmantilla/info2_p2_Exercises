/*
Problema 5. Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use
parámetros por referencia para retornar la cadena. Escriba un programa de prueba.
Ejemplo: si recibe un int con valor 123, la cadena que se retorne debe ser “123”.
*/

#include <iostream>
int pow(int a,int b);
int number_of_digits(int a);
int n_digit(int num, int n);
void itos(int , char *);

int main()
{
    char * str;
    str = new char [23];//reservamos memoria
    int num=0; //numero a convertir
    std::cout<<"inserte el numero que desea convertir a string:"<<std::endl;
    std::cin>>num;
    std::cout<<std::endl;
    //int num2=0; //esta linea estaba antes porque sino me daba error de segmentacion
    //despues me di cuenta de que era porque no estaba reservando memoria para el puntero

    itos(num, str);
    std::cout<<str<<std::endl;
    return 0;
}



void itos(int N, char * s)
{
    //N es el numero a convertir, por valor
    //s es el apuntador a la primera posicion de la cadena, por referencia ya que es un apuntador

    int i=0;//contador que recorre el arreglo de caracteres
    int j=1;//contador que recorre los digitos del numero

    //vemos si el numero es negativo, en ese caso colocamos un '-' al inicio de la cadena
    if(N < 0)
        {
            *(s+0)='-';
            i++;//aumentamos el contador del arreglo en 1 para ir al siguiente caracter
            N=N*-1;//volvemos el numero positivo, note que como N se paso por valor no se modifica la variable original
        }

    while(j<=number_of_digits(N))
        {
            *(s+i)=48 + n_digit(N,j);
            //recorremos la cadena igualando cada elemento el enesimo digito contados de izquierda a derecha
            //el offset de 48 es debido a la conversion en la tabla ascii, 48 es el 0, entonces 48 + el enesimo digito es el enesimo digito en ascii
            j++;//pasamos al siguiente digito
            i++;//pasamos al siguiente elemento de la cadena
        }
    *(s+i)='\0';//al finalizar insertamos un fin de string en el elemento (ya i se encontraba en la siguiente posicion de memoria al ultimo caracter)
}


//esta funcion da el resultado de elevar el numero "a" a la potencia "b" cuando ambos son naturales
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

//esta funcion devuelve el numero de digitos que tiene un numero "a"
int number_of_digits(int a)
    {
    int reduccion=a;
    int potencia=10;
    int digitos=0;

    //basicamente cuenta cuantas iteraciones le toma reducir un numero entero a uno sin parte entera
    //en cada iteracion divide entre 10 el numero
    //y el numero de iteraciones es basicamente el numero de digitos que tiene el numero

    while(reduccion>0)
        {
            reduccion=a/potencia;
            potencia=potencia*10;
            digitos++;
        }
    return digitos;
    }

//esta funcion devuelve el enesimo digito contados de izquierda a derecha, por ejemplo en 1223 el primer digito es 1
//basicamente usa el hecho de que al buscar el resto de un numero entre 10 se obtiene siempre el numero que esta en el lugar de las unidades
//entonces el algoritmo primero reduce el numero dividiendolo entre la potencia de 10 correcta hasta que el digito de interes quede en las unidades
//luego saca el resto entre 10 para obtener el digito
int n_digit(int num, int n)
    {
        int digit=0;
        digit=(num/pow(10,number_of_digits(num)-n))%10;
        return digit;
    }
