#pragma once
#include "Account.h"

class HashTable
{
private:
	int size;
	int length;
	Account** table;
	int countCollision;

public:
	HashTable(int n)
	{
		length = 0;
		size = n;
		table = new Account * [size];
		for (int i = 0; i < size; i++)
			table[i] = 0;
		countCollision = 0;
	}

	~HashTable()
	{
		for (int i = 0; i < size; i++)
			if (table[i] != 0)
				delete table[i];
		delete[] table;
	}

	int getCollision()
	{
		return countCollision;
	}

	void randForm(int n)
	{
		length += n;
		if (length > size)
		{
			cout << "�� ������� �����\n";
			return;
		}
		for (int i = 0; i < n; i++)
		{
			Account* temp = new Account();
			int ind = abs(getHashCode(*temp));
			if (table[ind] == 0)		// ���� ��������
				table[ind] = temp;
			else	// ���� ������
			{
				countCollision++;
				for (int j = ind + 1; j != ind; j++)	// ���� �� ��������� ������� �� �������� (������ ����)
				{
					if (j == size)	// ���� ����� �� �����, ������ �� ������
						j = 0;
					if (table[ind] == 0)	// ���� ����� ��������� �����
					{
						table[ind] = temp;
						break;
					}
				}
			}
		}
	}

	void show()
	{
		if (length == 0)
			cout << "�����\n";
		for (int i = 0; i < size; i++)
			if (table[i] != 0)
				cout << "#" << (i + 1) << " - " << *table[i]<<endl;
		cout << endl;
	}

	void find(string key)
	{
		Account ac(key, 0, 0.0f);
		int ind = abs(getHashCode(ac));
		if (table[ind] != 0 && table[ind]->getFio() == key)
		{
			cout << "#" << (ind + 1) << *table[ind] << endl;
			return;
		}
		else
		{
			int count = 0;
			for (int j = ind + 1; j != ind; j++, count++)	// ���� �� ��������� ������� �� �������� (������ ����)
			{
				if (j == size)	// ���� ����� �� �����, ������ �� ������
					j = 0;
				if (table[ind] != 0 && table[ind]->getFio() == key)	// ���� ����� ��������� �����
				{
					cout << "���������� ��������� = " << count << endl;
					cout << "#" << (ind + 1) << *table[ind] << endl;
					return;
				}
			}
			cout << "��� ������\n";
		}
	}

private:
	int getHashCode(Account& ac)
	{
		return ac.getHashCode() % size;
	}
};

