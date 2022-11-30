#include "SwimmingPool.h"
using namespace std;

#define DISTANCE 25
#define SWIMMER_SIZE 6

/**
 * В начале инициализируются 6 пловцов, с именами и скоростью
 * Далее конструктор инициализирует пул участников для соревнования
 * Дистанция соревнования установлена по умолчанию 25м (меньше ждать)
 * Скорости пловцов установлены практически максимально возможные
 * В реализацию внесена случайная возможность допуска ошибки пловца
 * При ошибке случайное число откатывает пловца назад до полуметра
 * таким образом можно реализовать гарантировано разный финиш в
 * каждом заплыве. Запустите и болейте за спорт на здоровье
 */
void solution_1() {

    Swimmer swimmers[] {{"Michael Phelps",    1.90},
                        {"Alexey Popov",      1.88},
                        {"Kaleb Dressel",     1.89},
                        {"Ryan Lohte",        1.87},
                        {"Jan Torp",          1.88},
                        {"Vladimir Salnikov", 1.88}};

    SwimmingPool pool(DISTANCE, swimmers,SWIMMER_SIZE);

    pool.competition();
    pool.printResults();

}
