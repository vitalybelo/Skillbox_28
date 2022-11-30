#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <thread>
#include <mutex>

struct Swimmer {
    std::string name = "Dude";  // swimmer name
    double speed = 1.5;         // speed in meters per second
    double distance = 100.0;    // calculate left of distance
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
