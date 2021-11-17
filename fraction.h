//// fraction.h

#include <iostream>
#include <cstdlib>
#include <string>
#include <valarray>
#include <sstream>
#include "fraction_aux.h"

using namespace std;


#ifndef FRACOES_H_INCLUDED
#define FRACOES_H_INCLUDED

int mdc(int a, int b)
{
    while(b != 0){ int aux = a % b;  a = b; b = aux; }
 return a;
}


struct fraction{

    int p = 0;
    int q = 0;
    
    fraction(){}
    fraction(int _p, int _q);
    fraction(double n, int cycles = 10, double precision = 5e-4);
    fraction(const char* n);

    void simplifica();

    void operator=(fraction a);
    void operator=(double a);

    friend ostream& operator<<(ostream& os, fraction a);
    friend istream& operator>>(istream& os, fraction& a);

    friend fraction operator~(fraction b);
    friend fraction operator!(fraction b);

    friend fraction operator+(fraction a, fraction b);
    friend fraction operator+(const int a, fraction b);
    friend fraction operator+(fraction b, const int a);
    friend void operator+=(fraction& a, fraction& b);
    friend void operator+=(fraction& b, const int a);
    friend fraction operator+(const double a, fraction b);
    friend fraction operator+(fraction b, const double a);
    friend void operator+=(fraction& b, const double a);

    friend fraction operator-(fraction a, fraction b);
    friend fraction operator-(const int a, fraction b);
    friend fraction operator-(fraction b, const int a);
    friend void operator-=(fraction& a, fraction& b);
    friend void operator-=(fraction& b, const int a);
    friend fraction operator-(const double a, fraction b);
    friend fraction operator-(fraction b, const double a);
    friend void operator-=(fraction& b, const double a);

    friend fraction operator*(fraction a, fraction b);
    friend fraction operator*(const int a, fraction b);
    friend fraction operator*(fraction b, const int a);
    friend void operator*=(fraction& a, fraction& b);
    friend void operator*=(fraction& b, const int a);
    friend fraction operator*(const double a, fraction b);
    friend fraction operator*(fraction b, const double a);
    friend void operator*=(fraction& b, const double a);

    friend fraction operator/(fraction a, fraction b);
    friend fraction operator/(const int a, fraction b);
    friend fraction operator/(fraction b, const int a);
    friend void operator/=(fraction& a, fraction& b);
    friend void operator/=(fraction& b, const int a);
    friend fraction operator/(const double a, fraction b);
    friend fraction operator/(fraction b, const double a);
    friend void operator/=(fraction& b, const double a);

    double to_double();
    friend bool operator<(fraction a, fraction b);
    friend bool operator<(fraction a, int b);
    friend bool operator<(int b, fraction a);
    friend bool operator<(fraction a, double b);
    friend bool operator<(double b, fraction a);

    friend bool operator<=(fraction a, fraction b);
    friend bool operator<=(fraction a, int b);
    friend bool operator<=(int b, fraction a);
    friend bool operator<=(fraction a, double b);
    friend bool operator<=(double b, fraction a);
    
    friend bool operator>(fraction a, fraction b);
    friend bool operator>(fraction a, int b);
    friend bool operator>(int b, fraction a);
    friend bool operator>(fraction a, double b);
    friend bool operator>(double b, fraction a);

    friend bool operator>=(fraction a, fraction b);
    friend bool operator>=(fraction a, int b);
    friend bool operator>=(int b, fraction a);
    friend bool operator>=(fraction a, double b);
    friend bool operator>=(double b, fraction a);

    friend bool operator==(fraction a, fraction b);
    friend bool operator==(fraction a, int b);
    friend bool operator==(int b, fraction a);
    friend bool operator==(fraction a, double b);
    friend bool operator==(double b, fraction a);

    friend bool operator!=(fraction a, fraction b);
    friend bool operator!=(fraction a, int b);
    friend bool operator!=(int b, fraction a);
    friend bool operator!=(fraction a, double b);
    friend bool operator!=(double b, fraction a);

};


fraction::fraction(int _p, int _q)
{
    if(!_q){cout << "invalida divisao por zero\n"; exit(0); };
   
    if(_q < 0)
    {
        this->p = (-1) * _p;
        this->q = (-1) * _q;
    }
    
    this->p = _p;
    this->q = _q;
}

