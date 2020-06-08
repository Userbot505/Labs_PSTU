#include <ctime>
#include "first.h"
#include "second.h"
#include "third.h"


void first()
{
	cout<<"multiset � ����� double\n";
	multiset<double> set;
	double x;
	for (int i = 0; i < 6; i++)
	{
		x = (double)(rand() % 100 - 50) * 0.1;
		x = round(x * 100) / 100;
		set.insert(x);
	}
	show(set);
	add(set);
	cout << "\n����������\n"; show(set);
}

void second()
{
	cout << "\n\nmultiset � ����� Time\n";
	multiset<Time> set;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		set.insert(t);
	}
	show(set);
	del(set);
	cout << "\n��������\n"; show(set);
}

void third()
{
	cout << "\n\nVector<T> � multiset\n";
	Vector<Time> v;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		v.add(t);
	}
	cout << v << endl;
	v.update();
	cout << "\n���������\n" << v << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(0));
	first();
	second();
	third();
	return 0;
}