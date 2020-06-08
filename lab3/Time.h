#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int min;
	int sec;

public:
	Time() { min = sec = 0; }
	Time(int m, int s);
	Time(const Time& t) { min = t.min; sec = t.sec; }
	~Time() { cout << "ƒеструктор\n"; }

	int getMin() { return min; }
	int getSec() { return sec; }
	void setMin(int m);
	void setSec(int s);

	Time& operator= (const Time& t);
	friend istream& operator>> (istream& in, Time& t);
	friend ostream& operator<< (ostream& out, const Time& t);
	Time operator+ (int s); // добавление секунд
	Time operator- (int s); // вычитание секунд
};

