#pragma once

#include <iostream>
using namespace std;

class Iterator
{
	friend class Vector;
private:
	int* elem;

public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }

	bool operator== (const Iterator& it) { return elem == it.elem; }
	bool operator!= (const Iterator& it) { return elem != it.elem; }

	void operator++ (int) { ++elem; }
	void operator-- (int) { --elem; }	// ������� � �����������
	int& operator*() const { return *elem; }
};

class Vector
{
private:
	int size;
	int* data;

	Iterator beg;
	Iterator end;

public:
	Vector(int s, int k = 0);
	Vector(const Vector& v);
	~Vector();

	Vector& operator= (const Vector& v);
	friend ostream& operator<< (ostream& out, const Vector& v);
	friend istream& operator>> (istream& in, Vector& v);

	int& operator[] (int index); // �� �������
	Vector operator+ (const Vector& v);// �������� ��������
	Vector operator+ (int a); // �������� �����

	Iterator first() { return beg; }
	Iterator last() { return end; }
};
