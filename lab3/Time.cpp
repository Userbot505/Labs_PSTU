#include "Time.h"
#include "Time.h"

Time::Time(int m, int s)
{
	if (m < 0)
		min = 0;
	else
		min = m;
	sec = s;
	while (sec > 59)
	{
		min++;
		sec -= 60;
	}
}

void Time::setMin(int m)
{
	if (m < 0)
		min = 0;
	else
		min = m;
}

void Time::setSec(int s)
{
	if (s < 0)
		sec = 0;
	else
	{
		sec = s;
		while (sec > 59)
		{
			min++;
			sec -= 60;
		}
	}
}

Time& Time::operator=(const Time& t)
{
	if (this == &t)
		return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator+(int s)
{
	sec = sec + s;
	while (sec > 59)
	{
		min++;
		sec -= 60;
	}
	return Time(min, sec);
}

Time Time::operator-(int s)
{
	sec = sec - s;
	while (sec < 0)
	{
		min--;
		sec += 60;
	}
	return Time(min, sec);
}

istream& operator>>(istream& in, Time& t)
{
	int x;
	cout << "Минуты? "; in >> x; t.setMin(x);
	cout << "Секунды? "; in >> x; t.setSec(x);
	return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << ":" << t.sec;
	return out;
}
