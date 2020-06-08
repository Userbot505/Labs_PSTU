#include <ctime>
#include "first.h"
#include "second.h"
#include "third.h"
#include "fourth.h"
#include "fifth.h"

void first()
{
	cout << "Двунаправленная очередь с типом double\n";
	deque<double> deq;
	double x;
	for (int i = 0; i < 6; i++)
	{
		x = (double)(rand() % 100 - 50) * 0.1;
		x = round(x * 100) / 100;
		deq.push_back(x);
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
	cout << "Двунаправленная очередь с типом Time\n";
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


void third()
{
	cout << "Двунаправленная очередь с типом Time\n";
	Vector<Time> v;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		v.add(t);
	}
	cout << v << endl;
	cout << "\nДобавление\n";  v.add();
	cout << v << endl;
	cout << "\nУдаление\n";  v.del();
	cout << v << endl;
	cout << "\nИзменение\n";  v.update();
	cout << v << endl;
}

void fourth()
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

void fifth()
{
	cout << "Двунаправленная очередь с типом Time\n";
	VectorNew<Time> v;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		v.add(t);
	}
	cout << v << endl;
	cout << "\nДобавление\n";  v.add();
	cout << v << endl;
	cout << "\nУдаление\n";  v.del();
	cout << v << endl;
	cout << "\nИзменение\n";  v.update();
	cout << v << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(0));
	//first();
	//second();
	//third();
	//fourth();
	fifth();
	return 0;
}