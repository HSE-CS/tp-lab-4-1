// Copyright 2020 aaa

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <string>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
private:
    double cash;
    const static int menuSize=8;
    std::string menu[menuSize] = {"hot beer", "tea", "milk", "coffee", "americano", "espresso", "hot chocolate", "hot water"};
    double prices[menuSize] = {1.0, 2.9, 3.8, 4.7, 5.6, 6.5, 7.4, 8.3};
    STATES state;
public:
    Automata() {cash = 0; state = OFF;}
    void on();
    void off();
    void coin(double);
    std::string getMenu();
    STATES getState();
    void choice(int);
    void check(int);
    void cancel();
    void cook(int);
    void finish(int);
    double getCash() const;
};


#endif //AUTOMATA_H
