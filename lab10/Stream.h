#pragma once
#include "Time.h"
#include <fstream>
#include <stdio.h>

void makeFile(string path);
void readFile(string path);
void del(string path);	// ������� ��� ������ ��������
void update(string path); // ��������� �� 1:30 � �������� ���������
void add(string path);	// �������� � ����� ���������

