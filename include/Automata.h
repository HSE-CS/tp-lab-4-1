// Copyright 2020 <Jiiijyyy>
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>

enum STATUS {
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
     unsigned choices;
     unsigned state;
 public:
     Automata();
     void on();
     void off();
     void coin(int);
     int getCoin();
     std::string getMenu();
     unsigned getState();
     int getChoice();
     std::string retChoice();
     void choice(unsigned);
     void check();
     void cancel();
     void cook();
     void finish();
     std::string error_automata(unsigned);
};
#endif  // INCLUDE_AUTOMATA_H_
