#pragma once
#include <iostream>
#include <queue>
#include <vector>
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
	while (!que.empty())
	{
		cout << que.top() << "\t";
		que.pop();
	}
	que = to_queue(temp);
	cout << endl;
}


void add(priority_queue<Time>& que)
{
	int pos;
	Time key;
	cout << "Введите ключ - "; cin >> key;
	cout << "Введите позицию - "; cin >> pos;
	auto temp = to_vector(que);
	auto it = temp.begin();
	while (it != temp.end())
	{
		if (*it == key)
		{
			auto iter = temp.begin() + pos - 1;
			temp.insert(iter, key);
			que = to_queue(temp);
			return;
		}
		it++;
	}
	cout << "Нет такого\n";
	que = to_queue(temp);
}

void del(priority_queue<Time>& que)
{
	Time key;
	cout << "Введите ключ - "; cin >> key;
	auto temp = to_vector(que);
	auto it = temp.begin();
	while (it != temp.end())
	{
		if (*it == key)
		{
			temp.erase(it);
			que = to_queue(temp);
			return;
		}
		it++;
	}
	cout << "Нет такого\n";
	que = to_queue(temp);
}

void update(priority_queue<Time>& que)
{
	auto temp = to_vector(que);
	auto it = temp.begin();
	Time max = *it, min = *it;
	while (it != temp.end())
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
		it++;
	}
	Time def = max - min;
	cout << "Разница = " << def << endl;
	for (it = temp.begin(); it != temp.end(); it++)
		*it = *it - def;
	que = to_queue(temp);
}


