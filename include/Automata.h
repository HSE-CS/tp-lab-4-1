#ifndef  AUTOMATA_H
#define AUTOMATA_H

#include<iostream>
#include <time.h>
#include<string>
#include<map>

enum STATES {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
private:
    int cash;
    std::map<std::string, int> menu;
    std::string product;
    STATES state;
public:
    Automata() {
        state = OFF;
        product = "";
        cash = 0;
    }
    void on();
    void off();
    void coin(int money);
    std::map<std::string, int> getMenu();
    STATES getState();
    void choice(const std::string);
    void check();
    void cancel();
    void cook();
    void finish();
};

#endif