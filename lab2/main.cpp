#include "Route.h"

void printRoute(Route& r)
{
	r.show();
}

Route getRoute()
{
	Route r("third", "fourth", 1.3f);
	return r;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Route r1;
	cout << "Конструктор без параметров: "; r1.show();
	Route r2("Точка 5", "Точка 6", 51.1f); 
	cout << "Конструктор с параметрами: "; r2.show();
	Route r3(r2);
	cout << "Конструктор копирования предыдущего: "; r3.show();
	cout << "После сеттеров и геттеров: ";
	r3.setStart("5 точка"); r3.setEnd("654 точка"); r3.setTime(-4.2f);
	cout << r3.getStart() << " - " << r3.getEnd() << ", " << r3.getTime() << endl;
	cout << "Кострукторы копирования\n";
	Route r4 = getRoute();
	cout << "#1 - "; r4.show();
	cout << "#2 - "; printRoute(r4);
	return 0;
}