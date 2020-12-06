#include "Automata.h"
const std::map<std::string, int> MENU = {
    {"Coffee", 50}, 
    {"Milk", 35}, 
    {"Water", 20}, 
    {"Lemonade", 25}, 
    {"Juice", 30} };

void Automata::on() { 
    state = WAIT;
    return;
}

void Automata::off() { 
    state = OFF;
    return;
}

void Automata::coin(int money) {
    if (state == OFF)  return;
    state = ACCEPT;
    cash += money;
    return;
}

std::map<std::string, int> Automata::getMenu() { 
    return menu;
}

STATES Automata::getState() { 
    return state;
}

void Automata::choice(const std::string chosen) {
    if (state == ACCEPT) {
        product = chosen;
    }
}

void Automata::check() {
    if (state == ACCEPT) {
        if (cash >= menu[product]) {
            state = CHECK;
        }
        else
            state = ACCEPT;
    }
}
void Automata::cancel() {
    state = WAIT;
    cash = 0;
    product = "";
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        product = "";
        cash = 0;
    }
}