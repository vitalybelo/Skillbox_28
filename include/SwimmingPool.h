#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <mutex>
#include <thread>

struct Swimmer {
    std::string name;   // swimmer name
    double speed;       // speed in meters per second
    double distance = 100;
};

class SwimmingPool {

private:

    double distance;
    std::vector<Swimmer> swimmers;
    std::vector<std::thread> threads;
    std::vector<int> winners;
    std::mutex winners_access;

public:

    SwimmingPool(int distance, Swimmer* swimmers, int sizeSwimmers);

    void competition();
    void printResults();
    void run(int i);

};
