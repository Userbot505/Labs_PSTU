#pragma once
#include <iostream>
#include <deque>
using namespace std;

template <class T>
class Vector
{
private:
	deque<T> deq;

public:
	Vector();
	~Vector();

	void add(T val);

	Vector<T>& operator= (const Vector& v);
	friend ostream& operator<< <>(ostream& out, const Vector<T>& v);

	void add();
	void del();
	void update();
};

template<class T>
Vector<T>::Vector()
{
}

template<class T>
Vector<T>::~Vector()
{
	deq.clear();
}

template<class T>
void Vector<T>::add(T val)
{
	deq.push_back(val);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this == &v)
		return *this;
	deq.clear();
	for (auto it = v.deq.begin(); it != v.deq.end(); it++)
		deq.push_back(*it);
	return *this;
}

template<class T>
ostream& operator<< (ostream& out, const Vector<T>& v)
{
	if (v.deq.size() == 0)
		out << "Пусто\n";
	for (auto it = v.deq.begin(); it != v.deq.end(); it++)
		out << *it << "\t";
	return out;
}

template<class T>
void Vector<T>::add()
{
	int pos;
	T key;
	cout << "Введите ключ - "; cin >> key;
	cout << "Введите позицию - "; cin >> pos;
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
	cout << "Нет такого\n";
}

template<class T>
void Vector<T>::del()
{
	T key;
	cout << "Введите ключ - "; cin >> key;
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
	cout << "Нет такого\n";
}

template<class T>
void Vector<T>::update()
{
	auto it = deq.begin();
	T max = *it, min = *it;
	while (it != deq.end())
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
		it++;
	}
	T def = max - min;
	cout << "Разница = " << def << endl;
	for (it = deq.begin(); it != deq.end(); it++)
		*it = *it - def;
}
