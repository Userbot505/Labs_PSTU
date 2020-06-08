#include "Route.h"

Route::Route()
{
	start = "Пусто"; end = "Пусто"; time = 0.0f;

}

Route::Route(string s, string e, float t)
{
	start = s;
	end = e;
	if (t < 0)
		time = 0;
	else
		time = t;
}

Route::Route(const Route& r)
{
	start = r.start;
	end = r.end;
	time = r.time;
}

Route::~Route()
{
	cout << "Деструктор\n";
}

string Route::getStart()
{
	return start;
}

string Route::getEnd()
{
	return end;
}

float Route::getTime()
{
	return time;
}

void Route::setStart(string s)
{
	start = s;
}

void Route::setEnd(string e)
{
	end = e;
}

void Route::setTime(float f)
{
	if (f < 0)
		time = 0;
	else
		time = f;
}

void Route::show()
{
	cout << "Маршрут: " << start << " - " << end << ", " << time << " мин."<<endl;

}