fraction::fraction(double n, int cycles, double precision)
{
    int sinal  = n > 0 ? 1 : -1; n = n * sinal; //abs(number);

    double novo_numero, parde_inteira;
    double parte_fracionaria =  n - (int)n;
    int counter = 0;
    
    valarray<double> vec_1 = {(double((int) n)), 1}; // (double)floor(n) = (double((int) n))
    valarray<double> vec_2 = {1, 0};
    valarray<double> temporario;

    while(parte_fracionaria > precision && counter < cycles)
    {
        novo_numero = 1 / parte_fracionaria;
        parde_inteira = (int) novo_numero;
        
        temporario = vec_1;
        vec_1 = parde_inteira * vec_1 + vec_2;
        vec_2 = temporario;
        
        parte_fracionaria = novo_numero - parde_inteira;
        counter++;
    }

    this->p = sinal * vec_1[0];
    this->q = vec_1[1];
}

fraction::fraction(const char* n)
{
    if( caso_2(n) )
    {
        str_frac(n, &this->p, &this->q);
    }

    else if( caso_3(n) )
    {
        str_int(n, &this->p, &this->q);
    }

    else if( caso_1(n) )
    {
        double num;
        stringstream ss(n);
        ss >> num;

        fraction aux(num, 10, 5e-4);
        this->p = aux.p;
        this->q = aux.q;
    }
}


fraction operator~(fraction b)
{
    if(b.p <= b.q)
    {
        fraction aux(b.q - b.p, b.q);
        return aux;
    }else{
        fraction aux = 1 - b;
        return aux;
    }

 cout << "ERRO!" << endl; return EXIT_FAILURE;
}

fraction operator!(fraction b)
{
    fraction aux(b.q, b.p); return aux;
}

void fraction::simplifica()
{
    int MDC = mdc(this->p, this->q);

    this->p /= MDC;
    this->q /= MDC;

    if(this->q < 0)
    {
        this->p = (-1) * p;
        this->q = (-1) * q;
    }
    
}

ostream& operator<<(ostream& os, fraction a)
{
    if(a.p == 0){ os << 0;}

    else if(a.q == 1) {os << a.p;}

    else { os << a.p << '/' << a.q;}
 
 return os;
}

istream& operator>>(istream& os, fraction& a)
{
    string num; os >> num;
    fraction aux(num.c_str()); aux.simplifica();

    a.p = aux.p;
    a.q = aux.q;

 return os; // sucesso
}


void fraction::operator=(fraction a)
{
    this->p = a.p;
    this->q = a.q;
}

void fraction::operator=(double a)
{
    fraction aux(a);
    *this = aux;
}

fraction operator+(fraction a, fraction b)
{
    int nume = (a.p * b.q) + (b.p * a.q);
    int deno = a.q * b.q;

    fraction aux(nume, deno); aux.simplifica();

 return aux;
}

fraction operator+(const int a, fraction b)
{
    fraction c(a * b.q, b.q);

 return c + b;
}

fraction operator+(fraction b, const int a)
{
    fraction c(a * b.q, b.q);

 return b + c;
}

void operator+=(fraction& a, fraction& b)
{
    a = (a + b);
}

void operator+=(fraction& b, const int a)
{
    b = (a + b);
}

fraction operator+(const double a, fraction b)
{
    fraction aux(a);
 return aux + b;
}

fraction operator+(fraction b, const double a)
{
    fraction aux(a);
 return b + aux;
}

void operator+=(fraction& b, const double a)
{
    fraction aux(a);
    b = (b + aux);
}

fraction operator-(fraction a, fraction b)
{
    int nume = (a.p * b.q) - (b.p * a.q);
    int deno = a.q * b.q;

    fraction aux(nume, deno); aux.simplifica();

 return aux;
}

fraction operator-(const int a, fraction b)
{
    fraction c(a * b.q, b.q);
 return c - b;
}

fraction operator-(fraction b, const int a)
{
    fraction c(a * b.q, b.q);
 return b - c;
}

void operator-=(fraction& a, fraction& b)
{
    a = (a - b);
}

void operator-=(fraction& b, const int a)
{
    b = (b - a);
}

fraction operator-(const double a, fraction b)
{
    fraction aux(a);
 return aux - b;
}

fraction operator-(fraction b, const double a)
{
    fraction aux(a);
 return b - aux;
}

void operator-=(fraction& b, const double a)
{
    fraction aux(a);
    b = (b - aux);
}

