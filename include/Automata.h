//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <map>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata{
 private:
  STATES cur_state;
  unsigned int cash;
  std::map<std::string, int> product_menu;
  std::string cur_choice;
  bool check();
  void cook();
  void finish();
 public:
  Automata();
  void on();
  void off();
  void cancel();
  void addCash(unsigned int num_of_coins);
  unsigned int getCash();
  int choice(const std::string product_name);
  std::map<std::string, int> getMenu();
  STATES getState();
};

#endif  // INCLUDE_AUTOMATA_H_
