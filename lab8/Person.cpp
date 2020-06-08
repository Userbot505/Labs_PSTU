#include "Person.h"

void Person::show()
{
	cout << name << ", " << age << " (л)" << endl;
}

void Person::input()
{
	cout << "Имя? "; cin >> name; 
	cout << "Возраст? "; cin >> age;
}
