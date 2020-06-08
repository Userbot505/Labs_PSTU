#include "Vector.h"
#include "Rightangled.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Vector v(2);
	v.add(new Rightangled(1, 2));
	v.add(new Pair(10, 15));
	v.add(new Rightangled(7, 8));
	cout << "Массив объектов\n" << v << endl;
	return 0;
}