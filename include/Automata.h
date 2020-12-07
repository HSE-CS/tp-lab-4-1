#ifndef Automata_h
#define Automata_h

#include <iostream>
#include <cstring>
#include <vector>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    unsigned int cash;
    std::vector<std::string> menu;
    std::vector<unsigned int> prices;
    STATES state;
public:
    Automata();
    Automata(std::string path);
    void on();
    void off();
    void coin(unsigned int money);
    void getMenu() const;
    STATES getState() const;
    void choice(std::string beverage);
    bool check(unsigned int index);
    void cancel();
    void cook();
    void finish();
};

#endif
