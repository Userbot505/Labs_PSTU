#pragma once
#include "Pair.h"
class Rightangled: public Pair
{
public:
	Rightangled(int a, int b) : Pair(a, b) { }
	~Rightangled() { cout << "Rightangled ����������\n"; }

	void show() { cout << "(" << first << ", " << second << ")" << endl; }
};

