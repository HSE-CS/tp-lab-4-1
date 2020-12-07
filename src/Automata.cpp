#include "Automata.h"
#include <fstream>
#include <sstream>
#include <string.h>

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    menu = {"espresso", "americano", "cappuccino", "latte", "tea"};
    prices = {30, 30, 50, 50, 10};
}

Automata::Automata(std::string path) {
    std::ifstream file(path);
    std::string line;
    state = STATES::OFF;
    cash = 0;
    while (getline(file, line)) {
        int i = 0;
        std::string beverage = "";
        while (line[i] != ' ') {
            beverage += line[i];
            i++;
        }
        menu.push_back(beverage);
        std::stringstream tmp(line.substr(i+1));
        int cost = 0;
        tmp >> cost;
        prices.push_back(cost);
    }
    file.close();
    if (menu.size() < 1)
        Automata();
}

void Automata::on() {
    state = STATES::WAIT;
}

void Automata::off() {
    state = STATES::OFF;
}

void Automata::coin(unsigned int money) {
    if (state == ACCEPT || state == WAIT) {
        if (money > 0) {
            state = STATES::ACCEPT;
            cash += money;
        }
        else
            cancel();
    }
    else
        cancel();
}

void Automata::getMenu() const {
    for (int i = 0; i < menu.size(); i++) {
        std::cout << menu[i] << " " << prices[i] << std::endl;
    }
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(std::string beverage) {
    if (state == ACCEPT) {
        int index = -1;
        int n = 0;
        while ((index == -1)&&(n < menu.size())) {
            if (beverage == menu[n])
                index = n;
            n++;
        }
        if (index == -1)
            cancel();
        else {
            check(index);
        }
    }
    else
        cancel();
}

bool Automata::check(unsigned int index) {
    if ((state == ACCEPT || state == CHECK)&&(cash >= prices[index])) {
        state = STATES::CHECK;
        return true;
    }
    else
        cancel();
        return false;
}

void Automata::cancel() {
    cash = 0;
    state = STATES::WAIT;
}

void Automata::cook() {
    if (state == CHECK)
        state = STATES::COOK;
}

void Automata::finish() {
    if (state == COOK) {
        cash = 0;
        state = STATES::WAIT;
    }
}