fraction operator*(fraction a, fraction b)
{
    int nume = a.p * b.p;
    int deno = a.q * b.q;

    fraction aux(nume, deno); aux.simplifica();

 return aux;
}

fraction operator*(const int a, fraction b)
{
    fraction c(a * b.q, b.q);
 return c * b;
}

fraction operator*(fraction b, const int a)
{
    fraction c(a * b.q, b.q);
 return c * b;
}

void operator*=(fraction& a, fraction& b)
{
    a = (a * b);
}

void operator*=(fraction& b, const int a)
{
    b = (a * b);
}

fraction operator*(const double a, fraction b)
{
    fraction aux(a);
 return aux * b;
}

fraction operator*(fraction b, const double a)
{
    fraction aux(a);
 return b * aux;
}

void operator*=(fraction& b, const double a)
{
    fraction aux(a);
    b = (b * aux);
}

fraction operator/(fraction a, fraction b)
{
    fraction c(b.q, b.p);

 return a * c;
}

fraction operator/(const int a, fraction b)
{
    fraction c(a * b.q, b.q);
 return c / b;
}

fraction operator/(fraction b, const int a)
{
    fraction c(a * b.q, b.q);
 return b / c;
}

void operator/=(fraction& a, fraction& b)
{
    a = (a / b);
}

void operator/=(fraction& b, const int a)
{
    b = (b / a);
}

fraction operator/(const double a, fraction b)
{
    fraction aux(a);
 return aux / b;
}

fraction operator/(fraction b, const double a)
{
    fraction aux(a);
 return b / aux;
}

void operator/=(fraction& b, const double a)
{
    fraction aux(a);
    b = (b / aux);
}

double fraction::to_double()
{
    return ( (double) this->p ) / this->q ;
}

bool operator<(fraction a, fraction b)
{
    return ( ( a.to_double() < b.to_double() ) ? true : false );
}

bool operator<(fraction a, int b)
{
    return ( (a.to_double() < b) ? true : false );
}

bool operator<(int b, fraction a)
{
    return ( (a.to_double() < b) ? true : false );
}

bool operator<(fraction a, double b)
{
    return ( (a.to_double() < b) ? true : false );
}

bool operator<(double b, fraction a)
{
    return ( (a.to_double() < b) ? true : false );
}

bool operator<=(fraction a, fraction b)
{
    return ( (a.to_double() <= b.to_double()) ? true : false );
}

bool operator<=(fraction a, int b)
{
    return ( (a.to_double() <= b) ? true : false );
}

bool operator<=(int b, fraction a)
{
    return ( (a.to_double() <= b) ? true : false );
}

bool operator<=(fraction a, double b)
{
    return ( (a.to_double() <= b) ? true : false );
}

bool operator<=(double b, fraction a)
{
    return ( (a.to_double() <= b) ? true : false );
}

bool operator>(fraction a, fraction b)
{
    return ( (a.to_double() > b.to_double()) ? true : false );
}

bool operator>(fraction a, int b)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator>(int b, fraction a)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator>(fraction a, double b)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator>(double b, fraction a)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator>=(fraction a, fraction b)
{
    return ( (a.to_double() > b.to_double()) ? true : false );
}

bool operator>=(fraction a, int b)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator>=(int b, fraction a)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator>=(fraction a, double b)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator>=(double b, fraction a)
{
    return ( (a.to_double() > b) ? true : false );
}

bool operator==(fraction a, fraction b)
{
    return ( (a.to_double() == b.to_double()) ? true : false );
}

bool operator==(fraction a, int b)
{
    return ( (a.to_double() == b) ? true : false );
}

bool operator==(int b, fraction a)
{
    return ( (a.to_double() == b) ? true : false );
}

bool operator==(fraction a, double b)
{
    return ( (a.to_double() == b) ? true : false );
}

bool operator==(double b, fraction a)
{
    return ( (a.to_double() == b) ? true : false );
}

bool operator!=(fraction a, fraction b)
{
    return( ! (b == a) );
}

bool operator!=(fraction a, int b)
{
    return( ! (a == b) );
}

bool operator!=(int b, fraction a)
{
    return( ! (b == a) );
}

bool operator!=(fraction a, double b)
{
    return( ! (a == b) );
}

bool operator!=(double b, fraction a)
{
    return( ! (b == a) );
}



#endif