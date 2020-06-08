#include "Abiturient.h"

void Abiturient::show()
{
	cout << name << ", " << age << " (л), баллов = " << sum << ", специальность: "<<spec<< endl;
}

void Abiturient::input()
{
	cout << "Имя абитуриента? "; cin >> name;
	cout << "Возраст? "; cin >> age;
	cout << "Сумма баллов? "; cin >> sum;
	cout << "Специальность? "; cin >> spec;
}
