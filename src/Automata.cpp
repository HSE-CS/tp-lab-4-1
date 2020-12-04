// Copyright AndreyBakurskii
#include "Automata.h"

Automata::Automata() {
  this->cash = 0;
  this->state = STATE::WAIT;
  this->order = "";
  this->menu = std::map<std::string, int> {
    {"Black tea", 30},
    {"Green tea", 30},
    {"Coffe", 45},
    {"Coffee with milk", 50},
    {"Chocolate milk", 50},
    {"Latte", 60},
    {"Americano", 60},
    {"Cappuccino", 60},
    {"Espresso", 60}};
}

bool Automata::on() {
  if (this->state != STATE::OFF) return false;

  this->state = STATE::WAIT;
  return true;
}

bool Automata::off() {
  if (this->state != STATE::WAIT) return false;

  this->state = STATE::OFF;
  return true;
}

bool Automata::coin(int money) {
  if (this->state != STATE::WAIT && this->state != STATE::ACCEPT) {
    return false;
  }

  this->cash += money;
  this->state = STATE::ACCEPT;

  return true;
}

std::string Automata::getMenu() {
  std::string str_menu = "MENU:\n";

  int index = 0;
  for (const auto& product : this->menu) {
    str_menu.append(std::to_string(index) + ". " + product.first + " = " +
    std::to_string(product.second) + "\n");
  }

  return str_menu;
}

STATE Automata::getState() { return this->state; }

int Automata::getCash() { return this->cash; }

bool Automata::choice(const std::string& user_order) {
  if (this->state != STATE::ACCEPT) return false;

  for (const auto& product : this->menu) {
    if (product.first == user_order) {
      this->order = user_order;
      this->state = STATE::CHECK;

      return true;
    }
  }

  return false;
}

bool Automata::check() {
  if (this->state != STATE::CHECK) return false;

  if (this->cash <= this->menu[this->order]) {
    this->state = STATE::ACCEPT;
    this->order = "";

    return false;
  }

  this->state = STATE::COOK;
  this->cash -= this->menu[this->order];
  return true;
}

bool Automata::cook() {
  if (this->state != STATE::COOK) return false;
  return true;
}

std::pair<std::string, int> Automata::finish() {
  std::pair<std::string, int> result = {this->order, this->cash};
  this->cash = 0;
  this->order = "";
  this->state = STATE::WAIT;
  return result;
}

int Automata::cancel() {
  int extra_money = this->cash;
  this->state = STATE::WAIT;
  this->order = "";
  this->cash = 0;

  return extra_money;
}
