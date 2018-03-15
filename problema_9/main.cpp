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


    zeros_to_left(str,str2,n);
    //std::cout<<std::endl<<str2<<std::endl;
    //std::cout<<std::endl<<str_to_int(str2,3,5)<<std::endl;
    std::cout<<std::endl<<"Original: "<<str<<std::endl<<"Suma: "<<sum_each_n(n,str2)<<std::endl;
    return 0;
}


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

void str_copy(char * source, char * target)
{
    int i=0;

    while(1)
    {
        *(target+i)=*(source+i);
        if(*(source+i)=='\0'){break;}
        i++;
    }
}

void zeros_to_left(char * source,char *target,int n)
{
    int m=0;

    while((str_size(source)+m)%n!=0)
    {
        m++;
    }

    //std::cout<<m;

    int i=0;
    int j=m;
    while(j>0)
    {
        *(target +i)='0';
        i++;
        j--;
    }

    str_copy(source, target + m);
}

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

int str_to_int( char * s,int a,int b)
{
    int i=a;
    int N=0;
    while(1)
    {
        if(i==b+1){break;}
        N=N+((*(s+i)-48)*pow(10,b-i));
        //std::cout<<*(s+i)<<"*"<<pow(10,str_size(s)-1-i)<<"  "<<N<<std::endl;
        i++;
    }
    return N;
}


int sum_each_n(int n, char * s)
{
    int sum=0;
    int cycle=1;
    int j=n-1;
    int i=0;

    while(1)
    {
    if(cycle>(str_size(s)/n)){break;}
    sum= sum+ str_to_int(s,i,j);
    //std::cout<<sum<<std::endl;
    j=j+n;
    i=i+n;
    cycle++;
    }
    return sum;
}
