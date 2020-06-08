#include "Pair.h"

void Pair::init(int f, int s)
{
	if (f < 0)
		first = 0;
	else
		first = f;
	if (s < 0)
		second = 0;
	else
		second = s;
}

void Pair::read()
{
	do
	{
		std::cout << "���� ������? ";
		std::cin >> first;
		if (first >= 0)
			break;
		std::cout << "������ ���� ������������� ������\n";
	} while (true);
	do
	{
		std::cout << "���������� ������? ";
		std::cin >> second;
		if (second >= 0)
			break;
		std::cout << "������ ���� ������������� ������\n";
	} while (true);
}

void Pair::show()
{
	std::cout << first << " ���, " << second << " ��.\n";
}

void Pair::cost()
{
	std::cout << "�������� ��������� = " << (first * second)<<"\n";
}
