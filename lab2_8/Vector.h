#pragma once
#include <map>
#include <fstream>
#include "Student.h"
#include <vector>
#include <string>
#include <algorithm>


class Vector
{
private:
	map<int, Group, std::greater<int>> groups;	// номера групп отсотрированы в пор€дке убывани€
	fstream stream;		// файловый поток двунаправленный
	string path = "groups.txt";

public:
	Vector() 
	{
		read();
	}

	~Vector() 
	{ 
		save();
		groups.clear();
	}

	void show()	// показать
	{
		cout << "—писок групп\n";
		for (auto it = groups.begin(); it != groups.end(); it++)
			cout << it->second << endl;
	}

	Group getGroupByName(string name)	// получение группы по имени
	{
		for (auto it = groups.begin(); it != groups.end(); it++)
			if (it->second.getName() == name)	// если равные имена то возвращаем
				return it->second;
		cout << "“акого нет\n";
		return Group();		// иначе возвращаем пустой
	}

	void query1()	// запрос 1 - список студентов с сортирвкой по имени
	{
		string str; int l;
		vector<Student> v;	// доп вектор
		for (auto grIter = groups.begin(); grIter != groups.end(); grIter++)	// идем по группам
		{
			try
			{	
				str = grIter->second.getName() + "-" + to_string(grIter->second.getYear()) + ".txt";
				stream.open(str, ios::in);
				if (!stream.is_open())
					throw 1;
				Student temp;
				stream >> l;
				do
				{
					stream >> temp;
					if (stream.eof())
						break;
					v.push_back(temp);		// записываем в вектор
				} while (true);
			}
			catch (int)
			{ }
			stream.close();
		}
		auto pred = [](Student& s1, Student& s2) { return s1.getName() < s2.getName(); };
		sort(v.begin(), v.end(), pred);		// сортируем по имени студента
		try
		{
			stream.open("query1.txt", ios::out);
			if (!stream.is_open())
				throw 1;
			for (auto it = v.begin(); it != v.end(); it++)
				stream << *it << endl;	// записываем в новый файл
		}
		catch(int)
		{ }
		stream.close();
	}

	void query2() // запрос 2 - список студентов с убыванием номера группы
	{
		string str; int l;
		vector<Student> v;
		for (auto grIter = groups.begin(); grIter != groups.end(); grIter++)	// идем по группам
		{
			try
			{
				str = grIter->second.getName() + "-" + to_string(grIter->second.getYear()) + ".txt";
				stream.open(str, ios::in);
				if (!stream.is_open())
					throw 1;
				Student temp;
				stream >> l;
				do
				{
					stream >> temp;
					if (stream.eof())
						break;
					v.push_back(temp);	// копируем в вектор
				} while (true);
			}
			catch (int)
			{
			}
			stream.close();
		}
		try
		{
			stream.open("query2.txt", ios::out);
			if (!stream.is_open())
				throw 1;
			for (auto it = v.begin(); it != v.end(); it++)
				stream << *it << endl;		// записываем в файл
		}
		catch (int)
		{
		}
		stream.close();
	}

private:
	void save()	// сохранение
	{
		try
		{
			stream.open(path, ios::out);
			if (!stream.is_open())
				throw exception("Ќе удалось открыть файл");
			for (auto it = groups.begin(); it != groups.end(); it++)
				stream << it->second << endl;	// сохран€ем по строчно
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
		stream.close();
	}

	void read() // чтение
	{
		try
		{
			stream.open(path, ios::in);
			if (!stream.is_open())
				throw exception("Ќе удалось открыть файл");
			groups.clear();
			Group temp;
			do
			{
				stream >> temp;			// читаем по строчно
				if (stream.eof())
					break;
				groups[temp.getId()] = temp;	// записываем в словарь
			} while (true);
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
		stream.close();
	}
};

