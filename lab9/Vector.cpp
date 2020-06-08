#include "Vector.h"


Vector::Vector(int n)
{
	size = n;
	curr = 0;
	data = new int[n];
}

Vector::Vector(const Vector& v)
{
	size = v.size;
	curr = v.curr;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

Vector::~Vector()
{
	delete[] data;
	data = 0;
}

Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	if (data != 0)
		delete[] data;
	size = v.size;
	curr = v.curr;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	return *this;
}

istream& operator>> (istream& in, Vector& v)
{
	if (v.size == 0)
		throw 1;					// стандартный тип
	for (v.curr = 0; v.curr < v.size; v.curr++)
	{
		cout << "v[" << v.curr << "]? ";
		in >> v.data[v.curr];
	}
	return in;
}

ostream& operator<< (ostream& out, const Vector& v)
{
	if (v.curr == 0)
		throw 2;			// стандартный тип
	for (int i = 0; i < v.curr; i++)
		out << v.data[i] << "\t";
	return out;
}

int& Vector::operator[] (int index)
{
	if (index < curr && index >= 0)
		return data[index];
	throw IndexError();		// с помощью иерархии
}

int Vector::operator() ()
{
	return size;
}

Vector& Vector::operator++ ()
{
	if (curr == size)
		throw OverSizeError(); // с помощью иерархии
	for (int j = curr; j > 0; j--)	// двигаем элементы вправо
		data[j] = data[j - 1];
	data[0] = rand() % 100 - 50;
	curr++;
	return *this;
}

Vector& Vector::operator++ (int)
{
	if (curr == size)
		throw OverSizeError(); // с помощью иерархии
	data[curr] = rand() % 100 - 50;
	curr++;
	return *this;
}
