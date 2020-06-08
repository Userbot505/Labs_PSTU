#pragma once
#include "Group.h"

class Student	// студент
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

	Student& operator= (const Student& s)	// присвоение
	{
		if (this == &s)
			return *this;
		id = s.id;
		name = s.name;
		year = s.year;
		return *this;
	}

	friend fstream& operator>> (fstream& in, Student& s) // чтение с файла
	{
		in >> s.id >> s.name >> s.year;
		return in;
	}

	friend fstream& operator<< (fstream& out, Student& s) // запись в файл
	{
		out << s.id << " " << s.name << " " << s.year;
		return out;
	}

	friend ostream& operator<< (ostream& out, const Student& s) // вывод в консоль
	{
		out << "#" << s.id << " - " << s.name << ", " << s.year << " (лет)";
		return out;
	}

	friend istream& operator>> (istream& in, Student& s)
	{
		cout << "Имя? "; in >> s.name;
		cout << "Возраст? "; in >> s.year;
		return in;
	}
};

