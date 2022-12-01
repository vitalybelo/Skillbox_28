#include <iostream>
#include <thread>
#include <random>
#include "KitchenPuzzle.h"
using namespace std;

/**
 * Задание №3
 * Кухня имеет 5 блюд доступных для заказа в службе доставки еды
 * Заказы поступают с частотой распределения dist_wait, от 2 до 4 секунд (можно изменить)
 * Время приготовления каждого заказа берем из распределения dist_time, от 5 до 9 секунд на заказ
 * Время необходимое чтобы курьер забрал готовый заказ с кухни равен времени приготовления заказа
 * Запускаем программу и ждем пока курьер не заберет 10 готовых заказов с кухни
 */
void solution_3() {

    std::cout << "\n\nЗадание №3 --------------- >>\n\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_dish(0, 4); // количество блюд доступных для заказа
    uniform_int_distribution<> dist_time(5, 9); // диапазон времени приготовления заказа
    uniform_int_distribution<> dist_wait(2, 4); // частота поступления новых заказов

    Dish dishes[] {{"Pizza", dist_time(gen)},
                   {"Sushi", dist_time(gen)},
                   {"Salad", dist_time(gen)},
                   {"Steak", dist_time(gen)},
                   {"Soup ", dist_time(gen)}};

    KitchenPuzzle kitchen;

    do {
        // получаем новый заказ, запускаем в обработку
        kitchen.add(dishes[dist_dish(gen)]);

        // ожидание поступления нового заказа
        this_thread::sleep_for(chrono::seconds(dist_wait(gen)));

    } while (kitchen.getDeliveryCount() < 10);

    cout << "\n\nСписок доставленных заказов:\n";
    for (const Dish& dish : kitchen.getOrder()) {
        if (!dish.delivered) break;
        cout << "Заказ № " << dish.id + 1 << " :: " << dish.name << endl;
    }

}
