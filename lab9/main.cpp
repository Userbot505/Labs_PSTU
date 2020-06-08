#include "Vector.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Vector v(2);
	try
	{
		cin >> v;
		cout << v << endl;
	}
	catch (int)
	{
		cout << "Ошибка. Пустой\n";
	}
	try
	{
		v++; // генерация исключения
		cout << v << endl;
		++v;
		cout << v << endl;
		v++;	
	}
	catch (Error& er)
	{
		er.what();
	}
	try
	{
		cout << "v[3] - " << v[3] << endl;
		cout << "v[1] - " << v[1] << endl; // генерация исключения
	}
	catch (Error & er)
	{
		er.what();
	}
}