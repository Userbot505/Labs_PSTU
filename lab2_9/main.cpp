#include "HashTable.h"
#include <string>
#include <Windows.h>

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HashTable table(100);
	int x; string s1, s2, s3;
	while (true)
	{
		cout << "\n1.Случайно добавить\n2. Поиск по ФИО\n3. Показать\n4. Количество коллизий\n5.Выход\n-->";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Количество? "; cin >> x;
			table.randForm(x);
			break;
		case 2:
			cout << "Ключ? "; cin >> s1 >> s2 >> s3;
			table.find(s1 +" "+ s2 +" "+ s3);
			break;
		case 3:
			table.show();
			break;
		case 4:
			cout << "Количество = " << table.getCollision() << endl;
			break;
		case 5:
			return 0;
		}
	}
}