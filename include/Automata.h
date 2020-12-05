#pragma once

#include <string>

using namespace std;

enum STATES{
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    STATES state;
    string menu[6] = {"espresso", "capuccino", "latte", "milk", "hot chocolate", "water"};
    int prices[6] = {30, 40, 40, 20, 50, 10};
    int cash;
    int chosen;
public:
    Automata();
    bool on();
    bool off();
    bool coin(int);
    string getMenu();
    STATES getState();
    int get_cash();
    bool choice(int);
    bool check();
    bool cancel();
    bool cook();
    bool finish();
};


