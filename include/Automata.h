// Copyright 2020 GHA Auto Team

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

enum STATE{
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata{
 private:
    double cash;
    std::vector<std::string> menu{
        "Tea",
        "Cappuccino",
        "Americano",
        "Latte",
        "Cocoa",
        "Hot milk",
    };
    std::map<std::string, double> prices{
        std::make_pair("Tea", 10.0),
        std::make_pair("Cappuccino", 30.0),
        std::make_pair("Americano", 35.0),
        std::make_pair("Latte", 20.0),
        std::make_pair("Cocoa", 10.0),
        std::make_pair("Hot milk", 45.0)
    };
    int state;
    double remainder;
    void cook();
    bool check(double);
    void finish();
public:
    Automata();
    void on();
    double off();
    void coin(double);
    std::map<std::string, double> getPriece();
    std::vector<std::string> getMenu();
    std::string getState();
    double getReminder();
    void cancel();
    void choice(std::string);
};

#endif // INCLUDE_AUTOMATA_H_
