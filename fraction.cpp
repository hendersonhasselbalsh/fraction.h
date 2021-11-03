/////

#include <iostream>
#include <iomanip>
#include "fraction.h"

using namespace std;


int main(int argc, char** argv)
{

    fraction a(1, 2);
    fraction b(3, 2);
    fraction c(0, 1);

    int x = 2;
    double v = 1.0 / 2;


    cout << a / x << endl;
    cout << (a / x).to_double() << endl;
    cout << boolalpha << bool(a == b) << endl;
    cout << boolalpha << bool(a == 1) << endl;
    cout << boolalpha << bool(a == 0) << endl;
    cout << boolalpha << !bool(a == v) << endl;

    
    
 
}