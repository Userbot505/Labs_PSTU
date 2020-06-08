#include "Rightangled.h"

void podst1(Pair& p)
{
	p.setFirst(-100);
	cout <<"Принцип подстановки 1 - "<< p << endl;
}

Pair podst2()
{
	Rightangled r(30, 40);
	return r;
}

int main()
{
	setlocale(LC_ALL, "rus");
	// Pair
	Pair p1(-10, 20);
	cout << "p1 - " << p1 << endl;
	Pair p2;
	cin >> p2;
	cout << "p2 - " << p2 << endl;
	cout << "p1 * p2 - " << (p1 * p2) << endl;
	// Rightangled
	Rightangled r1;
	cin >> r1;
	cout << "r1 - " << r1 << endl;
	Rightangled r2(3, 4);
	cout << "r2 - " << r2 << endl;
	cout << "gip(r1) - " << r1.gipotinusa() << endl;
	cout << "gip(r2) - " << r2.gipotinusa() << endl;
	// Принцип подстановки
	podst1(r2);
	Pair p = podst2();
	cout <<"Принцип подстановки 2 - "<< p << endl;
	return 0;
}