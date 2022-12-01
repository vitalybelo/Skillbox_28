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
        std::this_thread::sleep_for(std::chrono::seconds(i + 1)); // �������� �����������
    }
    for (auto &t : threads) t.join();
    threads.clear();
}

void PlainPuzzle::run(int index) {

    if (index < 0 || index > plains.size()) return;
    Plain plain = plains.at(index);

    int i = routeNumbers;
    while (i-- > 0) {
        // ����� � �������� ����������
        std::cout << (index + 1) << ". " << plain.name << " :: ������� �� �������� ����� ";
        std::cout << "(����� ������: " << plain.flightTime << " :: ����� �������: " << plain.parkingTime << ")\n";
        std::this_thread::sleep_for(std::chrono::seconds(plain.flightTime));

        // �������� ���������� ������� � ��������� ����������
        std::cout << "\n\t" << plain.name << " :: ���� ������������� �� �������\n";

        // ���������� �� ������� ��������, �������, ��������� � ����� �� ����
        airport_access.lock();
        std::cout << "\t" << plain.name << " :: ������������� ��������, �������� ������� � ��������� �����\n";
        std::cout << "\t\t" << plain.name << " :: ���������, ������� ���������� �� ����� " << plain.parkingTime
                  << "���.\n";
        std::this_thread::sleep_for(std::chrono::seconds(plain.parkingTime));
        std::cout << "\t\t\t" << plain.name << " :: ���������� �� ����� ��������, ";
        std::cout << " ������������ �� ����, ����� ������: " << plain.parkingTime << "\n\n";
        airport_access.unlock();

        // ����������� �������� �� ����
        std::this_thread::sleep_for(std::chrono::seconds(plain.flightTime));
        airport_access.lock();
        std::cout << (index + 1) << ". " << plain.name << " :: �������� �������, �������� �� ����";
        std::cout << " :: ����� ����������: " << plain.parkingTime << std::endl;
        airport_access.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(plain.parkingTime));
    }
    std::cout << (index + 1) << ". " << plain.name << " :: ������ ���������\n";
}


