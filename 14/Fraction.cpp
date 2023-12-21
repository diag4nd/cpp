#include "Fraction.h"
Fraction const operator+(const Fraction& x, const Fraction& y)
{
	return Fraction(x.num * y.den + y.num * x.den, x.den * y.den);
}
Fraction const operator-(const Fraction& x, const Fraction& y)
{
	return Fraction(x.num * y.den - y.num * x.den, x.den * y.den);
}
Fraction const operator*(const Fraction& x, const Fraction& y)
{
	return Fraction(x.num * y.num, x.den * y.den);
}
void Fraction::out()
{
	simplify();
	if (fpart == 0)
	{
		std::cout << ipart << std::endl;
	}
	else
	{
		std::cout << num << "/" << den << std::endl;
	}
}
void Fraction::partout()
{
	simplify();
	if (fpart == 0)
	{
		std::cout << ipart << std::endl;
	}
	else
	{
		std::cout << ipart << " and " << num % den << "/" << den << std::endl;
	}
}
void Fraction::simplify()
{
	int k(nod());
	while (k != 1)
	{
		num /= k;
		den /= k;
		k = nod();
	}
}
int Fraction::nod()
{
	int a = (abs(num) > abs(den)) ? abs(num) : abs(den);
	int b(abs(num) + abs(den) - a);
	int q(a % b);
	while (q != 0)
	{
		a = b;
		b = q;
		q = a % b;
	}
	return b;
}