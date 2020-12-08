// Copyright 2020 aaa
#include "Automata.h"

std::string Automata::getMenu() {
    std::string table;
    for (int i = 0; i < menuSize; ++i) {
        table += std::to_string(i+1) + ".\t" + menu[i] + "\t" + std::to_string(prices[i]) + " coins\n";
    }
    return table;
}

void Automata::coin(double amount) {
    state = STATES::ACCEPT;
    cash += amount;
    std::cout << "Coins accepted" << std::endl;
}

void Automata::off() {
    state = OFF;
    std::cout << "Automata turned off" << std::endl;
}

void Automata::on() {
    state = WAIT;
    std::cout << "Insert coins" << std::endl;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int beverage) {
    state = CHECK;
    check(beverage);
}

void Automata::check(int number) {
    if (cash >= prices[number]) {
        cook(number);
        return;
    }
    std::cout << "Not enough coins" << std::endl;
    state = ACCEPT;
}

void Automata::cancel() {
    state = WAIT;
    cash = 0;
    std::cout << "Canceled" << std::endl;
}

void Automata::cook(int beverage) {
    state = COOK;
    std::cout << "Beverage is cooking" << std::endl;
    finish(beverage);
}

void Automata::finish(int beverage) {
    std::cout << "Get rest of money: " << cash - prices[beverage] << std::endl;
    cash = 0;
    state = WAIT;
}

double Automata::getCash(){
    return cash;
}