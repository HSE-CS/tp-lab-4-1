#include "Automata.h"
#include <iostream>

int main() {
    Automata machine;
    machine.on();
    
    std::cout << "State: " << machine.getState() << std::endl;
    machine.coin(60);
    std::cout << "State: " << machine.getState() << std::endl;
    machine.getMenu();
    machine.choice(10);
    std::cout << "State: " << machine.getState() << std::endl;
    machine.coin(20);
    std::cout << "State: " << machine.getState() << std::endl;
    machine.choice(10);
    std::cout << "State: " << machine.getState() << std::endl;
    machine.cook();
    machine.off();
    std::cout << "Cash: " << machine.getCash() << std::endl;
    return 0;
}