#pragma once
#include "Time.h"
#include <fstream>
#include <stdio.h>

void makeFile(string path);
void readFile(string path);
void del(string path);	// удалить все равные значению
void update(string path); // уменьшить на 1:30 с заданным значением
void add(string path);	// добавить К после заданного

