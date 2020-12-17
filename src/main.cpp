//
// Created by stoja on 15.12.2020.
//
#include "Automata.h"
#include <iostream>

int main(){
    /*Automata automata = Automata();
    automata.on();
    automata.coin(50);
    automata.coin(100);
    std::cout<<automata.getCash()<<"\n";
    automata.choice(5);
    automata.choice(1);*/
    Automata automata = Automata();
    automata.on();
    automata.coin(50);
    automata.coin(100);
    automata.choice(1);
    std::cout<<automata.getState();
    return 0;
}

