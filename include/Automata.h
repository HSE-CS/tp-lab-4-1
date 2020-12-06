// Copyright 2020 Bogomazov Mikhail
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>

enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };

class Automata {
 private:
    
    double cash;
    std::string menu[3] = {
        "Mario",
        "Luigi",
        "Boozer"
    };
    int chosenPosition;
    double prices[3] = {
        10,
        20,
        30.2
    };
    STATES state;

 public:
    Automata() {
        state = OFF;
        cash = 0;
        chosenPosition = 0;
    }
    void on();
    void off();
    bool coin(double amount);
    std::string getMenu();
    int getState();
    bool choice(int position);
    bool check();
    bool cancel();
    bool cook();
    bool finish();
};

#endif //  INCLUDE_AUTOMATA_H_