// Copyright 2020 GN
#ifndef _AUTOMATA_H
#define _AUTOMATA_H_
#include<cmath>
#include <iostream>
using namespace std;
class Automata
{
 private: 
    enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
    string states[5] = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
    int cash;
    string* menu;
    int* prices;
    int state;
    string drink;
 public:
    Automata(string* _menu = {}, int* _prices = { 0 })
    {
        cash = 0;
        menu = _menu;
        prices = _prices;
        state = OFF;
        drink = "";
    }
    void on();
    void off();
    void coin(int);
    string* getMenu();
    string getState();
    int getCoin();
    void choice(string);
    void check();
    void cancel();
    void cook();
    void finish();
};
#endif
