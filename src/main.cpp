// Copyright 2020 aaa

#include "Automata.h"

int main(){
    Automata a;
    a.on();
    std::cout << a.getMenu();
    a.coin(10);
    a.coin(5);
    a.choice(3);
    std::cout << a.getCash() << std::endl;
    a.coin(2);
    a.choice(6);
    a.coin(10);
    a.choice(6);
    a.off();
}