//  Copyright 2020 Nikita Naumov
#ifndef INCLUDE_AUTOMATA_H
#define INCLUDE_AUTOMATA_H

#include <iostream>
#include <algorithm>
#include <string>
#include <typeinfo>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>

const int menuSize = 5;

enum STATES {
    offline = 0,
    waiting = 1,
    acceptingMoney = 2,
    cooking = 3
};

class Automata {
 private:
    unsigned cash;
    std::string menu[menuSize] = { "Latte", "Milk", "Black Tea", "Karkade", "Espresso"};
    int prices[menuSize] = {30, 25, 15, 20, 25};
    int codes[menuSize] = {0};
    int state;
    void finish();

 public:
    Automata();
    void on();
    void off();
    void coin(int m = 0);
    void cancel();
    std::string getMenu();
    int getState();
    void choice(int option = 0);
    bool check(int);
    void cook(int);

};

#endif  //  INCLUDE_AUTOMATA_H