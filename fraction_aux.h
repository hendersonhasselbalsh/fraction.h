/// biblioteca auxiliar para fraction.h usado principalmente para conversoes

#include <iostream>
#include <cstdlib>
#include <string.h> 

using namespace std;


#ifndef FRACTION_AUXILAR_LIB_H_INCLUDED
#define FRACTION_AUXILAR_LIB_H_INCLUDED


int find(const char* n, int size, const char f)
{
    int x = -1;
    for(int i = 0; i < size; i++)
    {
        if(n[i] == f){ x = i; break;}
    }
 return x;
}


bool caso_1(const char* n)
{
    int len = strlen(n);
    for(int i = 0; i < len; i++)
    {
        switch(n[i])
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
            case '.':
            break;

            default :
                return false;
            break;
        }
    }

    int f = find(n, len, '.');

 return ( (f != -1) ? true : false );
}

bool caso_2(const char* n)
{
    int len = strlen(n);
    for(int i = 0; i < len; i++)
    {
        switch(n[i])
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
            case '/':
            break;

            default :
                return false;
            break;
        }
    }

    int f = find(n, len, '/');

 return ( (f != -1) ? true : false );
}

bool caso_3(const char* n)
{
    for(unsigned int i = 0; i < strlen(n); i++)
    {
        switch(n[i])
        {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
            break;

            default :
                return false;
            break;
        }
    }

 return true;
}

int pow(int n)
{
    int resp = 1;
    for(int i = 0; i < n; i++) { resp *= 10;}
 return resp;
}

void str_frac(const char* n, int* p, int*  q)
{
    *p = 0; *q = 0;
    int len = strlen(n);

    int barra = -1;
    for(int i = 0; i < len - 1; i++)
    {
        if(n[i] == '/') { barra = i; break;}
    }
    
    if(barra == -1){cout << "erro na conversao\n";exit(1);}


    for(int i = 1; i <= barra; i++) 
    {
        *p = *p + pow(i - 1) * ((int) n[barra - i]- '0');
    }


    for(int i = 1, x = len - 1; i <= len - barra - 1; i++, x--) 
    { 
        *q = *q + pow(i - 1) * ((int) n[x] - '0');
    }
}

void str_int(const char* n , int* p, int* q)
{
    *p = 0; *q = 1;
    int len = strlen(n); len--;

    for(int i = 0; i <= len; i++)
    {
        *p = *p + pow(i) * ((int) n[len - i] - '0');
    }
}





#endif