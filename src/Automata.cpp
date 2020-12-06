#include <iostream>
#include "../include/Automata.h"

using namespace std;

Automata::Automata() {

    state = OFF;

    menu = {
            {"Tea",                  25},
            {"Espresso",             30},
            {"Double espresso",      35},
            {"Cappuccino",           40},
            {"Latte",                40},
            {"Hot chocolate",        40},
            {"Double hot chocolate", 45},
    };
}

void Automata::on(){
    if (state == OFF)
        state = WAIT;
}

void Automata::off(){
    if (state == WAIT)
        state = OFF;
}

void Automata::finish(){
    if (state == COOK)
        state = WAIT;
}

STATES Automata::getState(){
    return state;
}

void Automata::cancel(){
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cash = 0;
    }
}

void Automata::coin(double cash){
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        this->cash += cash;
    }
}

void Automata::choice(string beverage){
    if (state == ACCEPT){
        if (menu.find(beverage) != menu.end()){
            state = CHECK;
            target = beverage;
            check();
        }
        else
            cancel();
    }
}

void Automata::check(){
    if(state == CHECK){
        if (cash >= menu[target]){
            cout << "Change: " << cash - menu[target] << endl;
            cash -=  menu[target];
            cook();
        }
        else
            cout << "Not enough: " << menu[target] - cash << endl;
    }
}

void Automata::cook(){
    if(state == CHECK){
        state = COOK;
        finish();
    }
}

string Automata::getMenu(){
    string res;
    map <string, double>::iterator it;
    string str;
    for (it = menu.begin(); it != menu.end(); it++) {
        str = it->first + "\t" + to_string(it->second) + "\n";
        res.append(str);
    }
    return res;
}

