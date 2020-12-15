//
// Created by Kostin Andrej on 2020.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>



using namespace std;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata{
private:
    long cash;
    int lastTransaction;
    string menu[9] = {"Espresso", "Americano", "Cappuccino", "Latte", "Macchiato", "Latte Macchiato", "Ice coffee","Milk","Glasse"};
    int prices[9] = {35, 40, 40, 50, 50, 80, 50,20, 70};
    STATES state;
public:
    Automata(){
        state = OFF;
        cash = 0;
        lastTransaction = 0;
    };
    void on();
    void off();
    void coin(int money);
    string *getMenu();
    STATES getState();
    void choice(int number);
    void check(int number);
    void cancel();
    void cook();
    void finish();

    long getCash(); //для тестов
};

#endif //TASK1_AUTOMATA_H