#include "Pair.h"

Pair& Pair::operator=(const Pair& p)
{
	if (this == &p)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator*(const Pair& p)
{
	Pair temp(first * p.first, second * p.second);
	return temp;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "Первое число? "; in >> p.first;
	cout << "Второе число? "; in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << "[" << p.first << ", " << p.second << "]";
	return out;
}
