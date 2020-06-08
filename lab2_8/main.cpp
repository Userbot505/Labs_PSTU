#include "Vector.h"
#include "StVector.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);			// ���� ������� ��������
	SetConsoleOutputCP(1251);	// ����� ������� ��������
	Group g;	// ��� �����
	Vector v;	// ������
	StVector stV;	// ��������
	int x;	// ��� �����
	string str; // ��� �����
	while (true)
	{
		if (g == Group())	// ���� �������� �� ����� ��������
		{
			cout << "\n1. ������� ������\n2. ������� ������\n3. ������������ ������ � ����������� ���������\n4. ������������ ������ � ����������� �� �������� ������� �����\n5. �����\n-->";
			cin >> x;
			switch (x)
			{
			case 1:
				v.show();
				break;
			case 2:
				cout << "��������? "; cin >> str;
				g = v.getGroupByName(str);
				stV.setGroup(g);
				break;
			case 3:
				v.query1();
				break;
			case 4:
				v.query2();
				break;
			case 5:
				return 0;
			}
		}
		else // ���� �������� � ���������� �������
		{
			cout << "\n������� ������ - " << g << endl;
			cout << "1. ������� ������\n2. ��������\n3. ������� �� ������\n4. �������� �� ������\n5. �����\n-->";
			cin >> x;
			switch (x)
			{
			case 1:
				stV.show();
				break;
			case 2:
				stV.add();
				break;
			case 3:
				stV.del();
				break;
			case 4:
				stV.update();
				break;
			case 5:
				g = Group();
				stV.setGroup(g);
				break;
			}
		}
		
	}
}