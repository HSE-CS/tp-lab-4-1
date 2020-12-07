// Copyright 2020 Anastasiya Rogozyan


#include <unistd.h>
#include <iostream>
#include "../include/Automata.h"

int main() {
    Automata a = Automata();
    a.on();
    std::cout << a.getMenu() << std::endl;
    a.coin(20);
    a.choice(2);
    if (a.check()) {
        a.cook();
        usleep(5000000);
        a.finish();
    }
    std::cout << a.getState() << std::endl;
    return 0;

//
