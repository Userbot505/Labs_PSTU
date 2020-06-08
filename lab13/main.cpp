#include <ctime>
#include "first.h"
#include "second.h"
#include "third.h"

void first()
{
	cout << "\nДвусторонняя очередь с типом Time\n";
	deque<Time> deq;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		deq.push_back(t);
	}
	show(deq);
	cout << "\nДобавление\n";  add(deq);
	show(deq);
	cout << "\nУдаление\n";  del(deq);
	show(deq);
	cout << "\nИзменение\n";  update(deq);
	show(deq);
}

void second()
{
	cout << "Очередить с приоритетами с типом Time\n";
	priority_queue<Time> que;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		que.push(t);
	}
	show(que);
	cout << "\nДобавление\n";  add(que);
	show(que);
	cout << "\nУдаление\n";  del(que);
	show(que);
	cout << "\nИзменение\n";  update(que);
	show(que);
}

void third()
{
	cout << "Словарь с типом Time\n";
	map<int, Time> dic;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		dic[i + 1] = t;
	}
	show(dic);
	cout << "\nДобавление\n";  add(dic);
	show(dic);
	cout << "\nУдаление\n";  del(dic);
	show(dic);
	cout << "\nИзменение\n";  update(dic);
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