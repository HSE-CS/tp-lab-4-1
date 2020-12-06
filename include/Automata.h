// Copyright 1(6).12.2020 BD 
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
    FINISH
};

class Automata {
private:
    int cash; /*, change*/
    string menu[3] = { "Coffee", "Black tea", "Green tea" };
    int  prices[3] = { 25, 15, 10 };
    size_t msize = 3;
    unsigned state;
public:
    Automata();
    void on();
    void off();
    void coin(int);
    string getMenu();
    unsigned getState();
    void choice(size_t);
    void check(size_t);
    void cancel();
    void cook(size_t);
    void finish();
    int getCoin();
    int getChange();
};

#endif // INCLUDE_AUTOMATA_H_