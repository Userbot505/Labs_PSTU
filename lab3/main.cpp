#include "Time.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Time t1(-5, 130);
	cout << "Поток вывода: " << t1 << endl;
	Time t2;
	cout << "Поток ввода\n";
	cin >> t2;
	cout << t2 << endl;
	Time t3 = t2;
	cout << "После присвоения: " << t3 << endl;
	cout << "После добавления секунд: " << (t3 + 500) << endl;
	cout << "После вычитания секунд: " << (t3 - 110) << endl;
	return 0;
}