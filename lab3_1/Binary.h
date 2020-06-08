#pragma once
#include <iostream>
#include <string>
using namespace std;

string buf;

struct Point
{
	char* data;
	Point* left;
	Point* right;

	Point(const char* s)
	{
		data = new char[strlen(s)];
		strcpy(data, s);
		left = 0;
		right = 0;
	}

	~Point()
	{
		delete data;
	}
};

Point* addPoint(Point* root, int n)
{
	Point* p = root;
	int nl, nr;
	if (n == 0) {		// если закончили добавлять
		p = 0;
		return p;
	}
	nl = n / 2;			// количество в левом поддереве
	nr = n - nl - 1;	// в правом поддереве
	cout << "Введите строку? "; 
	getline(cin, buf);
	Point* r = new Point(buf.c_str());
	r->left = addPoint(r->left, nl);		// идем в левое
	r->right = addPoint(r->right, nr);		// идем в правое
	return r;
}

void showPoint(Point* root, int l)
{
	Point* p = root;
	if (p)
	{
		showPoint(p->right, l + 5);
		for (int i = 0; i < l; i++)	 // делает отступы
			cout << " ";
		cout << p->data << endl;
		showPoint(p->left, l + 5);
	}
}

void count(Point* root, int& n)
{
	Point* p = root;
	if (p)
	{	
		if (p->left == 0 && p->right == 0)
			n++;
		count(p->right, n);
		count(p->left, n);
	}
}

Point* addFindPoint(Point* root, char* d)
{
	Point* p = root;
	Point* r = 0;
	bool ok = false;  //флаг проверки, существует ли уже в дереве
	while (p && !ok)  // пока не конец и пока не нашли
	{
		r = p;
		if (strcmp(p->data, d) == 0)
			ok = true;         //элемент уже существует                          
		else
			if (strcmp(d, p->data) < 0)
				p = p->left;    //пойти в левое поддерево
			else
				p = p->right;    //пойти в правое поддерево
	}
	if (ok)   //если нашли похожий, то добавляем
		return p;
	Point* temp = new Point(d);     //выделили память
	if (strcmp(d, r->data) < 0)
		r->left = temp;   // если d < r->data, то добавляем его в левое поддерево
	else
		r->right = temp;   // если d > r->data, то добавляем его в правое поддерево
	return temp;
}

void formFindPoint(Point* p, Point* NewRoot)
{
	if (p)
	{
		formFindPoint(p->left, NewRoot);
		addFindPoint(NewRoot, p->data);
		formFindPoint(p->right, NewRoot);
	}
}