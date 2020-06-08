#pragma once
#include <iostream>
#include <deque>

using namespace std;

void show(deque<double>& deq)
{
	if (deq.empty())
		cout << "�����\n";
	for (auto it = deq.begin(); it != deq.end(); it++)
		cout << *it << "\t";
	cout << endl;
}

void add(deque<double>& deq)
{
	int pos;
	double key;
	cout << "������� ���� - "; cin >> key;
	key = round(key*100) / 100;
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

void del(deque<double>& deq)
{
	double key;
	cout << "������� ���� - "; cin >> key;
	key = round(key * 100) / 100;
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

void update(deque<double>& deq)
{
	auto it = deq.begin();
	double max = *it, min = *it;
	while (it != deq.end())
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
		it++;
	}
	double def = abs(max - min);
	cout << "������� = " << def << endl;
	for (it = deq.begin(); it != deq.end(); it++)
		*it -= def;
}
