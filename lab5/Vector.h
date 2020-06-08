#pragma once
#include "Object.h"

class Vector
{
private:
	Object** arr;
	int curr;
	int size;

public:
	Vector(int n);
	~Vector();
	void add(Object* obj);
	friend ostream& operator<< (ostream& out, const Vector& v);
};

