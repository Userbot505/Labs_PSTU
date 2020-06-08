#include <ctime>
#include "first.h"
#include "second.h"
#include "third.h"
#include "fourth.h"
#include "fifth.h"

void first()
{
	cout << "��������������� ������� � ����� double\n";
	deque<double> deq;
	double x;
	for (int i = 0; i < 6; i++)
	{
		x = (double)(rand() % 100 - 50) * 0.1;
		x = round(x * 100) / 100;
		deq.push_back(x);
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
	cout << "��������������� ������� � ����� Time\n";
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


void third()
{
	cout << "��������������� ������� � ����� Time\n";
	Vector<Time> v;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		v.add(t);
	}
	cout << v << endl;
	cout << "\n����������\n";  v.add();
	cout << v << endl;
	cout << "\n��������\n";  v.del();
	cout << v << endl;
	cout << "\n���������\n";  v.update();
	cout << v << endl;
}

void fourth()
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

void fifth()
{
	cout << "��������������� ������� � ����� Time\n";
	VectorNew<Time> v;
	Time t;
	for (int i = 0; i < 6; i++)
	{
		t = Time(rand() % 20 + 5, rand() % 100 + 10);
		v.add(t);
	}
	cout << v << endl;
	cout << "\n����������\n";  v.add();
	cout << v << endl;
	cout << "\n��������\n";  v.del();
	cout << v << endl;
	cout << "\n���������\n";  v.update();
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