#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>
#include <cmath>
class Fraction
{
	int nod();
	void simplify();
public:
	int num, den, ipart, fpart, sign;
	Fraction(int x, int y): num(x), den(y)
	{
		if (den == 0)
		{
			std::cout << "Devision by zero!" << std::endl;
			exit(-1);
		}
		ipart = num / den;
		fpart = num % den;
		sign = num / abs(num) * den / abs(den);
		num = sign * abs(num);
		den = abs(den);
	}
	Fraction(double x)
	{
		num = 1;
		den = 1;
		ipart = num / den;
		fpart = num % den;
		sign = num / abs(num) * den / abs(den);
		num = sign * abs(num);
		den = abs(den);

		int z = int(x);
		double r = x - z;
		while (int(r) != r)
		{
			std::cout << "!" << std::endl;
			r *= 10;
		}

		std::cout << x << std::endl;
		std::cout << z << std::endl;
		std::cout << r << std::endl;
	}
	friend const Fraction operator+(const Fraction& x, const Fraction& y);

	friend const Fraction operator-(const Fraction& x, const Fraction& y);

	friend const Fraction operator*(const Fraction& x, const Fraction& y);
	
	void out();

	void partout();
};

#endif // !FRACTION_H

