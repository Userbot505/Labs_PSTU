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
	map<int, Group, std::greater<int>> groups;	// ������ ����� ������������� � ������� ��������
	fstream stream;		// �������� ����� ���������������
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

	void show()	// ��������
	{
		cout << "������ �����\n";
		for (auto it = groups.begin(); it != groups.end(); it++)
			cout << it->second << endl;
	}

	Group getGroupByName(string name)	// ��������� ������ �� �����
	{
		for (auto it = groups.begin(); it != groups.end(); it++)
			if (it->second.getName() == name)	// ���� ������ ����� �� ����������
				return it->second;
		cout << "������ ���\n";
		return Group();		// ����� ���������� ������
	}

	void query1()	// ������ 1 - ������ ��������� � ���������� �� �����
	{
		string str; int l;
		vector<Student> v;	// ��� ������
		for (auto grIter = groups.begin(); grIter != groups.end(); grIter++)	// ���� �� �������
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
					v.push_back(temp);		// ���������� � ������
				} while (true);
			}
			catch (int)
			{ }
			stream.close();
		}
		auto pred = [](Student& s1, Student& s2) { return s1.getName() < s2.getName(); };
		sort(v.begin(), v.end(), pred);		// ��������� �� ����� ��������
		try
		{
			stream.open("query1.txt", ios::out);
			if (!stream.is_open())
				throw 1;
			for (auto it = v.begin(); it != v.end(); it++)
				stream << *it << endl;	// ���������� � ����� ����
		}
		catch(int)
		{ }
		stream.close();
	}

	void query2() // ������ 2 - ������ ��������� � ��������� ������ ������
	{
		string str; int l;
		vector<Student> v;
		for (auto grIter = groups.begin(); grIter != groups.end(); grIter++)	// ���� �� �������
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
					v.push_back(temp);	// �������� � ������
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
				stream << *it << endl;		// ���������� � ����
		}
		catch (int)
		{
		}
		stream.close();
	}

private:
	void save()	// ����������
	{
		try
		{
			stream.open(path, ios::out);
			if (!stream.is_open())
				throw exception("�� ������� ������� ����");
			for (auto it = groups.begin(); it != groups.end(); it++)
				stream << it->second << endl;	// ��������� �� �������
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
		stream.close();
	}

	void read() // ������
	{
		try
		{
			stream.open(path, ios::in);
			if (!stream.is_open())
				throw exception("�� ������� ������� ����");
			groups.clear();
			Group temp;
			do
			{
				stream >> temp;			// ������ �� �������
				if (stream.eof())
					break;
				groups[temp.getId()] = temp;	// ���������� � �������
			} while (true);
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
		stream.close();
	}
};

