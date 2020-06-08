#include "Rightangled.h"

Rightangled::Rightangled(int a, int b) : Pair()
{
	if (a < 1)
		first = 1;
	else
		first = a;
	if (b < 1)
		second = 1;
	else
		second = b;
}

void Rightangled::setFirst(int a)
{
	if (a < 1)
		first = 1;
	else
		first = a;
}

void Rightangled::setSecond(int b)
{
	if (b < 1)
		second = 1;
	else
		second = b;
}

Rightangled& Rightangled::operator=(const Rightangled& r)
{
	if (this == &r)
		return *this;
	first = r.first;
	second = r.second;
	return *this;
}

double Rightangled::gipotinusa()
{
	return pow(pow(first, 2) + pow(second, 2), 0.5);
}

istream& operator>>(istream& in, Rightangled& r)
{
	int x;
	cout << "a? "; in >> x; r.setFirst(x);
	cout << "b? "; in >> x; r.setSecond(x);
	return in;
}

ostream& operator<<(ostream& out, const Rightangled& r)
{
	out << "(" << r.first << ", " << r.second << ")";
	return out;
}
