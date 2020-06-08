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
	cout << "����������� ��� ����������: "; r1.show();
	Route r2("����� 5", "����� 6", 51.1f); 
	cout << "����������� � �����������: "; r2.show();
	Route r3(r2);
	cout << "����������� ����������� �����������: "; r3.show();
	cout << "����� �������� � ��������: ";
	r3.setStart("5 �����"); r3.setEnd("654 �����"); r3.setTime(-4.2f);
	cout << r3.getStart() << " - " << r3.getEnd() << ", " << r3.getTime() << endl;
	cout << "����������� �����������\n";
	Route r4 = getRoute();
	cout << "#1 - "; r4.show();
	cout << "#2 - "; printRoute(r4);
	return 0;
}