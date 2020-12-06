//
// Created by Данил on 06.12.2020.
//

#ifndef TP_LAB_4_1_AUTOMATA_H
#define TP_LAB_4_1_AUTOMATA_H


#include <string>
#include <iostream>
#include <cassert>


class Automata {

private:
    int cash;

    int rangeSize = 8;

    int customerChoice = -1;

    std::string *menu;

    int *prices;

    int state;

    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK,
    };

public:
    Automata();

    void on();

    void off();

    void coin(int moneyAmount);

    void cancel();

    void choice(int customerChoiceNumber);

    int check();

    void cook();

    void finish();


};


#endif //TP_LAB_4_1_AUTOMATA_H
