//Copyright 2020 FOM
#include <iostream>
#include "Automata.h"

Automata::Automata() {
    state = STATES::OFF;
    cash = 0;
}

void Automata::on() {
    if (state == STATES::OFF)
        state = STATES::WAIT;
}

void Automata::off() {
    if (state == STATES::WAIT)
        state = STATES::OFF;
}

bool Automata::coin(int cash) {
    if ((state == STATES::WAIT) && (state == STATES::ACCEPT)) {
        state = STATES::ACCEPT;
        cash += cash;
        return true;
    }
    return false;
}

std::string  Automata::getMenu() {
    if (state == STATES::OFF) {
        std::string menu{ "" };
        return menu;
    }
    std::string menu = "";
    for (int i = 0; i < SIZE; i++) {
        menu += std::to_string(i + 1) + " " + arr_menu[i] + " " + std::to_string(arr_prices[i]) + "\n";
    }
    return menu;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int num) {
    if (state == ACCEPT) {
        state = CHECK;
        check(num - 1);
    }
}

void Automata::check(int number)
{
    if (state == CHECK)
        if (cash >= arr_prices[number - 1])
            cook();
    return;
}

void Automata::cancel()
{
    if (state == OFF)
        return;
    state = WAIT;
    cash = 0;
}

void Automata::cook()
{
    state = COOK;
    finish();
}

void Automata::finish()
{
    state = WAIT;
}
