#pragma once
#include <iostream>
using namespace std;

class Error
{
protected:
	std::string msg;

public:
	virtual void what() = 0;
};

class IndexError : public Error
{
public:
	IndexError() { msg = "Ошибка индекса"; }
	void what() { cout << msg << endl; }
};

class OverSizeError : public Error
{
public:
	OverSizeError() { msg = "Нет места"; }
	void what() { cout << msg << endl; }
};