//  Copyright AndreyBakurskii
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <utility>
#include <iostream>
#include <string>
#include <map>


enum STATE {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
 public:
  Automata();
  bool on();
  bool off();
  bool coin(int money);
  std::string getMenu();
  STATE getState();
  int getCash();
  bool choice(const std::string& order);
  bool check();
  int cancel();
  bool cook();
  std::pair<std::string, int> finish();

 private:
  int cash;
  std::map<std::string, int> menu;
  STATE state;
  std::string order;
};

#endif  // INCLUDE_AUTOMATA_H_
