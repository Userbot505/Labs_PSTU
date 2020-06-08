#include "Vector.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Vector v1(5);
	cout << "Введите вектор\n";
	cin >> v1;
	cout <<"v1 - " << v1 << endl;
	Vector v2(5, 1);
	cout << "v2 - " << v2 << endl;
	cout << "v1[-5] - " << v1[-5] << endl;
	cout << "v1[2] - " << v1[2] << endl;
	cout << "v1 + v2 - " << (v1 + v2) << endl;
	cout << "v2 + 100 - " << (v2 + 100) << endl;
	
	cout << "С помощью итератора\n";
	for (Iterator it = v1.first(); it != v1.last(); it++)
		cout << (*it) << "\t";
	cout << endl;
	Iterator it = v1.last();
	it--; it--; it--;
	cout << "After it-3 - " << (*it) << endl;
	it++;
	cout << "After it++ - " << (*it) << endl;
	return 0;
}