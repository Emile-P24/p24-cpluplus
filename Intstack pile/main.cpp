#include "intstack.h"

IntStack::IntStack(int s) : pos(0), SIZE(s)
{
    ti = new int[SIZE];
}

IntStack::IntStack(const IntStack &r) : pos(r.pos), SIZE(r.SIZE)
{ // Constructeur de copie, permet de faire IntStack j(i); pour initialiser j avec i.
    ti = new int[SIZE];
    for (int i = 0; i < pos; i++)
    {
        *(ti + i) = r.ti[i];
    }
}

IntStack &IntStack::operator=(const IntStack &r)
{
    if (this != &r)
    {
        delete[] ti;
        SIZE = r.SIZE;
        pos = r.pos;
        ti = new int[SIZE];
        for (int i = 0; i < pos; i++)
        {
            ti[i] = r.ti[i];
        }
    }
    return *this;
}

IntStack::~IntStack()
{
    delete[] ti;
}

void IntStack::push(int e)
{
    // Ajoute l'entier e dans la pile
    if (is_full() == false)
    {
        *(ti + pos) = e;
        pos++;
    }
}

int IntStack::get_top()
{
    //retourne le dernier entier empilé
    return *(ti + pos);
}

int IntStack::pop()
{
    // Retourne le dernier entier empilé et supprime de la pile
    if (is_empty() == false)
    {
        get_top();
        return *(ti + --pos);
    }
    else
    {
        return EXIT_FAILURE;
    }
}

bool IntStack::is_empty()
{
    //Teste si la pile est vide
    return pos == 0;
}

bool IntStack::is_full()
{
    // teste si la pile est pleine
    // SIZE entiers dans la pile
    return pos == SIZE;
}

void IntStack::print()
{
    // affiche la pile
    std::cout << "[ ";
    for (int i = 0; i < pos; i++)
    {
        std::cout << *(ti + i) << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    IntStack s1(10);
    s1.print(); // affiche []
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.print();                         // affiche [1 2 3 4 5]
    std::cout << s1.pop() << std::endl; // affiche 5
    s1.print();                         // affiche [1 2 3 4]

    return 0;
}
