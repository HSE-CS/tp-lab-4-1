// Copyright 2020 mkhorosh
#include "Automata.h"
#include <string>
#include <iostream>
#include <map>
#include <thread>
#include <chrono>

void Automata::on() { // change state + get menu
  if (state == OFF) {
    std::cout << "Hello! I am ready to work." << std::endl;
    state = WAIT;
    this->getMenu();
  }
}

std::string Automata::getState() {
  static std::string states[] = {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
  return states[state];
}

void Automata::off() { // change state
  if (state == WAIT) {
    std::cout << "Goodbye! I am turned off." << std::endl;
    state = OFF;
  }
}

void Automata::coin(double input) { // client add money
  if (state == WAIT || state == ACCEPT) {
    balance += input;
    state = ACCEPT;
    std::cout << "current balance is " << balance << std::endl;
  }
}

void Automata::getMenu() { // menu&prices
  std::map<std::string, double>::iterator it;
  std::cout << "MENU:" << std::endl;
  for (it = menu.begin(); it != menu.end(); it++) {
    std::cout << it->first << "\t" << it->second << std::endl;
  }
  std::cout << std::endl;
}

void Automata::choice(std::string order) { // read order(string) + check
  if (state == ACCEPT) {
    state = CHECK;
    if (this->check(order)) {
      this->cook();
    }
  }
}

bool Automata::check(std::string order) { // is added money enough
  if (menu.count(order) == 1) {
    double cost = menu.find(order)->second;
    if (cost <= balance) {
      balance -= cost;
      cash += cost;
      return 1;
    } else {
      this->cancel();
      std::cout << "not enough money ):" << std::endl;
      return 0;
    }
  } else {
    std::cout << "error" << std::endl;
    this->cancel();
    return 0;
  }
}

void Automata::cancel() { // change state
  if (state == ACCEPT || state == CHECK) {
    state = WAIT;
  }
}

void Automata::cook() { // image and timer imitation of cooking
  state = COOK;
  std::cout << "***WAIT***" << std::endl;
  int simbol = 254; // ascii of black square
  for (int i = 0; i < 7; i++) {
    std::cout << (char) simbol;
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
  }
  std::cout << std::endl << "   DONE   " << std::endl;
  this->finish();
}

void Automata::finish() { // change state + money back
  state = WAIT;
  if (balance > 0) {
    std::cout << "don't forget you change: " << balance << std::endl;
    balance = 0;
  }
}
