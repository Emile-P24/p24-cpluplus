#pragma once
#include <iostream>

class rational {
public:
    int num;
    int denom;

    
    rational();
    rational(int n);
    rational(int n, int d);

    
    float divide();
    int printnum();
    int printdenom();
};


rational addition(int a, int b, int c, int d);
rational add(rational r1, rational r2);
