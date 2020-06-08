#pragma once

#include <iostream>
#include <set>
using namespace std;

template <class T>
class Vector
{
private:
	multiset<T> set;

public:
	Vector();
	~Vector();

	void add(T val);

	Vector<T>& operator= (const Vector& v);
	friend ostream& operator<< <>(ostream& out, const Vector<T>& v);

	void update();
};

template<class T>
Vector<T>::Vector()
{
}

template<class T>
Vector<T>::~Vector()
{
	set.clear();
}

template<class T>
void Vector<T>::add(T val)
{
	set.insert(val);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this == &v)
		return *this;
	set.clear();
	for (auto it = v.set.begin(); it != v.set.end(); it++)
		set.insert(*it);
	return *this;
}

template<class T>
ostream& operator<< (ostream& out, const Vector<T>& v)
{
	if (v.set.size() == 0)
		out << "Пусто\n";
	for (auto it = v.set.begin(); it != v.set.end(); it++)
		out << *it << "\t";
	return out;
}


template<class T>
void Vector<T>::update()
{
	auto it = set.begin();
	T max = *it, min = *it;
	while (it != set.end())
	{
		if (*it > max)
			max = *it;
		if (*it < min)
			min = *it;
		it++;
	}
	T def = max - min;
	cout << "Разница = " << def << endl;
	T temp;
	it = set.end();
	multiset<T> tempSet;
	for (it = set.begin(); it != set.end(); it++)
	{
		temp = *it;
		temp = temp - def;
		tempSet.insert(temp);
	}
	set.clear();
	set = tempSet;
}
