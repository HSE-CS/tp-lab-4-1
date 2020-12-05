#include "Automata.h"
#include <iostream>


Automata::Automata() {
    cash = 0;
    state = OFF;
    ready_for_cooking = false;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
    }
}

void Automata::coin(int money) {
    if (state == ACCEPT) {
        cash += money;
    }
    if (state == WAIT) {
        cash += money;
        state = ACCEPT;
    }
}

int Automata::getBalance() const {
    return cash;
}

std::map<std::string, int> Automata::getMenu() const {
    return drink_price;
}

std::string Automata::getState() const {
    switch(state) {
        case OFF:
            return "OFF";
        case WAIT:
            return "WAIT";
        case ACCEPT:
            return "ACCEPT";
        case CHECK:
            return "CHECK";
        case COOK:
            return "COOK";
    }
}

void Automata::choice(const std::string & drink) {
    if (state == ACCEPT) {
        state = CHECK;
        selected_drink = drink;
    }
}

void Automata::check() {
    if (state == CHECK && !ready_for_cooking) {
        if (drink_price[selected_drink] > cash) {
            state = ACCEPT;
        } else {
            ready_for_cooking = true;
        }
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        ready_for_cooking = false;
        state = WAIT;
    }
}

void Automata::cook() {
    if (state == CHECK && ready_for_cooking) {
        state = COOK;
        std::cout << "Cooking " << selected_drink << "...\n";
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        std::cout << selected_drink << " is ready\n";
        cash = 0;
        ready_for_cooking = false;
    }
}

