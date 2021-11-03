//// fraction.h

#include <iostream>
#include <cstdlib>
#include <string.h>

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

    fraction(int _p, int _q);
    fraction(double n);
    fraction(){}

    void simplifica();

    void operator=(fraction a);
    //void operator=(double a);
    //void operator=(string a);
    //void operator=(const char* a);

    friend ostream& operator<<(ostream& os, fraction a);
    friend fraction operator+(fraction a, fraction b);
    friend fraction operator+(const int a, fraction b);
    friend fraction operator+(fraction b, const int a);
    friend void operator+=(fraction& a, fraction& b);
    friend void operator+=(fraction& b, const int a);

    friend fraction operator-(fraction a, fraction b);
    friend fraction operator-(const int a, fraction b);
    friend fraction operator-(fraction b, const int a);
    friend void operator-=(fraction& a, fraction& b);
    friend void operator-=(fraction& b, const int a);

    friend fraction operator*(fraction a, fraction b);
    friend fraction operator*(const int a, fraction b);
    friend fraction operator*(fraction b, const int a);
    friend void operator*=(fraction& a, fraction& b);
    friend void operator*=(fraction& b, const int a);

    friend fraction operator/(fraction a, fraction b);
    friend fraction operator/(const int a, fraction b);
    friend fraction operator/(fraction b, const int a);
    friend void operator/=(fraction& a, fraction& b);
    friend void operator/=(fraction& b, const int a);

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

fraction::fraction(double n)
{
    // ainda em manutenção
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
    os << a.p << '/' << a.q;
 
 return os;
}

void fraction::operator=(fraction a)
{
    this->p = a.p;
    this->q = a.q;
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

 return c + b;
}

void operator+=(fraction& a, fraction& b)
{
    a = (a + b);
}

void operator+=(fraction& b, const int a)
{
    b = (a + b);
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
 return c - b;
}

void operator-=(fraction& a, fraction& b)
{
    a = (a - b);
}

void operator-=(fraction& b, const int a)
{
    b = (a - b);
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


#endif