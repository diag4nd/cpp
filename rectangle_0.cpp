#include <iostream>
#include <cmath>
#include "rectangle.h"

bool Rectangle::isIn(double x2, double y2)
{
    double x1 = this->getX();
    double y1 = this->getY();
    double w1 = this->getW();
    double h1 = this->getH();
    if ((abs(x1 - x2) <= w1 / 2) and (abs(y1 - y2) <= h1 / 2))
    {
        return true;
    }
    return false;
}