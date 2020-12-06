// Copyright 2020 GHA Automata Team

#include "Automata.h"

Automata::Automata() {
    cash = 0.0;
    state = STATE::OFF;
}

void Automata::on() {
    if (state == STATE::OFF) {
        state = STATE::WAIT;
    }
}

double Automata::off() {
    if (state == STATE::WAIT) {
        state = STATE::OFF;
        double _temp = cash;
        cash = 0.0;
        return _temp;
    }
    return 0.0;
}

void Automata::coin(double _money) {
    if (state == STATE::ACCEPT || state == STATE::WAIT) {
        state = STATE::ACCEPT;
        cash += _money;
    }
}

std::vector<std::string> Automata::getMenu() {
    if (state == STATE::WAIT || state == STATE::ACCEPT) {
        return menu;
    } else {
        std::vector<std::string> _temp;
        return _temp;
    }
}

std::map<std::string, double> Automata::getPriece() {
    if (state == STATE::WAIT || state == STATE::ACCEPT) {
        return prices;
    } else {
        std::map<std::string, double> _temp;
        return _temp;
    }
}

std::string Automata::getState() {
    switch (state) {
        case 0:
            return "off";
            break;
        case 1:
            return "wait";
            break;
        case 2:
            return "accept";
            break;
        case 3:
            return "check";
            break;
        case 4:
            return "cook";
            break;
        default:
            return "0";
            break;
    }
}

void Automata::cancel() {
    if (state == STATE::ACCEPT || state == STATE::CHECK) {
        state = STATE::WAIT;
    }
}

void Automata::choice(std::string _drink) {
    if (state != STATE::ACCEPT) {
        return;
    }
    std::map<std::string, double> _prices = getPriece();
    std::map<std::string, double>:: iterator it;
    it = _prices.find(_drink);
    state = STATE::CHECK;
    if (check(it->second)) {
        cash -= it->second;
        cook();
    } else {
        std::cout << "Amount of money is small" << std::endl;
        cancel();
    }
}

bool Automata::check(double  _price) {
    if (cash >= _price) {
        return true;
    } else {
        return false;
    }
}

void Automata::cook() {
    if (state == STATE::CHECK) {
        state = STATE::COOK;
        finish();
    }
}

void Automata::finish() {
    if (state == STATE::COOK) {
        std::cout << "Drink is ready\n You could get your remainder - to tap getRemainder" << std::endl;
        state = STATE::WAIT;
        remainder = cash;
    }
}

double Automata::getReminder() {
    if (state == STATE::WAIT || state == STATE::ACCEPT) {
        return cash;
    }
}