// Copyright 2020 JGMax

#ifndef LAB_4_AUTOMATA_H
#define LAB_4_AUTOMATA_H

#include "Menu.h"
#include <fstream>
#include <iostream>

enum States {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
    std::string adminPassword = "1234";
    std::string rememberedItem;
    double cash;
    double inputCash = 0;
    Menu menu;
    Menu incorrectMenu;
    States state;
    std::ostream* outputStream;
    bool check(std::string);
    void cook(std::string);
    double getChange(std::string);
    void finish();
 public:
    Automata() {
        outputStream = &(std::cout);
        state = OFF;
        cash = 0;
    }
    Automata(std::ostream* oStream) {
        outputStream = oStream;
        state = OFF;
        cash = 0;
    }

    Automata(std::ostream* oStream, std::string adminPassword, const Menu& menu) {
        if (adminPassword == this->adminPassword)
            this->menu = menu;
        outputStream = oStream;
        state = OFF;
        cash = 0;
    }

    Automata(std::ostream* oStream, std::string adminPassword, const double cash) {
        if (adminPassword == this->adminPassword)
            this->cash = cash;
        else
            this->cash = 0;
        outputStream = oStream;
        state = OFF;
    }

    Automata(std::ostream* oStream, std::string adminPassword, const Menu& menu,  const double cash) {
        if (adminPassword == this->adminPassword) {
            this->cash = cash;
            this->menu = menu;
        } else {
            this->cash = 0;
        }
        outputStream = oStream;
        state = OFF;
    }

    bool changeAdminPassword(std::string adminPassword, std::string newAdminPassword);
    Menu getMenu(bool show = true);
    Menu& getMenu(std::string adminPassword);

    void on();
    void off();
    void coin(double cash);
    double getChange();
    void cook();
    void choice(std::string item);
    States getState();
    double cancel();

    double getCash(std::string adminPassword);
};

#endif //LAB_4_AUTOMATA_H
