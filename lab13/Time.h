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
	~Time() { }

	int getMin() { return min; }
	int getSec() { return sec; }
	void setMin(int m);
	void setSec(int s);

	Time& operator= (const Time& t);

	friend istream& operator>> (istream& in, Time& t);
	friend ostream& operator<< (ostream& out, const Time& t);

	friend Time operator- (const Time& t1, const Time& t2);

	friend bool operator== (const Time& t1, const Time& t2) { return t1.min == t2.min && t1.sec == t2.sec; }
	friend bool operator!= (const Time& t1, const Time& t2) { return t1.min != t2.min || t1.sec != t2.sec; }


	friend bool operator> (const Time& t1, const Time& t2) { return t1.min > t2.min || (t1.min == t2.min && t1.sec > t2.sec); }
	friend bool operator< (const Time& t1, const Time& t2) { return t1.min < t2.min || (t1.min == t2.min && t1.sec < t2.sec); }
};

