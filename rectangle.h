#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double const xc;
    double const yc;
    double const width;
    double const height;
public:
    Rectangle(double x, double y, double a, double b)
        : xc{ x }, yc{ y }, width{ a }, height{ b }
    {}

    double getX() { return xc; };
    double getY() { return yc; };
    double getW() { return width; };
    double getH() { return height; };
    bool isIn(double x, double y);
};

#endif