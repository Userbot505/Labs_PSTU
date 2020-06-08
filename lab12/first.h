#pragma once

#include <iostream>
#include <set>
using namespace std;

void show(multiset<double>& set)
{
	if (set.empty())
		cout << "�����\n";
	for (auto it = set.begin(); it != set.end(); it++)
		cout << *it << "\t";
	cout << endl;
}

void add(multiset<double>& set)
{
	int pos;
	double key;
	cout << "������� ���� - "; cin >> key;
	key = round(key * 100) / 100;
	cout << "������� ������� - "; cin >> pos;
	auto it = set.begin();
	while (it != set.end())
	{
		if (*it == key)
		{
			auto temp = set.begin();
			for(int i=0; i<pos; i++)
				temp++;
			set.insert(temp, key);
			return;
		}
		it++;
	}
	cout << "��� ������\n";
}


