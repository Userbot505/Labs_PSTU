#include "Vector.h"
#include "StVector.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);			// ввод русской кирилицы
	SetConsoleOutputCP(1251);	// вывод русской кирилицы
	Group g;	// доп перем
	Vector v;	// группы
	StVector stV;	// студенты
	int x;	// доп перем
	string str; // доп перем
	while (true)
	{
		if (g == Group())	// если работаем со всеми группами
		{
			cout << "\n1. Вывести группы\n2. Выбрать группу\n3. Сформировать список с сортировкой студентов\n4. Сформировать список с сортировкой по убыванию номеров групп\n5. Выход\n-->";
			cin >> x;
			switch (x)
			{
			case 1:
				v.show();
				break;
			case 2:
				cout << "Название? "; cin >> str;
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
		else // если работаем с конкретной группой
		{
			cout << "\nТекущая группа - " << g << endl;
			cout << "1. Вывести список\n2. Добавить\n3. Удалить по номеру\n4. Изменить по номеру\n5. Назад\n-->";
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