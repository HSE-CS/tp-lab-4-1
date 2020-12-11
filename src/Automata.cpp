#include "Automata.h"
#include <iostream>
#include <string>


Automata::Automata() {
    this->cash=0;
    this-> menu;
    this-> prices;
}
void Automata::on()
{
    this->state = WAIT;
}

void Automata::off()
{
    this->state = OFF;
}

void Automata::coin(int money)
{
    if (state == WAIT) {
        this->cash += money;
        state = ACCEPT;
    }
}

std::string Automata::getMenu() {
    std::string info = "";
    int num = 0;
    for (int i = 0; i <( this->menu.size()); i++) {

        num = num+1;
        info += std::to_string(num) +" "+ menu[i] + " " + std::to_string(this->prices[i]) + '\n';
    }
    return info;
}

STATES Automata::getState()
{
    return this->state;
}

void Automata::choice(int number)
{
    if (this->state != ACCEPT)
        return;
    this->state = CHECK;
}

void Automata::check(int number)
{
    if (this->state == CHECK)
        if (this->cash >= this->prices[number - 1])
            cook();
    return;
}

void Automata::cancel()
{
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
    }
}

void Automata::cook()
{
    this->state = COOK;
    printf("Cooking...\n");
 }

void Automata::finish()
{
    this->state = WAIT;
    this->cash = 0;
}  