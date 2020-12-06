// Copyright 2020 mkhorosh
#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>
#include <map>

enum mashine_state { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
  double cash;
  double balance;
  std::map<std::string, double> menu;
  mashine_state state;
 public:
  Automata() {
    cash = 1000; // how many we need
    balance = 0; // added money
    menu = {{"late latte", 190}, {"express espresso", 155},
            {"capful cappuccino", 200}, {"morning mocha", 200},
            {"hot hot chocolate", 220}}; // init into map
    state = OFF;
  };
  void on(); // change state
  void off(); // change state
  void coin(double input); // client add money
  void getMenu(); // menu&prices
  std::string getState();
  void choice(std::string order); // read order(string)
  bool check(std::string order); // is added money enough
  void cancel(); // change state
  void cook(); // image or timer imitation of cooking
  void finish(); // change state
};

#endif
