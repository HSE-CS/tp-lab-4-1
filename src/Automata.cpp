// Copyright 2020 Galex
#include "Automata.h"

Automata::Automata() {
  this->state = states::OFF;
  this->cash = 0;
}
void Automata::on() {
  if (this->state == states::OFF) {
    this->state = states::WAIT;
  }
}
void Automata::off() {
  if (this->state == states::WAIT) {
    this->state = states::OFF;
  }
}
void Automata::coin(int income) {
  if (this->state == states::WAIT) {
    this->state = states::ACCEPT;
    this->cash += income;
  } else if (this->state == states::ACCEPT) {
    this->cash += income;
  }
}
void Automata::cancel() {
  if (this->state == states::ACCEPT) {
    this->cash = 0;
    this->state = states::WAIT;
  }
}
void Automata::choice(int position) {
  if (this->state == states::ACCEPT) {
    this->state = states::CHECK;
    check(position);
  }
}
std::string Automata::getMenu() {
  std::string menuStr = "";
  for (int i = 0; i < 4; ++i) {
    menuStr += std::to_string(i + 1) + " : " + menu[i] + " - " + std::to_string(prices[i]) + "RUB \n";
  }
  return menuStr;
}
states Automata::getState() {
  return this->state;
}

void Automata::check(int position) {
  if (this->state == states::CHECK) {
    if (this->cash >= prices[position - 1]) {
      this->cash = 0;
      cook(position);
    } else {
      this->state = states::ACCEPT;
    }
  }
}
void Automata::cook(int position) {
  this->state = states::COOK;
  // some cooking procceses for selected position
  finish();
}
void Automata::finish() {
  // return cooked product to customer
  this->state = states::WAIT;
}