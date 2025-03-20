#pragma once
#include <iostream>

class IntStack
{
private:
    int SIZE;
    int *ti;
    int pos;

public:
    IntStack(int s);
    IntStack(const IntStack &r); // Constructeur de copie, permet de faire IntStack j(i); pour initialiser j avec i.
    IntStack &operator=(const IntStack &r); 
    ~IntStack();

    void push(int e);
    int get_top();
    int pop();
    bool is_empty();
    bool is_full();
    void print();
};
