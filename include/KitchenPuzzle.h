#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

struct Dish {
    std::string name = "Pizza";
    int time = 10;
    int id = 0;
    bool delivered = false;
};

class KitchenPuzzle {

private:
    int orderCount = 0;
    int deliveryCount = 0;
    std::vector<Dish> order;
    std::mutex kitchen_access;
    std::mutex delivery_access;

public:

    KitchenPuzzle();

    void add(Dish dish);
    void cook(int index);
    void delivery(int index);

    int getDeliveryCount() const;
    const std::vector<Dish> &getOrder() const;

};
