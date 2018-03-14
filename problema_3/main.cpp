/*
Problema 3. Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
de prueba.
*/


#include <iostream>

//prototipos de funciones
int str_size (char * );
bool str_cmp( char * , char * );
void str_print(char * );

int main()
{
    char str1[]= "hello world!";
    char str2[]= "hello world!";
    char str3[]= "hello world";
    char str4[]= "1234";
    char str5[]= "hello world?";

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
bool str_cmp( char * a, char * b)
{
    bool cmp = true;
    int i=0;

    while(1)
    {
        if(*(a+i)!=*(b+i)){cmp = false;break;}
        //std::cout<<cmp<<std::endl;
        if(*(a+i)=='\0'||*(b+i)=='\0'){break;}
        i++;
    }

    return cmp;

}

int str_size (char * a){
    int i=0;
    int size=0;
    while(*(a+i)!='\0')
        {
            size++;
            //std::cout<<size<<std::endl;
            i++;
        }

    return size;
}

void str_print(char * a)
{
    int i=0;
    while(*(a+i)!='\0')
        {
            std::cout<<*(a+i);
            i++;
        }
}
