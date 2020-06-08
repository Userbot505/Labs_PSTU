#pragma once
#include <map>
#include <fstream>
#include "Student.h"
#include <string>

class StVector
{
private:
	int lastInsertId = 1; // ����� ���������� ������������ ��������, ����� ����� ���� �����������
	Group group;
	map<int, Student> students;
	string path;
	fstream stream;	// �������� ����� 

public:
	StVector() { }

	~StVector() 
	{
		students.clear(); 
	}

	void setGroup(Group& g)	// ��� ����� ������
	{
		if (g != Group()) // ���� ������� ������ ��� ������ � ���
		{
			group = g;
			path = g.getName() + "-" + to_string(g.getYear()) + ".txt";
			read();
		}	
		else	// ���� ��������� ������ � �������
		{
			save();
			students.clear();
			lastInsertId = 1;
			path = "";
		}
	}

	StVector& operator= (const StVector v) // �������� ���������
	{
		if (this == &v)
			return *this;
		group = v.group;
		students = v.students;
		path = v.path;
		return *this;
	}

	void show()	// ��������
	{
		cout << "������ ���������\n";
		for (auto it = students.begin(); it != students.end(); it++)
			cout << it->second << endl;
	}

	void add()	// ��������
	{
		Student st;
		cout << "������� ������ ��������\n";
		cin >> st;
		st.setId(lastInsertId++);
		students[st.getId()] = st;
	}

	void del() // �������
	{
		int key;
		cout << "������� ����� - "; cin >> key;
		int c = students.erase(key);
		if (c == 0)
			cout << "������ ���\n";
	}

	void update()	// ��������
	{
		int key;
		cout << "������� ����� - "; cin >> key;
		auto iter = students.find(key);
		if (iter == students.end())
			cout << "������ ���\n";
		else
		{
			Student st;
			cout << "������� ������ ��������\n";
			cin >> st;
			st.setId(iter->second.getId());
			students[key] = st;
		}
	}

private:
	void save()	// ���������
	{
		try
		{
			stream.open(path, ios::out);
			if (!stream.is_open())
				throw exception("�� ������� ������� ����");
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

	void read() // ������
	{
		try
		{
			stream.open(path, ios::in);
			if (!stream.is_open())
				throw exception("�� ������� ������� ����");
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

