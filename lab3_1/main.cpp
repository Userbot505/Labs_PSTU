#include "Binary.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Point  *temp, *root = 0;
	int x;
	while (true)
	{
		cout << "\n1. ������������\n2. �������\n3. ���������� �������\n4. � ������ ������\n5. �����\n-->";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "����������? "; cin >> x;
			cin.ignore(1);
			root = addPoint(root, x);
			break;
		case 2:
			showPoint(root, 5);
			break;
		case 3:
			x = 0;
			count(root, x);
			cout << "���������� = " << x << endl;
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