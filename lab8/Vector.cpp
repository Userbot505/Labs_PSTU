#include "Vector.h"
#include "Abiturient.h"

Vector::Vector()
{
	beg = 0;
	size = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	size = n;
	curr = 0;
}

Vector::~Vector()
{
	if (curr != 0)
		delete[] beg;
	beg = 0;
}

void Vector::add()
{
	if (curr == size)
	{
		cout << "Нет мест для добавления\n";
		return;
	}
	int sw;
	cout << "Что добавляем? 1. Персону\t2. Абитуриента\n"; cin >> sw;
	Object* obj;
	if (sw == 1)
		obj = new Person();
	else if (sw == 2)
		obj = new Abiturient();
	else
		return;
	obj->input();
	beg[curr++] = obj;
}

void Vector::del()
{
	if (curr == 0)
	{
		cout << "Группа пуста\n";
		return;
	}
	delete beg[--curr];
}

void Vector::show()
{
	if (curr == 0)
		cout << "Пусто\n";
	Object** p = beg;
	for (int i = 0; i < curr; i++, p++)
	{
		(*p)->show();
		cout << endl;
	}
}


void Vector::avg()
{
	Object** p = beg;
	double e = 0;
	for (int i = 0; i < curr; i++, p++)
		e += (*p)->getAge();
	cout << "Средний возраст = " << e / curr << endl;
}