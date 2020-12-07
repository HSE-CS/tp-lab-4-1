#pragma once

#include <string>

enum STATES
{
	OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata
{
private:
	unsigned cash;
	unsigned* prices;
    unsigned drink;
    std::string* menu;
	STATES state;


public:
    Automata();
    void on();
    void off();
    void coin(unsigned);
    std::string getMenu() const;
    STATES getState() const;
    void choice(const int n);
    bool check();
    void cancel();
    void cook();
    void finish();

};