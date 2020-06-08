#pragma once
#include <iostream>
using namespace std;

class Pair
{
protected:
	int first, second;

public:
	Pair() { first = second = 0; }
	Pair(int f, int s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() { cout << "Деструктор\n"; }

	int getFirst() { return first; }
	int getSecond() { return second; }
	// методы изменения полей
	void setFirst(int f) { first = f; }
	void setSecond(int s) { second = s; }

	Pair& operator= (const Pair& p);
	friend istream& operator>> (istream& in, Pair& p);
	friend ostream& operator<< (ostream& out, const Pair& p);

	Pair operator* (const Pair& p); // произведение чисел
};

