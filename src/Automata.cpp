// Copyright 2020 Egor Buzanov
#include "../include/Automata.h"

const std::map<std::string, int> MENU = {
    {"Americano", 25}, {"Cappuccino", 30}, {"Tea", 15}, {"Lemon tea", 20}};

Automata::Automata() {
  cash = 0;
  state = OFF;
  menu = MENU;
  product = "";
}

void Automata::on() { state = WAIT; }

void Automata::off() { state = OFF; }

void Automata::coin(unsigned int coin) {
  if (state == WAIT || state == ACCEPT) {
    state = ACCEPT;
    cash += coin;
  }
}

std::map<std::string, int> Automata::getMenu() { return menu; }

STATES Automata::getState() { return state; }

void Automata::choice(const std::string chosen) {
  if (state == ACCEPT) {
    product = chosen;
  }
}

void Automata::check() {
  if (state == ACCEPT) {
    if (cash >= menu[product]) {
      state = CHECK;
    } else
      state = ACCEPT;
  }
}

void Automata::cancel() {
  state = WAIT;
  cash = 0;
  product = "";
}

void Automata::cook() {
  if (state == CHECK) {
    state = COOK;
  }
}

void Automata::finish() {
  if (state == COOK) {
    state = WAIT;
    product = "";
    cash = 0;
  }
}
