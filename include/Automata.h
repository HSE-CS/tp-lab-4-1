// Copyright 2020 <Jiiijyyy>
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <cmath>
#include <iostream>
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
     int cash; 
     std::string menu[8] = { 
         "...",
         "...",
         "...",
         "...",
         "...", 
         "...",
         "...",
         "..."
     };
     int prices[8] = { 
         0, 
         0,
         0,
         0,
         0,
         0,
         0,
         0
     };
     unsigned m_size = 7;
     unsigned choice;
     unsigned state;
 public:
     Automata();
     void on();
     void off();
     void coin(int);
     int getCoin();
     //std::string* getMenu();
     std::string getMenu();
     unsigned getState();
     void choice(unsigned);
     //void check(unsigned);
     void check();
     void cancel();
     //void cook(unsigned);
     void cook();
     void finish();
    
};
#endif  // INCLUDE_AUTOMATA_H_
