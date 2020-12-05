// Copyright 2020 Lukicheva Polina
#include <iostream>
#include "Automata.h"

Automata::Automata() {
  state = OFF;
  menu = { {"Americano", 40},
    {"Espresso", 50},
    {"Double espresso", 80},
    {"Latte", 100},
    {"Cappuccino", 100},
    {"Cacao", 50},
    {"Hot chokolate", 90},
    {"Black tea", 40},
    {"Green tea", 40},
    {"Hot water", 200}
  };
  choice = "";
  cash_inside = 200;
  cash_outside = 0;
}

void Automata::on() {
  if (this->state == OFF)
    this->state = WAIT;
}

void Automata::off() {
  if (this->state == WAIT)
    this->state = OFF;
}

void Automata::cook() {
  if (this->state == CHECK) {
    this->state = COOK;
    finish();
  }
}

void Automata::finish() {
  if (this->state == COOK)
    this->state = WAIT;
}

void Automata::check() {
  if (this->state == CHECK) {
    if (this->cash_outside >= this->menu[this->choice]) {
      this->cash_inside += menu[this->choice];
      std::cout << "Your change: " << this->cash_outside - menu[this->choice] << std::endl;
      cook();
    }
    else
      std::cout << "Not enough cash" << std::endl;
  } 
}

void Automata::coin(double cash) {
  if (this->state == WAIT || this->state == ACCEPT) {
    this->state = ACCEPT;
    this->cash_outside += cash;
  }
}

std::string Automata::getMenu() {
  std::string result;
  std::map<std::string, double>::iterator it;
  std::string str;
  int i = 0;
  for (it = this->menu.begin(); it != this->menu.end(); it++) {
    str = it->first + "\t" + std::to_string(it->second) + "\n";
    result.append(str);
  }
  return result;
}

STATES Automata::getState() {
  return this->state;
}

void Automata::select(std::string drink) {
  if (this->state == ACCEPT) 
    if (this->menu.find(drink) != this->menu.end()) {
      this->state = CHECK;
      this->choice = drink;
      check();
    }
    else {
      cancel();
    }

}

void Automata::cancel() {
  if (this->state == ACCEPT || (this->state == CHECK )) {
    this->state = WAIT;
    this->cash_outside = 0;
  }
}
