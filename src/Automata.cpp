
// Copyright 2020 ArtyomLavrov

#include <iostream>
#include <cmath>
#include <iomanip>
#include <unistd.h>
#include <cstring>
#include "Automata.h"

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off() {
    state = OFF;
}

void Automata::cash(int money) {
    if (state == WAIT) {
        lastactivity += money;
        state = ACCEPT;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        lastactivity = 0;
        state = WAIT;
    }
}

string* Automata::getMenu() {
    auto* menu = new string[5];
    for (int i = 0; i < 5; ++i) {
        menu[i] += to_string(i + 1) += ") ";
        menu[i] += this->menu[i] += " - ";
        menu[i] += to_string(this->prices[i]);
    }
    return menu;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int number) {
    if (state == ACCEPT) {
        state = CHECK;
        this->check(number - 1);
    }
}

void Automata::check(int number) {
    if (lastactivity >= prices[number]) {
        this->cook();
        cash += prices[number];
        lastactivity = 0; //сдача
    }  else {
        cancel();
            }
}

void Automata::cook() {
    state = COOK;
    this->finish();
}

void Automata::finish() {
    state = WAIT;
}

long Automata::getCash() {
    return cash;
}
