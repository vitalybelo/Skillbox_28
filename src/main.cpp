#include <random>
#include "use_lib.h"
#include "PlainPuzzle.h"
#include "solution.h"
using namespace std;

#define PLAIN_FLEET 3

int main() {
    setlocaleRus();

    /**
     * В начале инициализируются 6 пловцов, с именами и скоростью
     * Далее конструктор инициализирует пул участников для соревнования
     * Дистанция соревнования установлена по умолчанию 25м, меньше ждать
     * Скорости пловцов установлены практически максимально возможные
     * В реализацию внесена случайная возможность допуска ошибки пловца
     * При ошибке случайное число откатывает пловца назад до полуметра
     * таким образом можно реализовать гарантировано разный финиш в
     * каждом заплыве. Запустите и болейте за спорт на здоровье
     */
    //solution_1();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_flight(5, 10);
    uniform_int_distribution<> dist_parking(3,6);

    Plain trains[] {{"A (Airbus 320)", dist_flight(gen), dist_parking(gen)},
                    {"B (Boeing 767)", dist_flight(gen), dist_parking(gen)},
                    {"C (Boeing 747)", dist_flight(gen), dist_parking(gen)}};

    PlainPuzzle fleet(trains, PLAIN_FLEET);

    fleet.start(1);


    return 0;
}
