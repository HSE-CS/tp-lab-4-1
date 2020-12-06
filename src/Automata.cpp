//
// Created by sharg on 28.11.2020.
//
#include "Automata.h"

#include <utility>
#include <zconf.h>

using namespace std;
const char *lineEnd = "\n";

Automata::Automata() {
    //конструктор со стандартным потоком COUT
    setMenu();
    input_stream = &(cout);
    *(input_stream) << "The Automata has been created, the state is OFF, cash is 0" << lineEnd;
}

Automata::Automata(ostream *input_stream) {
    //конструктор с изначально заданным потоком
    setMenu();
    this->input_stream = input_stream;
    *(input_stream) << "The Automata has been created, the state is OFF, cash is 0\"" << lineEnd;
}

void Automata::on() {
    //Включение автомата, или оповещение если он уже работает
    if (state == OFF) {
        state = WAIT;
        (*input_stream) << "Automata is ready to work" << lineEnd;
    } else {
        (*input_stream) << "Automata is already working" << lineEnd;
    }
}

void Automata::off() {
    //Выключение автомата, если это возможно
    if (state == OFF) {
        (*input_stream) << "Automata is already off" << lineEnd;
        return;
    }
    if (state == WAIT) {
        state = OFF;
        (*input_stream) << "Automata is off" << lineEnd;
    } else {
        (*input_stream) << "Finish the operation to turn off Automata" << lineEnd;
    }
}

void Automata::setMenu() {
    //созданиие меню
    menu = {
            {"Water",                20},
            {"Tea",                  30},
            {"Hot chocolate",        40},
            {"Expresso",             50},
            {"Americano",            50},
            {"Сappuccino",           60},
            {"Coco-Cola",            60},
            {"Sprite",               60},
            {"Latte",                60},
            {"Double Hot Chocolate", 70},
            {"Premium Americano",    70}};

}

map<string, int> Automata::getMenu() {
    //получение меню
    return menu;
}

States Automata::getState() {
    //получение состояния
    return state;
}


void Automata::printMenu() {
    // вывод меню
    if (state != OFF) {
        (*input_stream) << "Automata Menu" << lineEnd;
        for (auto &position : menu) {
            (*input_stream) << position.first << " - " << position.second << lineEnd;
        }
    } else {
        (*input_stream) << "Automata is off" << lineEnd;
    }
}

void Automata::coin(int coinValue) {
    if (state == WAIT || state == ACCEPT) {
        cash += coinValue;
        state = ACCEPT;
        (*input_stream) << "Now " << coinValue << " coins have been deposited into Automata" << lineEnd;
        (*input_stream) << "You have deposited " << cash << " coins in total" << lineEnd;
    } else {
        (*input_stream) << "Coins cannot be added now" << lineEnd;
    }
}

void Automata::cook() {
    if (state == CHECK) {
        (*input_stream) << "Starts to cook: " << lastChoice << lineEnd;
        for (int iter = 0; iter < 5; iter++) {
            (*input_stream) << "Stage of readiness " << iter << " of 5" << lineEnd;
            sleep(2);
        }
        (*input_stream) << lastChoice << " is ready" << lineEnd;
        state = COOK;
        finish();
    } else {
        (*input_stream) << "You can't do it now" << lineEnd;
    }

}

void Automata::choice(const string &selectedProduct) {

    if (state == ACCEPT || state == CHECK) {
        lastChoice = selectedProduct;
        if (!menu[selectedProduct]) {
            (*input_stream) << "The wrong product was selected please try again" << lineEnd;
            return;
        } else {
            if (check(menu[selectedProduct])) {
                cook();
            } else {
                (*input_stream) << "Check balance and try again" << lineEnd;
            }
        }
    } else {
        (*input_stream) << "You can't do it now" << lineEnd;
    }
}

bool Automata::check(int price) {
    if (state == ACCEPT || state == CHECK) {
        if (cash >= price) {
            cash -= price;
            value += price;
            state = CHECK;
            (*input_stream) << "The money have been charged" << lineEnd;
            return true;
        } else {
            (*input_stream) << price - cash << " - coins missing" << lineEnd;
            return false;
        }
    } else {
        (*input_stream) << "You can't do it now" << lineEnd;
        return false;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        getChange();
        lastChoice = "";
        state = WAIT;
        (*input_stream) << "You have canceled all actions" << lineEnd;
    } else {
        (*input_stream) << "You can't do it now" << lineEnd;
    }
}

void Automata::finish() {
    if (state == COOK) {
        getChange();
        lastChoice = "";
        state = WAIT;
    } else {
        (*input_stream) << "You can't do it now" << lineEnd;
    }
}

void Automata::getChange() {
    if (state == COOK || state == ACCEPT || state == CHECK) {
        (*input_stream) << "Please take your change " << cash << lineEnd;
        cash = 0;
    } else {
        (*input_stream) << "You can't do it now" << lineEnd;
    }
}





