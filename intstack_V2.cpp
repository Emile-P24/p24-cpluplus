#include <iostream>
#include <stdexcept>

class IntStack
{
private:
    int SIZE;
    int *ti; // Comme un tableau normal mais stocké dans la "mémoire dynamique", le "Heap".Il faut supprimer avec delete[]ti; pour libérer l'espace mémoire.
    int pos;

public:
    IntStack(int s) : pos(0), SIZE(s)
    {
        ti = new int[SIZE];
    }

    IntStack(const IntStack &r) : pos(r.pos), SIZE(r.SIZE)
    { // Constructeur de copie, permet de faire IntStack j(i); pour initialiser j avec i.
        ti = new int[SIZE];
        for (int i = 0; i < pos; i++)
        {
            *(ti + i) = r.ti[i];
        }
    }

    IntStack &operator=(const IntStack &r)
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

    ~IntStack()
    {
        delete[] ti;
    }

    void push(int e)
    {
        // Ajoute l'entier e dans la pile
        if (is_full() == false)
        {
            *(ti + pos) = e;
            pos++;
        }
    }

    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
        return *(ti + pos);
    }

    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
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

    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        return pos == 0;
    }
    bool is_full()
    {
        // teste si la pile est pleine
        //SIZE entiers dans la pile
        return pos == SIZE;
    }
    void print()
    {
        // affiche la pile
        std::cout << "[ ";
        for (int i = 0; i < pos; i++)
        {
            std::cout << *(ti + i) << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main()
{
    IntStack s1(10);
    s1.print(); // affiche []
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.print();                         // affiche [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affiche 3
    s1.print();                         // affiche [1 2 ]

    return 0;
}
