// Copyright 2020 Lukicheva Polina
#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <string>
#include <vector>
#include <map>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
 private:
  double cash_inside;
  double cash_outside;
  std::map <std::string, double> menu;
  std::string choice;
  STATES state;
  void cook();
  void finish();
  void check();
 public:
  Automata();
  void on();
  void off();
  void coin(double);
  std::string getMenu();
  STATES getState();
  void select(std::string);
  void cancel();
};
#endif // AUTOMATA_H_
