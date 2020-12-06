#include "Automata.h"

Automata::Automata()
{
    state=OFF;
    cash=0;
}

void Automata::on()
{
    if(state==OFF)
        state=WAIT;
}

void Automata::off()
{
    if(state==WAIT)
        state=OFF;
}

void Automata::coin(int money)
{
    if(state!=OFF)
    {
        state=ACCEPT;
        cash=cash+money;
    }
}

string Automata::getMenu()
{
    std::string per = "";
    for (int i=0; i<n; i++)
    {
        per=per+menu[i]+' '+to_string(prices[i])+"\n";
    }
    return per;
}

STATES Automata::getState()
{
    return state;
}

void Automata::cancel()
{
    if(state!=WAIT)
    {
        state=WAIT;
        cash=0;
    }
}

void Automata::cook()
{
    if(state==CHECK)
    {
        state=COOK;
        finish();
    }
}

void Automata::finish()
{
    if(state==COOK)
    {
        state=WAIT;
        cash=0;
    }
}

void Automata::check(int per)
{
    if (cash>=prices[per])
    {
        cash=cash-prices[per];
        cook();
    }
    else
        cancel();
}

void Automata::choice(int per)
{
    if (state==ACCEPT)
    {
        state=CHECK;
        check(per-1);
    }
}//

