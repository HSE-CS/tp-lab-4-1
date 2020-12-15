//
// Created by Kostin Andrej on 2020.
//
#include "Automata.h"
void Automata::on() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off() {
    state = OFF;
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        lastTransaction += money;
        state = ACCEPT;
        cout<< "INFO:The money is deposited in the account."<< endl;
    }
    else{
        cout<< "INFO:The money is not credited to the account."<< endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        lastTransaction = 0;
        state = WAIT;
    }
}

string* Automata::getMenu() {
    auto *menu = new string[9];
    cout << "Menu"<<endl;
    for (int i = 0; i < 9; ++i) {
        menu[i] += to_string(i + 1) += ") ";
        menu[i] += this->menu[i] += " - ";
        menu[i] += to_string(this->prices[i]) += " cents";
    }
    for (int i = 0; i < 8; ++i) {
        cout << menu[i] << endl;
    }
    return menu;
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int num) {
    if (state == ACCEPT) {
        state = CHECK;
        this->check(num - 1);
    }
}

void Automata::check(int num) {
    if (lastTransaction >= prices[num]){
        this->cook();
        cash += prices[num];
        lastTransaction = 0; //сдача
    }
    else {
        cancel();
    }
}

void Automata::cook() {
    state = COOK;
    this->finish();
}

void Automata::finish() {
    state = WAIT;
}

long Automata::getCash() {
    return cash;
}
