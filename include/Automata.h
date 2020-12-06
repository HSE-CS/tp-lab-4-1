// Copyright 2020 Egor Buzanov
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <map>
#include <string>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
  unsigned int cash;
  std::map<std::string, int> menu;
  std::string product;
  STATES state;

 public:
  Automata();
  void on();
  void off();
  void coin(unsigned int);
  std::map<std::string, int> getMenu();
  STATES getState();
  void choice(const std::string);
  void check();
  void cancel();
  void cook();
  void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
