#include "KitchenPuzzle.h"

KitchenPuzzle::KitchenPuzzle() = default;


void KitchenPuzzle::add(Dish dish)
{
    dish.id = orderCount++;
    order.push_back(dish);

    std::cout << "Принят заказ №" << dish.id + 1 << " :: ";
    std::cout << dish.name << " :: время приготовления = " << dish.time << std::endl;

    std::thread cooking(&KitchenPuzzle::cook, this, dish.id);
    cooking.detach();
}

void KitchenPuzzle::cook(int index)
{
    kitchen_access.lock();
    {
        std::cout << "\t--> Кухня взяла в работу заказ №" << order.at(index).id + 1;
        std::cout << " :: " << order.at(index).name;
        std::cout << " :: будет готов через " << order.at(index).time << " сек.\n";
        std::this_thread::sleep_for(std::chrono::seconds(order.at(index).time));
        std::cout << "\t\t--> Заказ №" << order.at(index).id + 1 << " :: готов --> ожидает курьера -->\n";
    }
    kitchen_access.unlock();
    std::thread courier(&KitchenPuzzle::delivery, this, index);
    courier.detach();
}

void KitchenPuzzle::delivery(int index)
{
    std::lock_guard<std::mutex> lg(delivery_access);
    std::this_thread::sleep_for(std::chrono::seconds(order.at(index).time));
    std::cout << "\n\t\t**** ЗАКАЗ №" << order.at(index).id + 1 << " ВЫДАН КУРЬЕРУ НА ДОСТАВКУ ****\n\n";
    order.at(index).delivered = true;
    deliveryCount++;
}

int KitchenPuzzle::getDeliveryCount() const {
    return deliveryCount;
}

const std::vector<Dish> &KitchenPuzzle::getOrder() const {
    return order;
}


