// Copyright 2020 Team
#include "Automata.h"
#include <iostream>


int main() {
    Automata automata;
    std::cout << STATES(automata.getState()) << std::endl;
    automata.on();
    std::cout << STATES(automata.getState()) << std::endl;
    char** menu;
    //automata.getMenu(menu);
    //for (size_t i=0; i<3; i++) cout<<menu[i]<<endl;
    std::cout << STATES(automata.getState()) << std::endl;
    automata.coin(50);
    std::cout << STATES(automata.getState()) << std::endl;
    automata.coin(25);
    std::cout << STATES(automata.getState()) << std::endl;
    automata.choice(0);
    std::cout << STATES(automata.getState()) << std::endl;
    automata.coin(100);
    std::cout << STATES(automata.getState()) << std::endl;
    automata.choice(2);
    std::cout << STATES(automata.getState()) << std::endl;
    automata.cook();
    std::cout << STATES(automata.getState()) << std::endl;
    std::cout << automata.finish() << std::endl;
    std::cout << STATES(automata.getState()) << std::endl;
    std::cout << STATES(automata.getState()) << std::endl;
    automata.off();
    std::cout << STATES(automata.getState()) << std::endl;
    return 0;
}

