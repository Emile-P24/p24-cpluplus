#include "Shape.h"

// Définition des méthodes

std::pair<int, int> Shape::position() const
{
    return {x, y};
}

float Square::area() const
{
    return side * side;
}

void Square::who_am_I() const
{
    std::cout << "Carré à la position (" << position().first << "," << position().second
              << ") d'aire " << area() << std::endl;
}

float Circle::area() const
{
    return 3.14 * radius * radius;
}

void Circle::who_am_I() const
{
    std::cout << "Cercle à la position (" << position().first << "," << position().second
              << ") d'aire " << area() << std::endl;
}

float Rectangle::area() const
{
    return height * width;
}

void Rectangle::who_am_I() const
{
    std::cout << "Rectangle à la position (" << position().first << "," << position().second
              << ") d'aire " << area() << std::endl;
}

Shape *find_at_position(int xf, int yf, const std::vector<Shape *> &v)
{
    for (Shape *s : v)
    {
        if (s->position() == std::make_pair(xf, yf))
        {
            return s;
        }
    }
    return nullptr;
}

// Fonction principale
int main()
{
    Circle c(0, 0, 1);
    Rectangle r(1, 1, 2, 3);
    Square s(2, 2, 4);

    std::vector<Shape *> v;
    v.push_back(&c);
    v.push_back(&r);
    v.push_back(&s);

    std::cout << "L'aire du cercle vaut " << c.area() << std::endl;
    std::cout << "L'aire du rectangle vaut " << r.area() << std::endl;
    std::cout << "L'aire du carré vaut " << s.area() << std::endl;

    Shape *found = find_at_position(0, 0, v);
    if (found)
    {
        std::cout << "Objet trouvé: ";
        found->who_am_I();
    }
    else
    {
        std::cout << "Aucun objet trouvé." << std::endl;
    }

    return 0;
}
