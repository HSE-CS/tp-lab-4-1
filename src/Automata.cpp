#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
    }
}

void Automata::coin(double cash) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        this->cash = this->cash + cash;
    }
}

string Automata::getMenu() {
    string drinks;
    for (int i = 0; i < 5; i++) {
        if (i == 4)
        {
            drinks = drinks + menu[i] + " " + "-" + " " + to_string(i + 1);
        } else {
            drinks = drinks + menu[i] + " " + "-" + " " + to_string(i + 1) + "," + " ";
        }
    }
    return drinks;
}

string Automata::getState() {
    string state;
    switch (this->state) {
        case OFF: {
            state = "OFF";
            break;
        }
        case WAIT: {
            state = "WAIT";
            break;
        }
        case ACCEPT: {
            state = "ACCEPT";
            break;
        }
        case CHECK: {
            state = "CHECK";
            break;
        }
        case COOK: {
            state = "COOK";
            break;
        }
    }
    return state;
}

void Automata::choice(int drink) {
    if (state == ACCEPT) {
        state = CHECK;
        cook(drink);
    }
}

bool Automata::check(int drink)
{
    if (state == CHECK) {
        if (prices[drink - 1] <= this->cash) {
            return true;
        } else {
            return false;
        }
    }
}

void Automata::cook(int drink) {
    if (state == CHECK) {
        if (check(drink)) {
            state = COOK;
            finish(drink);
            state = WAIT;
        } else {
            cancel();
        }
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
    }
}

double Automata::finish(int drink) {
    if (state == COOK) {
        return this->cash - prices[drink - 1];
    }
}