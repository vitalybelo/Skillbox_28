#include "use_lib.h"
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include "windows.h"

std::string getCommand() {
    std::string command;
    getline(std::cin,command);
    for (char & i : command) {
        i = (char) tolower(i);
    }
    return command;
}

void clearStdin () {
    std::cin.clear();
    fflush(stdin);
}
void setlocaleRus () {
    setlocale(LC_ALL, "Russian");
}

void setlocale1251 () {
    setlocaleRus();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int irandom_next (int from, int to) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(from, to);

    return dist(gen);
    //return (int)gen();
}

tm get_TMDate (std::string date_string) {
    time_t t = time(nullptr);
    tm now = *localtime(&t);
    replace(date_string.begin(), date_string.end(), '/', ' ');
    if (std::istringstream(date_string) >> now.tm_mday >> now.tm_mon >> now.tm_year) {
        now.tm_mon -= 1;
        now.tm_year -= 1900;
    }
    return now;
}

