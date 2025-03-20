#pragma once
#include <iostream>
#include <vector>

class Shape
{
protected:
    int x, y;

public:
    Shape(int xsh, int ysh) : x(xsh), y(ysh) {}
    virtual ~Shape() {}

    void move(int nx, int ny) { x = nx; y = ny; }

    inline std::pair<int, int> position() const;

    virtual void who_am_I() const = 0;
    virtual float area() const = 0;
};

class Square : public Shape
{
    int side;

public:
    Square(int xs, int ys, int s) : Shape(xs, ys), side(s) {}

    inline float area() const override;
    inline void who_am_I() const override;
};

class Circle : public Shape
{
    int radius;

public:
    Circle(int xc, int yc, int r) : Shape(xc, yc), radius(r) {}

    inline float area() const override;
    inline void who_am_I() const override;
};

class Rectangle : public Shape
{
    int height, width;

public:
    Rectangle(int xr, int yr, int h, int w) : Shape(xr, yr), height(h), width(w) {}

    inline float area() const override;
    inline void who_am_I() const override;
};

Shape *find_at_position(int xf, int yf, const std::vector<Shape *> &v);
