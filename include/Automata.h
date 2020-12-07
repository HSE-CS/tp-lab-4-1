//
// Created by vladimir on 07.12.2020.
//

#ifndef TP_LAB_4_AUTOMATA_H
#define TP_LAB_4_AUTOMATA_H

#include <string>
#include <map>

using namespace std;

enum states {
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
    void choice(const string& name);
    void check(const string& product_name);
    void cook(const string& name);
    void cancel();
    void finish();
    int getCash() const;
    states getState();
    map<string, int> getMenu();


private:
    int cash;
    map<string, int> menu {
            {"coffee", 100},
            {"latte", 70},
            {"tea", 50},
            {"chocolate", 60}
    };
    states state;

};



#endif //TP_LAB_4_AUTOMATA_H

