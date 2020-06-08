#include <ctime>
#include "first.h"
#include "second.h"
#include "third.h"

void first()
{
	cout << "\n������������ ������� � ����� Time\n";
	deque<Time> deq;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		deq.push_back(t);
	}
	show(deq);
	cout << "\n����������\n";  add(deq);
	show(deq);
	cout << "\n��������\n";  del(deq);
	show(deq);
	cout << "\n���������\n";  update(deq);
	show(deq);
}

void second()
{
	cout << "��������� � ������������ � ����� Time\n";
	priority_queue<Time> que;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		que.push(t);
	}
	show(que);
	cout << "\n����������\n";  add(que);
	show(que);
	cout << "\n��������\n";  del(que);
	show(que);
	cout << "\n���������\n";  update(que);
	show(que);
}

void third()
{
	cout << "������� � ����� Time\n";
	map<int, Time> dic;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		dic[i + 1] = t;
	}
	show(dic);
	cout << "\n����������\n";  add(dic);
	show(dic);
	cout << "\n��������\n";  del(dic);
	show(dic);
	cout << "\n���������\n";  update(dic);
	show(dic);
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(0));
	//first();
	//second();
	third();
	return 0;
}