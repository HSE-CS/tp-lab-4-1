//
// Created by Данил on 06.12.2020.
//

#include "../include/Automata.h"

int checkState(int state, int expected) {
    // std::cout << state << ' ' << expected << '\n';
    if (state == expected)
        return 1;
    else {
        // std::cout << "Incorrect state. Impossible to change it to this" << '\n';
        return 0;
    }
}

Automata::Automata() {
    this->cash = 0;
    this->menu = new std::string[this->rangeSize]{
            "Pivo Baltika Bezalkogol'noye",
            "Water",
            "Cold water",
            "Warm water",
            "Hot water",
            "Awesome water",
            "Orange juice",
            "K.O.M.P.O.T.",
    };
    this->prices = new int[this->rangeSize]{
            49,
            10,
            12,
            14,
            16,
            199,
            79,
            19,
    };
    this->state = OFF;
}

void Automata::on() {
    if (checkState(this->state, OFF))
        this->state = WAIT;
}

void Automata::off() {
    if (checkState(this->state, WAIT))
        this->state = OFF;
}

void Automata::coin(int moneyAmount) {
    if (checkState(this->state, ACCEPT) or
        checkState(this->state, WAIT)) {
        this->state = ACCEPT;
        this->cash += moneyAmount;
        std::cout << "Added " << moneyAmount << " bucks!\n";
    }
}

void Automata::cancel() {
    if (checkState(this->state, ACCEPT) || checkState(this->state, CHECK)) {
        this->state = WAIT;
        this->cash = 0;
    }
}

void Automata::choice(int customerChoiceNumber) {
    if (checkState(this->state, ACCEPT)) {
        assert(0 <= customerChoiceNumber <= this->rangeSize);
        this->state = CHECK;
        this->customerChoice = customerChoiceNumber;
        std::cout << "You choose " << this->menu[this->customerChoice] << "!\n";
    }
}

int Automata::check() {
    if (checkState(this->state, CHECK)) {
        if (this->cash >= this->prices[this->customerChoice]) {
            return 1;
        }
        std::cout << "Not enough money!\n";
    }
    return 0;
}

void Automata::cook() {
    if (checkState(this->state, CHECK)) {
        this->state = COOK;
        this->cash -= this->prices[this->customerChoice];
        std::cout << "Your " << this->menu[this->customerChoice] << " is ready!\n";
        std::cout << "Please, take back your " << this->cash << " bucks!\n";
    }
}

void Automata::finish() {
    if (checkState(this->state, COOK)) {
        this->state = WAIT;
        this->customerChoice = -1;
    }
}
