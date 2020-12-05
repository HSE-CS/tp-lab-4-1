
// Copyright 2020 ArtyomLavrov

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

class Automata {

  private:
    long cash;
    int lastactivity;
    string menu[5] = { "Apple juice", "Cocoa", "Soda", "Coca-cola", "Coffee" };
    int prices[5] = { 40, 45, 50, 55, 60 };
    STATES state;

  public:
    Automata() {
        state = OFF;
        cash = 0;
        lastactivity = 0;
    };

    void on();
    void off();
    void cash(int money);
    string* getMenu();
    STATES getState();
    void choice(int number);
    void check(int number);
    void cancel();
    void cook();
    void finish();
    long getCash();
};

#endif //TASK1_AUTOMATA_H