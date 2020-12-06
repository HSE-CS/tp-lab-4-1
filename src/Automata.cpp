// Copyright 1(6).12.2020 BD 
#include "Automata.h"

Automata::Automata()
{
    state = STATES::OFF;
    cash = 0;
    //change = 0;
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        return;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        return;
    }
}

void Automata::coin(int money) {
    if (state == STATES::OFF) { return; }
    if (state == STATES::WAIT) {
        state = STATES::ACCEPT;
        cash += money;
        return;
    }
}

string  Automata::getMenu() {
    if (state == STATES::OFF) {
        string men{ "" };
        return men;
    }
    if (state == STATES::WAIT) {
        string men = "";
        for (size_t i = 0; i < msize; i++) {
            men += to_string(i + 1) + " " + menu[i] + " " + to_string(prices[i]) + "\n";
        }
        return men;
    }
}

unsigned Automata::getState() {
    return state;
}

/*int Automata::getChange() {
    return change;
}*/

int Automata::getCoin() {
    return cash;
}

void Automata::choice(size_t count) {
    if (count == 0 || count - 1 > msize || state == STATES::OFF) { return; }
    if (state == STATES::WAIT || state == STATES::ACCEPT && count > 0 && count < 3) {
        state = STATES::CHECK;
        check(count - 1);
        return;
    }
}

void Automata::check(size_t count) {
    if (prices[count] > cash) {
        //change = cash;
        //cout << change;
        cancel();
        return;
    }
    if ((state == STATES::CHECK || state == STATES::ACCEPT) && prices[count] <= cash) {     
        //change = cash - prices[count];
        //cout << change;
        state = STATES::COOK;
        cook(count);
        return;
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        cash = 0;
        state = STATES::WAIT;
    }
}

void Automata::cook(size_t count) {
    if (state == STATES::COOK) {
        state = STATES::FINISH;
        finish();
        return;
    }
    else { return; }
}

void Automata::finish() {
    if (state == STATES::OFF) { return; }
    if (state == STATES::FINISH) {
        cash = 0;
        state = STATES::WAIT;
        return;
    }
}