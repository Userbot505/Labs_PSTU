#include "Stream.h"
#include <ctime>

string getPath()
{
	string temp;
	cout << "Введите путь к файлу: ";
	cin >> temp;
	return temp;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(0));
	string path;
	int x;
	while (true)
	{
		cout << "\n1. Сформировать  2. Читать  3. Удалить с заданным значением\n4. Вычесть 1:30 из заданных  5. Добавить К после заданного  6. Выйти\n-->";
		cin >> x;
		switch (x)
		{
		case 1:
			path = getPath();
			makeFile(path);
			break;
		case 2:
			path = getPath();
			readFile(path);
			break;
		case 3:
			path = getPath();
			del(path);
			break;
		case 4:
			path = getPath();
			update(path);
			break;
		case 5:
			path = getPath();
			add(path);
			break;
		case 6:
			return 0;
		}
	}
}