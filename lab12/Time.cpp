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


Time operator- (const Time& t1, const Time& t2)
{
	Time temp(t1.min, t1.sec);
	int s = t2.min * 60 + t2.sec;
	temp.sec = temp.sec - s;
	while (temp.sec < 0)
	{
		temp.min--;
		temp.sec += 60;
	}
	if (temp.min < 0)
	{
		temp.min = temp.sec = 0;
	}
	return temp;
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
