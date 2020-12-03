#include "Automata.h"

Automata::Automata()
{
    this->cash = 0;
    this->state = OFF;
    this->menu.push_back("tea");
    this->price.push_back(2);
    
}

void Automata::on()
{
    if (this->state != OFF)
        return;
    this->state = WAIT;
}

void Automata::off()
{
    this->cash = 0;
    this->state = OFF;
}

void Automata::coin(double coin)
{
    if (this->state != ACCEPT && this->state != WAIT)
        return;
    this->state = ACCEPT;
    this->cash += coin;
}

std::vector<std::string> Automata::getMenu()
{
    return this->menu;
} 

STATES Automata::getState()
{
    return this->state;
}  

void Automata::choice()
{
    if(this->state != ACCEPT)
        return;
    this->state = CHECK;
}

void Automata::check(int number)
{
    if (this->state == CHECK)
        if (this->cash >= this->price[number-1])
            cook();
    return;
}

void Automata::cancel()
{
    if (this->state == OFF)
        return;
    this->state = WAIT;
    this->cash = 0;
}

void Automata::cook()
{
    this->state = COOK;
    printf("Cooking...\n");
    finish();
}

void Automata::finish()
{
    this->state = WAIT;
    this->cash = 0;
}