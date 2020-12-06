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
     std::string* menu;
     int* prices;
     STATUS state;
 public:

     unsigned int choice_;

     Automata();
     void on();
     void off();
     void coin(int);
     int getCoin();
     std::string getMenu();
     unsigned getState();
     void choice(unsigned);
     void check();
     void cancel();
     void cook();
     void finish();
};

#endif // !INCLUDE_AUTOMATA_H_

