//
// Created by sharg on 28.11.2020.
//

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>

#include "States.h"

using namespace std;

class Automata {
 private:
     int cash = 0;
     int value = 0;
     string lastChoice;
     map<string, int> menu;
     States state = OFF;
     ostream *input_stream{};
 public:
     Automata();

     explicit Automata(ostream *);

     void on();

     void off();

     map<string, int> getMenu();

     void setMenu();

     void printMenu();

     void coin(int coinValue);

     void cook();

     void choice(const string &selectedProduct);

     bool check(int price);

     States getState();

     void getChange();

     void cancel();

     void finish();
};

#endif
