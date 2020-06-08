#pragma once
#include "Pair.h"
class Rightangled : public Pair
{
public:
	Rightangled() :Pair() {}
	Rightangled(int a, int b);
	Rightangled(const Rightangled& r) : Pair(r) {}

	void setFirst(int a);
	void setSecond(int b);

	Rightangled& operator= (const Rightangled& r);
	friend istream& operator>> (istream& in, Rightangled& r);
	friend ostream& operator<< (ostream& out, const Rightangled& r);

	double gipotinusa();
};

