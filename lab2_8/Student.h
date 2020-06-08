#pragma once
#include "Group.h"

class Student	// �������
{
private:
	int id;
	string name;
	int year;

public:
	Student() { id = year = 0; name = ""; }
	Student(int i, string n, int y) { id = i; name = n; year = y; }
	Student(const Student& s) { id = s.id; name = s.name; year = s.year; }
	~Student() { }

	void setId(int i) { id = i; }
	int getId() { return id; }
	string getName() { return name; }

	Student& operator= (const Student& s)	// ����������
	{
		if (this == &s)
			return *this;
		id = s.id;
		name = s.name;
		year = s.year;
		return *this;
	}

	friend fstream& operator>> (fstream& in, Student& s) // ������ � �����
	{
		in >> s.id >> s.name >> s.year;
		return in;
	}

	friend fstream& operator<< (fstream& out, Student& s) // ������ � ����
	{
		out << s.id << " " << s.name << " " << s.year;
		return out;
	}

	friend ostream& operator<< (ostream& out, const Student& s) // ����� � �������
	{
		out << "#" << s.id << " - " << s.name << ", " << s.year << " (���)";
		return out;
	}

	friend istream& operator>> (istream& in, Student& s)
	{
		cout << "���? "; in >> s.name;
		cout << "�������? "; in >> s.year;
		return in;
	}
};

