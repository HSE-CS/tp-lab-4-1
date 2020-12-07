// Copyright 2020 Anastasiya Rogozyan

#include <iostream>
#include "../include/Automata.h"

void Automata::on() {
    state = WAIT;
}

void Automata::off() {
    state = OFF;
}

bool Automata::coin(double amount) {
    if (state == WAIT) {
        cash += amount;
        state = ACCEPT;
        return true;
    }
    return false;
}

std::string Automata::getMenu() {
    std::string res;
    for (int i = 0; i < static_cast<int>(sizeof(menu)/sizeof(*menu)); i++)
        res += menu[i] + ": " + std::to_string(prices[i]) + "\n";
    return res;
}

int Automata::getState() {
    return state;
}

bool Automata::choice(int position) {
    if (state == ACCEPT) {
        if (position > 0
            && position < static_cast<int>(sizeof(menu)/sizeof(*menu))) {
            state = CHECK;
            chosenPosition = position - 1;
            return true;
        }
        return false;
    }
    return true;
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash < prices[chosenPosition]) {
            state = WAIT;
            return false;
        }
        return true;
    }
    return false;
}

bool Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        return true;
    }
    return false;
}

bool Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        return true;
    }
    return false;
}

bool Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        return true;
    }
    return false;
}
