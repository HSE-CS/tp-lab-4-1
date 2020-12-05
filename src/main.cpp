// Copyright 2020 <Jiiijyyy>
#include "Automata.h"


int main() {
    Automata myAutomata;
    myAutomata.on(); //On Automata
    std::cout << myAutomata.getMenu() << std::endl; //Geting menu
    myAutomata.coin(90); //Adding money
    std::cout << myAutomata.getCoin() << std::endl; //Checking the money
    std::cout << myAutomata.getState() << std::endl; //Checking the state
    myAutomata.choice(0); //Choosing tea
    std::cout << myAutomata.retChoice() << std::endl; //Checking the selection
    myAutomata.cancel(); //Cancel the selection
    std::cout << myAutomata.getState() << std::endl; //Checking the state
    myAutomata.choice(0); //Choosing tea
    myAutomata.check(); //We check the money and start working with the machine
    //Automata is working now
    myAutomata.off(); //We got tea, turned off the machine
    std::cout << myAutomata.getState() << "\n"; //Check whether it is disabled
    return 0;
}
