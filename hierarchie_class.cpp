#include <iostream>
#include <vector>

class Shape
{
    int x;
    int y;

public:
    Shape(int xsh, int ysh ): x(xsh), y(ysh){
    }

    void move(int nx, int ny)
    {
        x = nx;
        y = ny;
    }

    std::pair<int,int> position(){
        return {x,y};
    }

    virtual void who_am_I()
    {
        std::cout << "Shape at position (" << x << ", " << y << ")" << std::endl;
    }

    virtual ~Shape(){}
};


class Square : public Shape
{
    int side;

public:
    Square(int xs, int ys, int s): side(s),Shape(xs,ys){
    }
    
    float area()
    {
        return side*side;
    }

    void who_am_I()
    {
        std::cout << "Square at position (" << position().first << "," << position().second 
                  << ") with area " << area() << std::endl;
    }
};


class Circle : public Shape
{
    int radius;

public:
    Circle(int xc, int yc, int r): radius(r),Shape(xc,yc){

    }
    
    
    float area()
    {
        return 3.14*radius*radius;
    }

    void who_am_I()
    {
        std::cout << "Circle at position (" << position().first << "," << position().second 
                  << ") with area " << area() << std::endl;
    }
};

class Rectangle : public Shape
{
    int height;
    int width;
public:
    Rectangle(int xr, int yr, int h, int w): height(h), width(w), Shape(xr,yr){

    }
    
    float area()
    {
        return height*width;
    }

    void who_am_I()
    {
        std::cout << "Rectangle at position (" << position().first << "," << position().second 
                  << ") with area " << area() << std::endl;
    }
};

Shape* find_at_position(int xf, int yf, std::vector<Shape*> v ){
    for (Shape* s : v){
        if (s->position() == std::make_pair(xf, yf)){
        return s;
        }
    }
    return nullptr;
}

int main(){
    Circle c{0,0,1};
    Rectangle r(1,1,2,3);
    std::vector<Shape*> v;
    v.push_back(&c);
    v.push_back(&r);
    Shape* s = find_at_position(0,0,v);
    std::cout<<"L'aire du carré vaut "<<c.area()<<std::endl;
    std::cout<<"L'aire du rectangle vaut "<<r.area()<<std::endl;
    std::cout<<"Object found: ";
    s->who_am_I();

    return 0;
}