#include <iostream>
#include "Automata.h"

int main() {
    Automata a1;
    std::cout << a1.getState() << '\n';
    a1.on();
    std::cout << a1.getState() << '\n';
    a1.coin(10);
    std::cout << a1.getState() << '\n';
    a1.coin(20);
    std::cout << a1.getBalance() << '\n';
    a1.choice("milk");
    std::cout << a1.getState() << '\n';
    a1.check();
    a1.cook();
    std::cout << a1.getState() << '\n';
    a1.coin(70);
    a1.choice("milk");
    std::cout << a1.getState() << '\n';
    a1.check();
    a1.cook();
    a1.finish();
    a1.off();
    std::cout << a1.getState() << '\n';
}
