#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Account
{
private:
	string fio;
	int number;
	float sum;

public:
	Account()
	{
		fio = fNames[rand() % fNames.size()] + " " + sNames[rand() % sNames.size()] + " " + tNames[rand() % tNames.size()];
		number = rand() % 1000000000;
		sum = (float)(rand() % 10000000000) * 0.01f;
	}

	Account(string f, int n, float s)
	{
		fio = f;
		number = n;
		sum = s;
	}
	~Account()
	{
	}

	string getFio()
	{
		return fio;
	}

	int getHashCode()
	{
		int s = 0;
		for (int i = 0; i < fio.length(); i++)
			s += fio[i] - '0';
		return s;
	}

	friend ostream& operator<< (ostream& out, const Account& ac)
	{
		out << ac.fio << ", �" << ac.number << ", " << ac.sum << " ���.";
		return out;
	}

private:
	vector<string> fNames = { "������","������","�������","�����","����","��������","������","���","����","������","�����","�����" };
	vector<string> sNames = { "����","����","�����","������","����","�������","�����","������","�����","�����","��������","����","�������","������","�������" };
	vector<string> tNames = { "��������","��������","���������","����������","��������","�����������","���������","����������","��������","���������", "������������","��������","����������","����������","����������" };
};