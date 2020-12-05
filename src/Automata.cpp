// Copyright Nikolaev Ivan


#include "Automata.h"

Automata::Automata() {
    this->state = OFF;
    this->cash = 0;

}

void Automata::off() {
    if (getState() == WAIT)
	    this->state = OFF;
}

void Automata::on() {
    if (getState() == OFF)
    this->state = WAIT;
}
void Automata::coin(int money) {
    if (getState() == WAIT || getState() == ACCEPT) {
        this->state = ACCEPT;
        this->cash += money;
    }
}
string Automata::getMenu() {
    string res = "Menu: \n";
    for (int i = 0; i < menu.size(); i++) {
        res += '(' + to_string(i) + ')' + this->menu[i] + " Price: " + to_string(prices[i]) + string("\n");
    }
    return res;
}
STATES Automata::getState() {
    return this->state;
}
void Automata::choice(int beverage) {
    if (getState() == ACCEPT) {
        this->state = CHECK;
        check(beverage);
    }
}
void Automata::check(int beverage) {
    if (this->cash < prices[beverage]) {
        cancel();
    }
    else {
        this->cash -= prices[beverage];
        this->state = COOK;
        cook();
    }
}
void Automata::cancel() {
    if (getState() == ACCEPT || getState() == CHECK) {
        coin(-1 * this->cash);
        this->state = WAIT;
    }
}
void Automata::cook() {
    printf("Making the beverage..\n");
    printf("Done!\n");
    finish();
}
void Automata::finish() {
    this->state = ACCEPT;
    cancel();
}
