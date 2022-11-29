#pragma once
#include <iostream>

std::string getCommand();

void clearStdin();
void setlocaleRus();
void setlocale1251();

int irandom_next(int from, int to);

tm get_TMDate(std::string date_string);

