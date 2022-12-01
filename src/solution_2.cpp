#include <random>
#include "use_lib.h"
#include "PlainPuzzle.h"
#include "solution.h"
using namespace std;

#define PLAIN_FLEET 3

/**
 * Внимание: парк транспортных средств заправлен и готов к работе
 * Задание №2 немного модифицировано но не упрощено, прошу простить и понять ))
 * Вместо паровозиков в задании участвуют самолеты, взлетающие со своих баз дислокации
 * Каждый самолет имеет время полета и время стоянки в аэропорту назначения - аэропорт ЦЕНТР
 * Подлетая к аэропорту ЦЕНТР, командир корабля запрашивает разрешение на посадку, если полоса
 * свободна, разрешение выдается, самолет совершает посадку, выполняет разгрузку, просит разрешение
 * на взлет и улетает на базу. В это время, другие самолеты, ожидают разрешения на посадку в порядке
 * живой очереди, получают, совершают посадку, разгружаются и также вылетают назад на свои базы.
 * Вы можете указать единственный параметр n_routes для задания - сколько рейсов каждый самолёт
 * должен совершить в ЦЕНТР и вернуться назад. По умолчанию = 1. Пристегнитесь и вперед.
 */
void solution_2(int n_routes) {

    std::cout << "\n\nЗадание №2 --------------- >>\n\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_flight(5, 10);
    uniform_int_distribution<> dist_parking(3,6);

    Plain trains[] {{"A (Airbus 320)", dist_flight(gen), dist_parking(gen)},
                    {"B (Boeing 767)", dist_flight(gen), dist_parking(gen)},
                    {"C (Boeing 747)", dist_flight(gen), dist_parking(gen)},
                    {"D (Airbus 440)", dist_flight(gen), dist_parking(gen)},
                    {"E (Dusty's 88)", dist_flight(gen), dist_parking(gen)}};

    PlainPuzzle fleet(trains, PLAIN_FLEET);

    fleet.start(n_routes);
}
