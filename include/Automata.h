#pragma once
#include<string>

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
  std::string menu[6] = {
  "coca-cola",
  "lemonade",
  "cofee",
  "tea",
  "beer",
  "water"
  };
  int prices[6] = { 50, 60, 100, 130, 150, 300 };
  STATES state;
  unsigned int ch;

public:
  Automata();
  void on();
  void off();
  void coin(int c);
  void getMenu();
  void getState();
  void choice(unsigned int ch);
  bool check();
  void cancel();
  void cook();
  void finish();
  int get_cash();
  unsigned int get_ch();
};