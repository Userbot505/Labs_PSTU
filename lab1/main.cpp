#include "Pair.h"
#include <ctime>
using namespace std;

Pair& make_pair(int f, int s)
{
	Pair p;
	if (f < 0)
	{
		cout << "Цена должна быть положительным числом\n";
		return p;
	}
	p.first = f;
	if (s < 0)
	{
		cout << "Количество должно быть положительным числом\n";
		return p;
	}	
	p.second = s;
	return p;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(0));
	Pair p1; 
	p1.init(-7, 2); cout << "Объект с помощью init - "; p1.show();
	Pair p2; 
	p2.read(); cout << "Объект с помощью read - "; p2.show();
	cout << "p1 cost - "; p1.cost();

	const int n = 3;
	Pair p[n];
	for (int i = 0; i < n; i++)
		p[i] = make_pair(rand() % 100 - 50, rand() % 20 - 5);
	cout << "Объекты в массиве:\n";
	for (int i = 0; i < n; i++)
		p[i].show();
	return 0;
}