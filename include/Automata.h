#pragma once
#define AUTOMATA_H
#ifdef AUTOMATA_H
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include<vector>
using namespace std;
enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};
class Automata
{
private:
    int cash;
    std::vector <std::string> menu = { "Coffee", "Black tea", "Green tea" ,"Latte", "Espresso"};;
    std::vector <int> prices = {25, 10,15,35,25};
    STATES state;
public:
    Automata();
    void on();
    void off();
    void coin(int money);
    string getMenu();
    STATES getState();
    void choice(int number);
    void check(int number);
    void cancel();
    void cook();
    void finish();
};
#endif // AUTOMATA_H
