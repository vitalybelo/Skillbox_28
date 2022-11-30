#include "SwimmingPool.h"

SwimmingPool::SwimmingPool(int distance, Swimmer *swimmers, int sizeSwimmers)
{
    this->distance = distance;
    for (int i = 0; i < sizeSwimmers; i++) {
        swimmers[i].distance = distance;
        this->swimmers.push_back(swimmers[i]);
    }
}

void SwimmingPool::competition()
{
    for (int i = 0; i < swimmers.size(); i++) {
        threads.emplace_back(&SwimmingPool::run, this, i);
    }
    for (auto &t : threads) t.join();
    threads.clear();
}

void SwimmingPool::run(int i)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,100);
    std::uniform_real_distribution<> dist_fault(0.1,0.5);

    while (swimmers[i].distance > 0) {

        // wait for virtual second goes
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // decrease distance for swimmer
        swimmers[i].distance -= swimmers[i].speed;

        // per suite random swimmer's faults
        if (dist(gen) > 80) {
            swimmers[i].distance += dist_fault(gen); // random technical fault in swimming occurred
        }

        // display left distance
        winners_access.lock();
        if (swimmers[i].distance > 0) {
            std::cout << swimmers[i].name << " ---> " << swimmers[i].distance << std::endl;
        }
        winners_access.unlock();
    }
    // register finished swimmer
    winners_access.lock();
    winners.push_back(i);
    winners_access.unlock();
}

void SwimmingPool::printResults()
{
    std::cout << std::endl << "Results of competition on distance " << distance << "m :\n";
    for (int i = 0; i < winners.size(); i++) {
        std::cout << "Place: " << (i + 1) << " :: " << swimmers[winners[i]].name << std::endl;
    }
}







