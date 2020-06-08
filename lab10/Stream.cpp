#include "Stream.h"

void makeFile(string path)
{
	ofstream out;
	try
	{
		out.open(path);
		if (!out.is_open())
			throw exception("Файл не открылся");
		int n;
		cout << "Количество временных интервалов? "; cin >> n;
		if (n < 1)
			throw exception("Введите значение больше 0");
		for (int i = 0; i < n; i++)
		{
			Time t(rand() % 20 + 5, rand() % 100 + 10);
			out << i << " " << t << endl; // записываем в файл
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
			throw exception("Файл не открылся");
		int i, m, s;
		char c;
		do
		{
			in >> i >> m >> c >> s;			// читаем строку
			if (in.eof())
				break;
			cout << m << c << s << endl;	// выводим на экран
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
			throw exception("Файл не открылся");
		out.open("temp.txt");
		cout << "Введите временной интервал для удаления\n";
		Time t, temp; cin >> t;
		int i, m, s, k = 0;
		char c;
		do
		{
			in >> i >> m >> c >> s;			
			if (in.eof())
				break;
			temp = Time(m, s);
			if (t != Time(m, s)) // если не равно
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
			throw exception("Файл не открылся");
		out.open("temp.txt");
		Time temp, tUpd, tMin(1, 30);
		cout << "Введите интервал для уменьшения\n"; cin >> tUpd;
		int i, m, s;
		char c;
		do
		{
			in >> i >> m >> c >> s;
			if (in.eof())
				break;
			temp = Time(m, s);
			if (tUpd != Time(m, s)) // если не равно
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
			throw exception("Файл не открылся");
		out.open("temp.txt");
		Time temp, t;
		cout << "Введите интервал\n"; cin >> t;
		int K, i, m, s, k=0;
		char c;
		cout << "Введите K = "; cin >> K;
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
