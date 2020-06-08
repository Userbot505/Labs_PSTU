#pragma once
#include "Object.h"
class Person : public Object
{
protected:
	string name;
	int age;

public:
	Person(){}
	Person(string n, int a) :Object() { name = n; age = a; }
	~Person() {}

	void show();
	void input();

	int getAge() { return age; }
};

