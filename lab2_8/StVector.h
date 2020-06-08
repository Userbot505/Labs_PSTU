#pragma once
#include <map>
#include <fstream>
#include "Student.h"
#include <string>

class StVector
{
private:
	int lastInsertId = 1; // номер последнего добавленного студента, чтобы ключи были уникальными
	Group group;
	map<int, Student> students;
	string path;
	fstream stream;	// файловый поток 

public:
	StVector() { }

	~StVector() 
	{
		students.clear(); 
	}

	void setGroup(Group& g)	// при смене группы
	{
		if (g != Group()) // если введена группа для работы с ней
		{
			group = g;
			path = g.getName() + "-" + to_string(g.getYear()) + ".txt";
			read();
		}	
		else	// если закончили работу с группой
		{
			save();
			students.clear();
			lastInsertId = 1;
			path = "";
		}
	}

	StVector& operator= (const StVector v) // оператор сравнения
	{
		if (this == &v)
			return *this;
		group = v.group;
		students = v.students;
		path = v.path;
		return *this;
	}

	void show()	// показать
	{
		cout << "Список студентов\n";
		for (auto it = students.begin(); it != students.end(); it++)
			cout << it->second << endl;
	}

	void add()	// добавить
	{
		Student st;
		cout << "Введите данные студента\n";
		cin >> st;
		st.setId(lastInsertId++);
		students[st.getId()] = st;
	}

	void del() // удалить
	{
		int key;
		cout << "Введите номер - "; cin >> key;
		int c = students.erase(key);
		if (c == 0)
			cout << "Такого нет\n";
	}

	void update()	// изменить
	{
		int key;
		cout << "Введите номер - "; cin >> key;
		auto iter = students.find(key);
		if (iter == students.end())
			cout << "Такого нет\n";
		else
		{
			Student st;
			cout << "Введите данные студента\n";
			cin >> st;
			st.setId(iter->second.getId());
			students[key] = st;
		}
	}

private:
	void save()	// сохранить
	{
		try
		{
			stream.open(path, ios::out);
			if (!stream.is_open())
				throw exception("Не удалось открыть файл");
			stream << lastInsertId << endl;
			for (auto it = students.begin(); it != students.end(); it++)
				stream << it->second << endl;
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
		stream.close();
	}

	void read() // читать
	{
		try
		{
			stream.open(path, ios::in);
			if (!stream.is_open())
				throw exception("Не удалось открыть файл");
			students.clear();
			Student temp;
			stream >> lastInsertId;
			do
			{
				stream >> temp;
				if (stream.eof())
					break;
				students[temp.getId()] = temp;
			} while (true);
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
		stream.close();
	}
};

