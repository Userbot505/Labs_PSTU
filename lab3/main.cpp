#include "Time.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Time t1(-5, 130);
	cout << "����� ������: " << t1 << endl;
	Time t2;
	cout << "����� �����\n";
	cin >> t2;
	cout << t2 << endl;
	Time t3 = t2;
	cout << "����� ����������: " << t3 << endl;
	cout << "����� ���������� ������: " << (t3 + 500) << endl;
	cout << "����� ��������� ������: " << (t3 - 110) << endl;
	return 0;
}