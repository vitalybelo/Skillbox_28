#include "PlainPuzzle.h"

PlainPuzzle::PlainPuzzle(Plain* plains, int plainNumbers)
{
    for (int i = 0; i < plainNumbers; i++) {
        this->plains.push_back(plains[i]);
    }
}

void PlainPuzzle::start(int routeTimes) {
    routeNumbers = routeTimes;
    for(int i = 0; i < plains.size(); i++) {
        threads.emplace_back(&PlainPuzzle::run, this, i);
        std::this_thread::sleep_for(std::chrono::seconds(i + 1)); // задержка отправления
    }
    for (auto &t : threads) t.join();
    threads.clear();
}

void PlainPuzzle::run(int index) {

    if (index < 0 || index > plains.size()) return;
    Plain plain = plains.at(index);

    int i = routeNumbers;
    while (i-- > 0) {
        // Вылет в аэропорт назначения
        std::cout << (index + 1) << ". " << plain.name << " :: вылетел по маршруту ЦЕНТР ";
        std::cout << "(время полета: " << plain.flightTime << " :: время стоянки: " << plain.parkingTime << ")\n";
        std::this_thread::sleep_for(std::chrono::seconds(plain.flightTime));

        // Ожидание разрешения посадки в аэропорту назначения
        std::cout << "\n\t" << plain.name << " :: ждет подтверждения на посадку\n";

        // Разрешение на посадку получено, посадка, разгрузка и вылет на базу
        airport_access.lock();
        std::cout << "\t" << plain.name << " :: подтверждение получено, совершил посадку в аэропорту ЦЕНТР\n";
        std::cout << "\t\t" << plain.name << " :: разгрузка, ожидает разрешения на взлет " << plain.parkingTime
                  << "сек.\n";
        std::this_thread::sleep_for(std::chrono::seconds(plain.parkingTime));
        std::cout << "\t\t\t" << plain.name << " :: разрешение на взлет получено, ";
        std::cout << " возвращается на базу, время полета: " << plain.parkingTime << "\n\n";
        airport_access.unlock();

        // Возвращение самолета на базу
        std::this_thread::sleep_for(std::chrono::seconds(plain.flightTime));
        airport_access.lock();
        std::cout << (index + 1) << ". " << plain.name << " :: совершил посадку, вернулся на базу";
        std::cout << " :: время готовности: " << plain.parkingTime << std::endl;
        airport_access.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(plain.parkingTime));
    }
    std::cout << (index + 1) << ". " << plain.name << " :: миссия завершена\n";
}


