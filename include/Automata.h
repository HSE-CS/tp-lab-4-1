#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>
#include <iostream>

enum States {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
 private:
    States state;
    double cash;
    double client_cash;
    int client_choice;
    std::string menu[10] = {
        "Coffe",
        "Coffee with milk",
        "Green tea",
        "Black tea",
        "Hot chocolate",
        "Chocolate milk",
        "Latte",     
        "Americano",
        "Cappuccino",
        "Espresso" };
    int prices[10] = {
        55,
        60,
        45,
        40,
        55,
        55,
        65,
        65,
        65,
        65 };

 public:
    Automata();
    void on();
    void off();
    void coin(int coins);
    std::string* getMenu();
    States getState();
    void choice(int number);
    void check();
    void cancel();
    void cook();
    void finish();
    double getCash();
};

#endif
