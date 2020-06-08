#pragma once
#include <iostream>
#include <deque>
#include "Time.h"

using namespace std;

void show(deque<Time>& deq)
{
	if (deq.empty())
		cout << "�����\n";
	for (auto it = deq.begin(); it != deq.end(); it++)
		cout << *it << "\t";
	cout << endl;
}

void add(deque<Time>& deq)
{
	int pos;
	Time key;
	cout << "������� ���� - "; cin >> key;
	cout << "������� ������� - "; cin >> pos;
	auto it = deq.begin();
	while (it != deq.end())
	{
		if (*it == key)
		{
			auto temp = deq.begin() + pos - 1;
			deq.insert(temp, key);
			return;
		}
		it++;
	}
	cout << "��� ������\n";
}

void del(deque<Time>& deq)
{
	Time key;
	cout << "������� ���� - "; cin >> key;
	auto it = deq.begin();
	while (it != deq.end())
	{
		if (*it == key)
		{
			deq.erase(it);
			return;
		}
		it++;
	}
	cout << "��� ������\n";
}

void update(deque<Time>& deq)
{
	auto it = deq.begin();
	Time max = *it, min = *it;
	while (it != deq.end())
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
		it++;
	}
	Time def = max - min;
	cout << "������� = " << def << endl;
	for (it = deq.begin(); it != deq.end(); it++)
		*it = *it - def;
}
