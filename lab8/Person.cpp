#include "Person.h"

void Person::show()
{
	cout << name << ", " << age << " (�)" << endl;
}

void Person::input()
{
	cout << "���? "; cin >> name; 
	cout << "�������? "; cin >> age;
}
