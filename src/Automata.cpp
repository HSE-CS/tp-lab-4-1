#include "Automata.h"
#include <string>
#include <iostream>

Automata::Automata() {
    client_cash = 0;
    client_choice = 0;
    cash = 0;
    state = OFF;
}

void Automata::on() {
    this->state = WAIT;
    std::cout << "Welcome!" << std::endl;
}

void Automata::off() {
    this->state = OFF;
    std::cout << "Thanks for coming, bye!" << std::endl;
}

void Automata::coin(int coins) {
    if (this->state == WAIT || this->state == ACCEPT) {
        this->client_cash += coins;
        this->state = ACCEPT;
    }
}

std::string* Automata::getMenu() {
    if (this->state != OFF) {
        for (int i = 1; i <= 10; i++) {
            std::cout << i << ". " << this->menu[i - 1] << ". Price: " << this->prices[i - 1] << std::endl;
        }
    }
    else std::cout << "Turn on the machine" << std::endl;

    return nullptr;
}

States Automata::getState() {
    return this->state;
}

void Automata::choice(int number) {
    if (number > 10) std::cout << "Wrong number" << std::endl;
    else {
        this->state = CHECK;
        this->client_choice = number - 1;
        check();
    }
}

void Automata::check() {
    if (this->prices[this->client_choice] > this->client_cash) {
        std::cout << "Not enough money. Choose something different or add money and try again." << std::endl;
        this->state = WAIT;
    }
    else {
        std::cout << "All's set! Do you want to start cooking?" << std::endl;
        this->state = ACCEPT;
    };
}

void Automata::cancel() {
    if (this->state == CHECK || this->state == ACCEPT) {
        std::cout << "Your money was sent back: " << this->client_cash << std::endl;
        this->client_cash = 0;
        this->client_choice = 0;
        this->state = WAIT;
    }
    else if (this->state == COOK) {
        std::cout << "Sorry, it is not possible." << std::endl;
    }
}

void Automata::cook() {
    this->state = COOK;
    this->client_cash -= this->prices[this->client_choice];
    this->cash += this->prices[this->client_choice];
    std::cout << "All's done! ";
    finish();
}

void Automata::finish() {
    this->state = WAIT;
    std::cout << "Take your change: " << this->client_cash << std::endl;
    this->client_cash = 0;
    this->client_choice = 0;
}

double Automata::getCash() {
    return this->cash;
}
