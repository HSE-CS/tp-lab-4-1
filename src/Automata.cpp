//
// Created by vladimir on 07.12.2020.
//

#include "Automata.h"


Automata::Automata() {
    this->state = states::OFF;
    this->cash = 0;
}

void Automata::off() {
    if (this->state == states::WAIT) this->state = states::OFF;
}

void Automata::on() {
    if (this->state == states::OFF) this->state = states::WAIT;
}

void Automata::coin(int money) {
    if (this->state == states::WAIT) this->state = states::ACCEPT;
    this->cash += money;
}

void Automata::choice(const string& name) {
    if (this->state == states::ACCEPT || this->state == states::WAIT){
        this->state = states::CHECK;
        check(name);
    }
}

void Automata::check(const string& product_name) {
    if (this->state == states::CHECK && this->cash >= menu.find(product_name)->second){
        this->cash -= menu.find(product_name)->second;
        cook(product_name);
    } else {
        cancel();
    }

}

void Automata::cook(const string& name) {
    if (this->state == states::CHECK){
        this->state = states::COOK;
        finish();
    }
}

void Automata::cancel() {
    if (this->state == states::ACCEPT) this->cash = 0;
    this->state = states::WAIT;
}

void Automata::finish() {
    if (this->state == states::COOK){
        this->state = states::WAIT;
    }
}

states Automata::getState() {
    return this->state;
}

map<string, int> Automata::getMenu() {
    return this->menu;
}

int Automata::getCash() const {
    return this->cash;
}
