// Copyright Nikolaev Ivan


#ifndef AUTOMATA_H_
#define AUTOMATA_H_
#include <string>
#include <vector>
using namespace std;

enum STATES {
    OFF,
    WAIT,
    ACCEPT, 
    CHECK,
    COOK
};

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(int money);
    string getMenu();
    STATES getState();
    void choice(int beverage);
    void check(int beverage);
    void cancel();
    void cook();
    void finish();
 private:
    int cash;
    vector <string> menu { "Espresso", "Double espresso", "Americano", "Latte", "Cappuccino", "White tea", "Black Tea" };
    vector <int> prices {60, 90, 70, 50, 55, 40, 30};
    STATES state;
};

#endif AUTOMATA_H  //AUTOMATA_H_
