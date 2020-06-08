#pragma once

#include <iostream>
#include <set>
#include "Time.h"
using namespace std;

void show(multiset<Time>& set)
{
	if (set.empty())
		cout << "Пусто\n";
	for (auto it = set.begin(); it != set.end(); it++)
		cout << *it << "\t";
	cout << endl;
}

void del(multiset<Time>& set)
{
	Time key;
	cout << "Введите ключ - "; cin >> key;
	auto it = set.begin();
	while (it != set.end())
	{
		if (*it == key)
		{
			set.erase(it);
			return;
		}
		it++;
	}
	cout << "Нет такого\n";
}
