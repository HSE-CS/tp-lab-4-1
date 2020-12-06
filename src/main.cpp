#include "Automata.h"
#include<iostream>
int main() {
    Automata test;
    test.on();
    std::map<std::string, int> menu = test.getMenu();
    for (const auto& prod : menu) {
        std::cout << prod.first << " " << prod.second << std::endl;
    }
    std::cout << test.getState() << std::endl;
    test.coin(35);
    std::cout << test.getState() << std::endl;
    test.coin(35);
    test.choice("Milk");
    test.check();
    std::cout << test.getState() << std::endl;
    test.cook();
    std::cout << test.getState() << std::endl;
    test.finish();
    std::cout << test.getState() << std::endl;
    return 0;
}