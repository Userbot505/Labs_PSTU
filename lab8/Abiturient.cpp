#include "Abiturient.h"

void Abiturient::show()
{
	cout << name << ", " << age << " (�), ������ = " << sum << ", �������������: "<<spec<< endl;
}

void Abiturient::input()
{
	cout << "��� �����������? "; cin >> name;
	cout << "�������? "; cin >> age;
	cout << "����� ������? "; cin >> sum;
	cout << "�������������? "; cin >> spec;
}
