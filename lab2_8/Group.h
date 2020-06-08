#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Group  // группа
{
protected:
	int id;
	string name;
	int year;

public:
	Group() { id = 0; name = ""; year = 0; }
	Group(int i, string n, int y) { id = i; name = n;  year = y; }
	Group(const Group& g) { id = g.id; name = g.name; year = g.year; }
	~Group() { }

	int getId() { return id; }
	string getName() { return name; }
	int getYear() { return year; }

	Group& operator= (const Group& g)
	{
		if (this == &g)
			return *this;
		id = g.id;
		name = g.name;
		year = g.year;
		return *this;
	}

	bool operator== (const Group& g) { return id == g.id; }
	bool operator!= (const Group& g) { return id != g.id; }

	friend fstream& operator>> (fstream& in, Group& g)	// чтение с файла
	{
		in >> g.id >> g.name >> g.year;
		return in;
	}

	friend fstream& operator<< (fstream& out, const Group& g) // вывод в файл
	{
		out << g.id << " " << g.name << " " << g.year;
		return out;
	}

	friend ostream& operator<< (ostream& out, const Group& g) // вывод на консоль
	{
		out << g.name << "-" << g.year;
		return out;
	}
};

