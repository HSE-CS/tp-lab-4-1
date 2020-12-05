// Copyright 2020 Polina Lukicheva
#include <iostream>
#include "Automata.h"

int main() {
  Automata autom;
  autom.on();
  std::cout << autom.getMenu() << std::endl;
  autom.coin(210);
  autom.select("Latte");
  std::cout << "-----------------------------------\n";
  Automata b;
  b.on();
  std::cout << b.getMenu() << std::endl;
  b.coin(10);
  b.select("Latte");
}
