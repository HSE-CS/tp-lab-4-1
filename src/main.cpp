#include <iostream>
#include "Automata.h"

int main() {
    Automata automata;
    automata.on();
    automata.coin(50);
    std::cout << automata.getState() <<'\n';
    automata.choice(2);
    std::cout << automata.getState() <<'\n';
    automata.check();
    std::cout << automata.getState() <<'\n';
    automata.cook();
    std::cout << automata.getState() <<'\n';
    automata.finish();
    std::cout << automata.getState() <<'\n';
    return 0;
}