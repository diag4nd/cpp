#include <iostream>
#include <cmath>
#include "rectangle.cpp"
#include <fstream>
#include <vector>
#include <string>

bool intersects(Rectangle &r1, Rectangle &r2);

std::vector<double> getParams(std::string fileName);

int main()
{
    std::vector<double> params = getParams("params.txt");

    Rectangle r1(params[0], params[1], params[2], params[3]), r2(params[4], params[5], params[6], params[7]);
    if (intersects(r1, r2))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}

bool intersects(Rectangle &r1, Rectangle &r2)
{
    double x1 = r1.getX();
    double y1 = r1.getY();
    double w1 = r1.getW();
    double h1 = r1.getH();
    double x2 = r2.getX();
    double y2 = r2.getY();
    double w2 = r2.getW();
    double h2 = r2.getH();

    if (y1 == y2)
    {
        if (abs(x1 - x2) > (w1 + w2) / 2)
        {
            return false;
        }
        return true;
    }
    else if (x1 == x2)
    {
        if (abs(y1 - y2) > (h1 + h2) / 2)
        {
            return false;
        }
        return true;
    }
    else
    {
        double xd1{ 0 };
        double yd1{ 0 };
        double xd2{ 0 };
        double yd2{ 0 };

        if ((x2 > x1) and (y2 > y1))
        {
            xd1 = x1 + w1 / 2;
            yd1 = y1 + h1 / 2;
            xd2 = x2 - w2 / 2;
            yd2 = y2 - h2 / 2;
        }
        else if ((x2 < x1) and (y2 > y1))
        {
            xd1 = x1 - w1 / 2;
            yd1 = y1 + h1 / 2;
            xd2 = x2 + w2 / 2;
            yd2 = y2 - h2 / 2;
        }
        else if ((x2 < x1) and (y2 < y1))
        {
            xd1 = x1 - w1 / 2;
            yd1 = y1 - h1 / 2;
            xd2 = x2 + w2 / 2;
            yd2 = y2 + h2 / 2;
        }
        else if ((x2 > x1) and (y2 < y1))
        {
            xd1 = x1 + w1 / 2;
            yd1 = y1 - h1 / 2;
            xd2 = x2 - w2 / 2;
            yd2 = y2 + h2 / 2;
        }
        if (r1.isIn(xd2, yd2) or r2.isIn(xd1, yd1))
        {
            return true;
        }
        return false;
    }
}

std::vector<double> getParams(std::string fileName)
{
    std::vector<double> params(8);
    std::string line;
    int j{ 0 }, l{ 0 }, r{ 0 };
    std::ifstream in(fileName);
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            line.append(1, '\n');
            for (int i = 0; i < line.length(); i++)
            {
                if ((line[i] == ' ') or (line[i] == '\n'))
                {
                    r = i;
                    params[j] = std::stod(line.substr(l, r));
                    j++;
                    l = r + 1;
                }
            }
            l = 0;
            r = 0;
        }
    }
    in.close();
    return params;
}
