#pragma once

#include <iostream>
using namespace std;

class Route
{
private:
	string start;
	string end;
	float time;

public:
	Route();
	Route(string s, string e, float t);
	Route(const Route& r);
	~Route();

	string getStart();
	string getEnd();
	float getTime();
	void setStart(string s);
	void setEnd(string e);
	void setTime(float f);

	void show();
};

