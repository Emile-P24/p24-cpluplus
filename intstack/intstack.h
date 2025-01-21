# pragma once
#include <iostream>

const int SIZE{12};

class IntStack{

public:
    
    int stack[SIZE];
    int pos{0};

    void push(int e)
    {
        // cette fonction ajoute l'entier e dans la pile
        if (is_full() == false)
        {
            stack[pos] = e;
            pos++;
        }
    }

    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
        return stack[pos];
    }

    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
        if (is_empty() == false)
        {
            get_top();
            return stack[--pos];
        }
        else
        {
            return EXIT_FAILURE;
        }
    }

    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        return pos == 0;
    }
    bool is_full()
    {
        // cette fonction teste si la pile est pleine
        // il y a SIZE entiers dans la pile
        return pos == (SIZE-1);
    }
    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        std::cout << "[ ";
        for (int i = 0; i < pos; i++)
        {
            std::cout << stack[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};