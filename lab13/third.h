#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include "Time.h"

using namespace std;

void show(map<int, Time>& dic)
{
	auto pred = [](pair<int, Time> p) { cout << p.first << " - "<< p.second << "\t"; };
	for_each(dic.begin(), dic.end(), pred);
	cout << endl;
}

void add(map<int, Time>& dic)
{
	int pos;
	Time key;
	cout << "Введите ключ - "; cin >> key;
	cout << "Введите позицию - "; cin >> pos;
	auto pred = [&key](const pair<int, Time> p) { return p.second == key; };
	auto iter = find_if(dic.begin(), dic.end(), pred);	// ищем по значению
	if (iter != dic.end())
	{
		int x;
		while (true)
		{
			x = rand() % 100 + 50;			
			if (dic.find(x) == dic.end())		// ищем уникальный ключ для пары
			{
				dic[x] = key;
				break;
			}
		}
	}
	else
		cout << "Нет такого\n";
}


void del(map<int, Time>& dic)
{
	Time key;
	cout << "Введите ключ - "; cin >> key;
	auto pred = [&key](const pair<int, Time> p) { return p.second == key; };
	auto iter = find_if(dic.begin(), dic.end(), pred);	// ищем по значению
	if (iter != dic.end())
		dic.erase(iter);
	else
		cout << "Нет такого\n";
}

void update(map<int, Time>& dic)
{
	auto it = dic.begin();
	Time max=it->second, min = it->second;
	auto predFind = [&max, &min](pair<int, Time> p)
	{
		if (p.second > max) max = p.second;
		if (p.second < min) min = p.second;
	};
	for_each(dic.begin(), dic.end(), predFind);
	Time def = max - min;
	cout << "Разница = " << def << endl;
	auto pred = [&dic, &def](pair<int, Time> p) { dic[p.first] = p.second - def; };
	for_each(dic.begin(), dic.end(), pred);
}