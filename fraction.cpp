///////

#include <iostream>
#include <iomanip>
#include "fraction.h"

using namespace std;


int main(int argc, const char* argv[])
{
    
    fraction a(1.0 / 2);
    fraction b(3, 2);
    fraction c(0, 1);

    int x = 2;
    double v = 1.0 / 2;


    cout << a << endl;
    cout << "a * b = " << a / (1.0/3) << endl << endl;
    cout << (a / x).to_double() << endl;
    

    
    fraction w;

    cout << "digite uma fracao:  ";
    cin >> w;

    cout << "\n\n\n" << w << endl;

    cout << w + 1 << endl;

    cout << w - 2 << endl;
    

    fraction a1("1/2"), b2("70/3");

    cout << "(" << b << ") => " << ~b << endl;
    cout << "(" << b << ") + " << ~b << " = " << b + ~b << endl;

    cout << "!a = " << !a << endl;
    cout << boolalpha << bool(1 == EXIT_FAILURE) << endl;

    v++;
}