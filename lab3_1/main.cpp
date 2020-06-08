#include "Binary.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Point  *temp, *root = 0;
	int x;
	while (true)
	{
		cout << "\n1. Сформировать\n2. Вывести\n3. Количество листьев\n4. В дерево поиска\n5. Выход\n-->";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Количество? "; cin >> x;
			cin.ignore(1);
			root = addPoint(root, x);
			break;
		case 2:
			showPoint(root, 5);
			break;
		case 3:
			x = 0;
			count(root, x);
			cout << "Количество = " << x << endl;
			break;
		case 4:
			temp = new Point(root->data);
			formFindPoint(root, temp);
			root = temp;
			break;
		case 5:
			return 0;
		}
	}
}