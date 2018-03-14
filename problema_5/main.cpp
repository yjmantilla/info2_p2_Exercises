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
    int num=-123;
    char * str;
    itos(num, str);
    std::cout<<str<<std::endl;
    return 0;
}

void itos(int N, char * s)
{
    //N es el numero a convertir
    //s es el apuntador a la primera posicion de la cadena

    int i=0;//contador que recorre el arreglo de caracteres
    int j=1;//contador que recorre los digitos del numero

    //vemos si el numero es negativo, en ese caso colocamos un '-' al inicio de la cadena
    if(N < 0)
        {
            *(s+0)='-';
            i++;//aumentamos el contador del arreglo en 1 para ir al siguiente caracter
            N=N*-1;//volvemos el numero positivo, note que como
        }

    while(j<=number_of_digits(N))
        {
            *(s+i)=48 + n_digit(N,j);
            j++;
            i++;
        }
    *(s+i)='\0';
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
