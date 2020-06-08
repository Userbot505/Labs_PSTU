#pragma once
#include <iostream>
#include <deque>
#include <algorithm>
#include "Time.h"

using namespace std;

void show(deque<Time>& deq)
{
	auto pred = [](Time& t) { cout << t << "\t"; };
	for_each(deq.begin(), deq.end(), pred);
	cout << endl;
}

void add(deque<Time>& deq)
{
	int pos;
	Time key;
	cout << "Введите ключ - "; cin >> key;
	cout << "Введите позицию - "; cin >> pos;
	auto iter = find(deq.begin(), deq.end(), key);
	if (iter != deq.end())
	{
		auto temp = deq.begin() + pos - 1;
		deq.insert(temp, key);
	}
	else
		cout << "Нет такого\n";
}

void del(deque<Time>& deq)
{
	Time key;
	cout << "Введите ключ - "; cin >> key;
	auto iter = find(deq.begin(), deq.end(), key);
	if (iter != deq.end())
	{
		auto it = remove(deq.begin(), deq.end(), key);
		deq.erase(it, deq.end());
	}
	else
		cout << "Нет такого\n";
}

void update(deque<Time>& deq)
{
	auto max = max_element(deq.begin(), deq.end());
	auto min = min_element(deq.begin(), deq.end());
	Time def = *max - *min;
	cout << "Разница = " << def << endl;
	auto pred = [&def](Time& t) { t = t - def; };
	for_each(deq.begin(), deq.end(), pred);
}