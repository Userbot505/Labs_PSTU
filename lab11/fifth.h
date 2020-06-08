#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <class T>
class VectorNew
{
private:
	priority_queue<T> que;

	vector<T> to_vector(priority_queue<T> que);
	priority_queue<T> to_queue(vector<T> v);

public:
	VectorNew();
	~VectorNew();

	void add(T val);

	VectorNew<T>& operator= (const VectorNew& v);
	friend ostream& operator<< <>(ostream& out, VectorNew<T>& v);

	void add();
	void del();
	void update();
};

template<class T>
VectorNew<T>::VectorNew()
{
}

template<class T>
VectorNew<T>::~VectorNew()
{
	while (!que.empty())
		que.pop();
}

template<class T>
void VectorNew<T>::add(T val)
{
	que.push(val);
}

template<class T>
VectorNew<T>& VectorNew<T>::operator=(const VectorNew<T>& v)
{
	if (this == &v)
		return *this;
	que.clear();
	for (auto it = v.que.begin(); it != v.que.end(); it++)
		que.push(*it);
	return *this;
}

template<class T>
vector<T> VectorNew<T>::to_vector(priority_queue<T> que)
{
	vector<T> v;
	while (!que.empty())
	{
		v.push_back(que.top());
		que.pop();
	}
	return v;
}

template<class T>
priority_queue<T> VectorNew<T>::to_queue(vector<T> v)
{
	priority_queue<T> que;
	for (auto it = v.begin(); it != v.end(); it++)
		que.push(*it);
	return que;
}

template<class T>
ostream& operator<< (ostream& out, VectorNew<T>& v)
{
	if (v.que.empty())
		out << "Пусто\n";
	auto temp = to_vector(v.que);
	while (!v.que.empty())
	{
		out << v.que.top() << "\t";
		v.que.pop();
	}
	v.que = to_queue(temp);
	return out;
}

template<class T>
void VectorNew<T>::add()
{
	int pos;
	T key;
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

template<class T>
void VectorNew<T>::del()
{
	T key;
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

template<class T>
void VectorNew<T>::update()
{
	auto temp = to_vector(que);
	auto it = temp.begin();
	T max = *it, min = *it;
	while (it != temp.end())
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
		it++;
	}
	T def = max - min;
	cout << "Разница = " << def << endl;
	for (it = temp.begin(); it != temp.end(); it++)
		*it = *it - def;
	que = to_queue(temp);
}
