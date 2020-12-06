#include<iostream>
#include<string>
#include "Automata.h"
Automata::Automata()
{
    state = OFF;
    cash = 0;
}
void Automata::on()
{
    if(state == OFF)
        state = WAIT;
}
void Automata::off()
{
    if(state == WAIT)
        state = OFF;
}
void Automata::coin(int count)
{
    if(state == WAIT || state == ACCEPT && count > 0 )
        cash += count;
}
void Automata::choice(int number)
{
    if(state == WAIT || state == ACCEPT && number > 0 && number < 3)
    {
        this->number = number;
        state = ACCEPT;
    }
}
bool Automata::check()
{
    if((state == CHECK || state == ACCEPT) && price[number] <= cash)
    {
        state = COOK;
        change = cash - price[number];
        return true;
    }
    return false;
}
void Automata::cook()
{
    if(state == COOK)
        state = FINISH;
}
int Automata::cancel()
{
    if(state == ACCEPT || state == CHECK)
        return cash;
}
int Automata::finish()
{
    if(state == FINISH)
    {
        state = WAIT;
        return change;
    }
    return 0;
}
Automata::States Automata::getState()
{
    return state;
}
std::string * Automata::getMenu()
{
    if(state == WAIT)
        return menu;
}
int Automata::getCash() 
{
	return cash;
}