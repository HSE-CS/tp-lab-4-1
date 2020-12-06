// Copyright 2020 GHA Main Team

#include <iostream>
#include "Automata.h"

int main() {
    Automata _mydrink;
    std::cout << _mydrink.getState() << std::endl;
    _mydrink.on();
    std::cout << _mydrink.getState() << std::endl;
    _mydrink.off();
    std::cout << _mydrink.getState() << std::endl;
    std::map<std::string, double> _prices1 = _mydrink.getPriece();

    _mydrink.on();
    _mydrink.coin(5.0);
    std::cout << _mydrink.getState() << std::endl;
    _mydrink.off();
    std::cout << _mydrink.getState() << std::endl;

    std::vector<std::string> _menu = _mydrink.getMenu();
    _mydrink.choice(_menu.at(0));
    std::cout << _mydrink.getState() << std::endl;

    _mydrink.coin(10.0);
    std::cout << _mydrink.getState() << std::endl;
    double _remainder1 = _mydrink.getReminder();
    std::cout << _remainder1 << std::endl;
    _mydrink.coin(45.0);
    double _remainder2 = _mydrink.getReminder();
    std::cout << _remainder2 << std::endl;
    std::cout << _mydrink.getState() << std::endl;
    _mydrink.off();
    std::cout << _mydrink.getState() << std::endl;
    _mydrink.choice(_menu.at(0));
    std::cout << _mydrink.getState() << std::endl;
    double _myremainder = _mydrink.getReminder();
    std::cout << _myremainder << std::endl;
    return 0;
}
