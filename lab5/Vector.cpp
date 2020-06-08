#include "Vector.h"

Vector::Vector(int n)
{
	size = n;
	curr = 0;
	arr = new Object * [size];
}

Vector::~Vector()
{
	if (curr == 0)
		return;
	for (int i = 0; i < curr; i++)
		delete arr[i];
	delete[] arr;
}

void Vector::add(Object* obj)
{
	if (curr == size)
	{
		cout << "Вектор полон\n";
		return;
	}
	arr[curr] = obj;
	curr++;
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.curr == 0)
		out << "Пустой" << endl;
	for (int i = 0; i < v.curr; i++)
		v.arr[i]->show();
	return out;
}
