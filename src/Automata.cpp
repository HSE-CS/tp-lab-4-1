// Copyright 2020 <Jiiijyyy>
#include "Automata.h"

Automata::Automata() {
    this->cash = 0;
    this->state = OFF;
    this->choices = 8;
}

void Automata::on() {
    this->state = WAIT;
    return;
}

void Automata::off() {
    this->state = OFF;
    return;
}

void Automata::coin(int money) {
    if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return;
    }
    else {
        this->state = ACCEPT;
        this->cash += money;
        return;
    }
}

int Automata::getCoin() {
    if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return -1;
    }
    else if (state == COOK) {
        std::string error = this->error_automata(1);
        return -1;
    }
    return this->cash;
}

std::string Automata::getMenu() {
    if (state == OFF) {
        std::string error = this->error_automata(0);
        return error;
    }
    else if (state == COOK) {
        std::string error = this->error_automata(1);
        return error;
    }
    else {
        std::string list_of_menu = "";
        for (size_t i = 0; i < m_size; ++i) {
            list_of_menu.append(std::to_string(i) + ". " + menu[i] + " - " + std::to_string(prices[i]) + "\n");
        }
        return list_of_menu;
    }
}

unsigned Automata::getState() {
    return this->state;
}

int Automata::getChoice() {
    if (state == OFF) {
        std::string error = this->error_automata(0);
        return -1;
    }
    else if (state == COOK) {
        std::string error = this->error_automata(1);
        return -1;
    }
    return this->choices;
}

std::string Automata::retChoice() {
    if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return error;
    }
    else if (this->state == COOK) {
        std::string error = this->error_automata(1);
        return error;
    }
    else if (this->getChoice() == 8) {
        std::string error = this->error_automata(2);
        return error;
    }
    else {
        std::string choicing = menu[this->getChoice()] + " - " "you have chosen" + "\n";
        return choicing;
    }
}

void Automata::choice(unsigned choice) {
    if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return;
    }
    else if (choice < -1 && choice > this->m_size) {
        std::string error = this->error_automata(2);
        return;
    }
    else if (this->state == COOK) {
        std::string error = this->error_automata(1);
        return;
    }
    else {
        this->choice = choice;
        this->state = CHECK;
        this->check();
        return;
    }
}

void Automata::check() {
    if (this->state == CHECK && this->cash >= this->prices[this->choices]) {
        this->cash -= this->prices[this->choices];
        this->state = COOK;
        this->cook();
        return;
    }
    else if (this->state == CHECK && CHECK && this->cash < this->prices[this->choices]) {
        std::string error = this->error_automata(3);
        this->state = ACCEPT;
        this->choices = 8;
        return;
    }
    else if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return;
    }
    else if (this->state == ACCEPT || this->state == WAIT) {
        std::string error = this->error_automata(2);
        return;
    }
    else if (this->state == COOK) {
        std::string error = this->error_automata(1);
        return;
    }
}

void Automata::cancel() {
    if (this->state == ACCEPT || this->state == CHECK) {
        this->state = WAIT;
        this->choices = 8;
        this->cash = 0;
    }
    else if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return;
    }
    else if (this->state == COOK) {
        std::string error = this->error_automata(1);
        return;
    }
    return;
}

void Automata::cook() {
    if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return;
    }
    else if (this->state == ACCEPT || this->state == WAIT || this->state == CHECK) {
        std::string error = this->error_automata(2);
        return;
    }
    else {
        time_t start = clock();
        while (clock() - start < 5) {
        }
        finish();
    }
}

void Automata::finish() {
    if (this->state == OFF) {
        std::string error = this->error_automata(0);
        return;
    }
    else if (this->state == ACCEPT || this->state == WAIT || this->state == CHECK) {
        std::string error = this->error_automata(2);
        return;
    }
    else if (this->state == COOK) {
        this->cash = 0;
        this->state = WAIT;
        this->choices = 8;
        return;
    }
}

std::string Automata::error_automata(unsigned error_type) { 
    if (error_type == 0) {
        std::string error = "Sorry, but you need to enable automata!\n";
        return error;
    }
    else if (error_type == 1) {
        std::string error = "Please, waiting! Automata is bisy!\n";
        return error;
    }
    else if (error_type == 2) {
        std::string error = "You haven't made a choice yet!\n";
        return error;
    }
    else if (error_type == 3) {
        std::string error = "Not enough money, add it and make a choice again!\n";
        return error;
    }
}