//Copyright 2020 Ryzhova
#include "Automata.h"

int main() {
    Automata a;
    a.on();
    std::cout << a.getMenu() << std::endl;
    a.coin(10.45);
    a.coin(11.0);
    a.choice(3);
    std::cout << a.getCash() << std::endl;
    a.coin(20);
    a.choice(3);
    a.off();
    return 0;
}