//  Copyright 2020 Nikita Naumov
#include "Automata.h"

Automata::Automata() {
    this->cash = 0;
    for (size_t i = 0; i < menuSize; ++i) {
        this->codes[i] = i+10;
    }
    this->state = 0;
}

void Automata::on() {
    switch (this->state) {
        case offline:
            this->state = waiting;
            std::cout << "Now automata is ready to work" << std::endl;
            break;
        case waiting:
        case acceptingMoney:
        case cooking:
            std::cout << "Automata is already working" << std::endl;
            break;
    }
}

void Automata::off() {
    switch (this->state) {
        case waiting:
            this->state = offline;
            std::cout << "Now automata is turned off" << std::endl;
            break;
        case acceptingMoney:
            std::cout << "To off the automata, please, press cancel to get your change and try again" << std::endl;
            std::cout << "Now automata is turned off" << std::endl;
            break;
        case cooking:
            std::cout << "You can't off automata while cooking. Try again later" << std::endl;
            break;
        case offline:
            std::cout << "Automata is already offline" << std::endl;
            break;
    }
}

void Automata::coin(int m) {
    if (this->state == offline){
        this->state = offline;
        return;
    }
    this->state = acceptingMoney;
    int money = 0;
    if (m == 0) {
        std::cout << "Insert the coin or banknote" << std::endl;
        std::cin >> money;
    } else {
        money = m;
    }
    if (money == 1 || money == 2 || money == 5 || money == 10 || money == 50 || money == 100 || money == 200){
        this->cash += money;
        std::cout << "Now you have " << this->cash  << " rubles on your account " << std::endl;
    } else {
        if (money > 10){
            std::cout << "*The sound of returning banknote*" << std::endl;
        } else {
            std::cout << "*The sound of falling coin*" << std::endl;
        }
    }
}


std::string Automata::getMenu() {
    std::string str;
    std::cout << "Product code\t" << "Product Name\t" << "Price" << std::endl;
    if (this->state == offline) {
        str = "";
        return str;
    }
    for (size_t i = 0; i < menuSize; ++i) {
        std::cout << this->codes[i] << "\t\t" << this->menu[i] << "\t\t" << this->prices[i] << std::endl;
        str += std::to_string(this->codes[i]) + " " + this->menu[i] + " " + std::to_string(this->prices[i]) + "\n";
    }
    return str;
}

int Automata::getState() {
    switch (this->state) {
        case offline:
            //std::cout << "Automata is off" << std::endl;
            return offline;
            break;
        case waiting:
            //std::cout << "Automata is waiting" << std::endl;
            return waiting;
            break;
        case acceptingMoney:
            //std::cout << "Automata is accepting money" << std::endl;
            return acceptingMoney;
            break;
        case cooking:
            //std::cout << "Automata is cooking" << std::endl;
            return cooking;
            break;
        }
    return offline;
}

bool Automata::check(int option) {
    int _option = -1;
    for (size_t i = 0; i < menuSize; ++i) {
        if (codes[i] == option) {
            _option = i;
        }
    }
    if (_option != -1) {
        if (this->cash >= this->prices[_option]) {
            return true;
        }
    }
    return false;
}

void Automata::choice(int option) {
    int option_n = -1;
    if (option == 0) {
        std::cout << "Choose your option (code)" << std::endl;
        std::cin >> option_n;
    } else {
        option_n = option;
    }
    if (check (option_n)) {
        int _option = -1;
        for (size_t i = 0; i < menuSize; ++i) {
            if (codes[i] == option_n) {
                _option = i;
            }
        }
        cook(_option);
    } else {
        std::cout << "You have entered wrong code or you don't have enough money";
    }
    
}


void Automata::cancel() {
    if (this->state != cooking && this->state != offline) {
        std::cout << "Cancelling the process" << std::endl;
        if (this->cash != 0){
            std::cout << "Returning money..." << std::endl << "*The sound of falling coins*" << std::endl;
            this->cash = 0;
        }
        this->state = waiting;
    }
}

void Automata::cook(int option) {
    this->cash -= prices[option];
    this->state = cooking;
    std::cout << "*The sounds of automata working*" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    finish();
}

void Automata::finish() {
    std::cout << "Here is your order! Warning, drink is hot" << std::endl;
    if (this->cash != 0) {
        std::cout << "Now you have " << this->cash  << " rubles on your account " << std::endl;
        this->state = acceptingMoney;
    } else {
        this->state = waiting;
    }
}
