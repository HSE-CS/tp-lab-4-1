// Copyright 2020 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <vector>
#include <string>
#include <fstream>

enum STATES {
    OFF, 
    WAIT, 
    ACCEPT, 
    CHECK, 
    COOK};

class Automata {
    private:
        double cash;
        std::vector<std::string> menu;
        std::vector<double> price;
        STATES state;
        void cook();
        void finish();
    public:
        Automata();
        void on();
        void off();
        void coin(double);
        std::vector<std::string> getMenu(); 
        STATES getState();  
        void choice();
        void check(int);
        void cancel();
};

#endif  //INCLUDE_AUTOMATA_H_