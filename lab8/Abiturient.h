#pragma once
#include "Person.h"
class Abiturient : public Person
{
private:
	int sum;
	string spec;

public:
	Abiturient():Person(){}
	Abiturient(string n, int a, int s, string sp) :Person(n, a) { sum = s; spec = sp; }
	~Abiturient() {}

	void show();
	void input();
};

