#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

struct Plain {
    std::string name = "Diesel";    // имя паровозика
    int flightTime = 5;             // время в пути
    int parkingTime = 5;            // время стоянки
};

class PlainPuzzle {

private:
    int routeNumbers = 1;
    std::vector<Plain> plains;
    std::vector<std::thread> threads;
    std::mutex airport_access;

public:
    explicit PlainPuzzle(Plain* plains, int plainNumbers);

    void start(int routeTimes);
    void run(int index);

};
