#pragma once

#include "Object.h"

class Vector
{
protected:
	Object** beg;
	int size;
	int curr;

public:
	Vector();
	Vector(int n);
	~Vector();
	void add();
	void del();
	void show();
	void avg();
};
