#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
#include "Time.h"

using namespace std;

vector<Time> to_vector(priority_queue<Time> que)
{
	vector<Time> v;
	while (!que.empty())
	{
		v.push_back(que.top());
		que.pop();
	}
	return v;
}


priority_queue<Time> to_queue(vector<Time> v)
{
	priority_queue<Time> que;
	for (auto it = v.begin(); it != v.end(); it++)
		que.push(*it);
	return que;
}

void show(priority_queue<Time>& que)
{
	auto temp = to_vector(que);
	auto pred = [](Time& t) { cout << t << "\t"; };
	for_each(temp.begin(), temp.end(), pred);
	cout << endl;
}


void add(priority_queue<Time>& que)
{
	auto temp = to_vector(que);
	int pos;
	Time key;
	cout << "Введите ключ - "; cin >> key;
	cout << "Введите позицию - "; cin >> pos;
	auto iter = find(temp.begin(), temp.end(), key);
	if (iter != temp.end())
	{
		auto iter = temp.begin() + pos - 1;
		temp.insert(iter, key);
	}
	else
		cout << "Нет такого\n";
	que = to_queue(temp);
}

void del(priority_queue<Time>& que)
{
	auto temp = to_vector(que);
	Time key;
	cout << "Введите ключ - "; cin >> key;
	auto iter = find(temp.begin(), temp.end(), key);
	if (iter != temp.end())
	{
		auto it = remove(temp.begin(), temp.end(), key);
		temp.erase(it, temp.end());
	}
	else
		cout << "Нет такого\n";
	que = to_queue(temp);
}

void update(priority_queue<Time>& que)
{
	auto temp = to_vector(que);
	auto max = max_element(temp.begin(), temp.end());
	auto min = min_element(temp.begin(), temp.end());
	Time def = *max - *min;
	cout << "Разница = " << def << endl;
	auto pred = [&def](Time& t) { t = t - def; };
	for_each(temp.begin(), temp.end(), pred);
	que = to_queue(temp);
}
