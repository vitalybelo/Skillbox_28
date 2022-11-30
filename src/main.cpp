#include <iostream>
#include "use_lib.h"
#include "SwimmingPool.h"
using namespace std;

#define DISTANCE 25
#define SWIMMER_SIZE 6

int main() {
    setlocaleRus();

    Swimmer swimmers[] {{"Michael Phelps",    1.90},
                        {"Alexey Popov",      1.88},
                        {"Kaleb Dressel",     1.89},
                        {"Ryan Lohte",        1.87},
                        {"Jan Torp",          1.88},
                        {"Vladimir Salnikov", 1.88}};

    SwimmingPool pool(DISTANCE, swimmers,SWIMMER_SIZE);

    pool.competition();
    pool.printResults();

    return 0;
}
