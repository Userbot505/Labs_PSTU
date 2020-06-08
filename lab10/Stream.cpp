#include "Stream.h"

void makeFile(string path)
{
	ofstream out;
	try
	{
		out.open(path);
		if (!out.is_open())
			throw exception("���� �� ��������");
		int n;
		cout << "���������� ��������� ����������? "; cin >> n;
		if (n < 1)
			throw exception("������� �������� ������ 0");
		for (int i = 0; i < n; i++)
		{
			Time t(rand() % 20 + 5, rand() % 100 + 10);
			out << i << " " << t << endl; // ���������� � ����
		}
		out.close();
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
		out.close();
	}
}

void readFile(string path)
{
	ifstream in;
	try
	{
		in.open(path);
		if (!in.is_open())
			throw exception("���� �� ��������");
		int i, m, s;
		char c;
		do
		{
			in >> i >> m >> c >> s;			// ������ ������
			if (in.eof())
				break;
			cout << m << c << s << endl;	// ������� �� �����
		} while (true);
		in.close();
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
		in.close();
	}
}

void del(string path)
{
	ifstream in;
	ofstream out;
	try
	{
		in.open(path);
		if(!in.is_open())
			throw exception("���� �� ��������");
		out.open("temp.txt");
		cout << "������� ��������� �������� ��� ��������\n";
		Time t, temp; cin >> t;
		int i, m, s, k = 0;
		char c;
		do
		{
			in >> i >> m >> c >> s;			
			if (in.eof())
				break;
			temp = Time(m, s);
			if (t != Time(m, s)) // ���� �� �����
				out << (k++)<<" " << temp<<endl;	
		} while (true);
		in.close();
		out.close();
		remove(path.c_str());
		rename("temp.txt", path.c_str());
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
		in.close(); out.close();
	}
}

void update(string path)
{
	ifstream in;
	ofstream out;
	try
	{
		in.open(path);
		if (!in.is_open())
			throw exception("���� �� ��������");
		out.open("temp.txt");
		Time temp, tUpd, tMin(1, 30);
		cout << "������� �������� ��� ����������\n"; cin >> tUpd;
		int i, m, s;
		char c;
		do
		{
			in >> i >> m >> c >> s;
			if (in.eof())
				break;
			temp = Time(m, s);
			if (tUpd != Time(m, s)) // ���� �� �����
				out << i << " " << temp << endl;
			else
				out << i << " " << (temp - tMin) << endl;
		} while (true);
		in.close();
		out.close();
		remove(path.c_str());
		rename("temp.txt", path.c_str());
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
		in.close(); out.close();
	}
}

void add(string path)
{
	ifstream in;
	ofstream out;
	try
	{
		in.open(path);
		if (!in.is_open())
			throw exception("���� �� ��������");
		out.open("temp.txt");
		Time temp, t;
		cout << "������� ��������\n"; cin >> t;
		int K, i, m, s, k=0;
		char c;
		cout << "������� K = "; cin >> K;
		do
		{
			in >> i >> m >> c >> s;
			if (in.eof())
				break;
			temp = Time(m, s);
			out << (k++) << " " << temp << endl;
			if (t == Time(m, s))
			{
				for (int i = 0; i < K; i++)
				{
					Time t(rand() % 20 + 5, rand() % 100 + 10);
					out << (k++) << " " << t << endl;
				}
			}
		} while (true);
		in.close();
		out.close();
		remove(path.c_str());
		rename("temp.txt", path.c_str());
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
		in.close(); out.close();
	}
}
