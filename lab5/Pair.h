#pragma once
#include "Object.h"

class Pair: public Object
{
protected:
	int first, second;

public:
	Pair(int f, int s) { first = f; second = s; }
	~Pair() { cout << "Pair деструктор\n"; }

	void show() { cout << "[" << first << ", " << second << "]" << endl; }
};

