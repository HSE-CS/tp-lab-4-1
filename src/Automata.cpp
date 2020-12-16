#include "Automata.h"
#include <iostream>
#include <unistd.h>

Automata::Automata() {
    this->state = STATES::OFF;
    this->cash = 0;
}

bool Automata::on(){
    this->state = STATES::WAIT;
}

bool Automata::off(){
    this->state = STATES::OFF;
}

bool Automata::coin(double coins){
    this->state = STATES::ACCEPT;
    this->cash+=coins;
}

std::string Automata::getMenu() {
    std::string menu = "";
    for (int i = 0; i<menu_size; i++){
        menu+=this->menu[i]+": "+std::to_string(this->prices[i])+'\n';
    }
    return menu;
}

STATES Automata::getState() {
    return this->state;
}

bool Automata::choice(int num) {
    this->state = STATES::WAIT;
    if (menu_size>num && num>=0){
        this->user_choice = num-1;
    } else {
        std::cout << "Choose between listed drinks";
    }
}

bool Automata::check() {
    this->state = STATES::CHECK;
    if (this->cash < this->prices[this->user_choice]){
        std::cout << "Not enough money in the automata\n";
    } else {
        std::cout << "All checks are passed\n";
    }
}

bool Automata::cook(){
    this->state = STATES::COOK;
    std::cout << "Your " << this->menu[this->user_choice] << " is cooking\n...\n";
    std::cout << "Your " << this->menu[this->user_choice] << " is ready\nYou may take it now\n";
}

bool Automata::cancel() {
    this->state = STATES::WAIT;
}

bool Automata::finish() {
    this->state = STATES::WAIT;
}
