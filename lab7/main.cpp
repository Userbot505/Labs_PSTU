#include "Vector.h"
#include "Time.h"

int main()
{
	setlocale(LC_ALL, "rus");
	// int
	Vector<int> v1(3, 33);
	cout << "v1 - " << v1 << endl;
	Vector<int> v2(3, 0);
	cout << "¬ведите вектор из целых чисел\n";
	cin >> v2;
	cout << "v2 - " << v2 << endl;
	cout << "v2[5] - " << v2[5] << endl;
	cout << "v1 + v2 - " << (v1 + v2) << endl;
	cout << "v1 + 3 - " << (v1 + 3) << endl;
	cout << endl;
	// double
	Vector<double> v3(4, 5);
	Vector<double> v4(4, -5.5);
	cout << "v3 - " << v3 << endl;
	cout << "v4 - " << v4 << endl;
	cout << "v4[3] - " << v4[3] << endl;
	cout << "v3 + v4 - " << (v3 + v4) << endl;
	cout << " v4 + 2 - " << (v4 + 2) << endl;
	cout << endl;
	// Time
	Vector<Time> v5(3, Time(100, 100));
	cout << "v5 - " << v5 << endl;
	Vector<Time> v6(3, Time());
	cout << "¬ведите вектор из временных интервалов\n";
	cin >> v6;
	cout << "v6 - " << v6 << endl;
	cout << "v6[-1] - " << v6[-1] << endl;
	cout << "v5 + v6 - " << (v5 + v6) << endl;
	cout << "v5 + 1 - " << (v5 + 1) << endl;
	return 0;
}