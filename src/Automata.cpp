#include "Automata.h"

Automata::Automata() {
 cash = 0;
 menu = { "hot water", "green tea", "black tea", "americano", "cappuccino",
        "cocoa",     "latte",     "espresso",  "frappe" };
 price = { 10, 15, 15, 20, 25, 30, 30, 15, 35 };
 state = states::OFF;
 user = 0;
 change = 0;
}

void Automata::on() {
 state = ON;
 std::cout << "turn on" << std::endl << std::endl;
 state = WAIT;
 std::cout << "wait..." << std::endl << std::endl;
}

void Automata::off() {
 state = OFF;
 std::cout << "turn off" << std::endl << std::endl;
}

void Automata::coin(int c) {
 if (getState() == ACCEPT || getState() == WAIT) {
  cash += c;
  state = ACCEPT;
  std::cout << "balance: " << cash << std::endl;
 }
}

std::string Automata::getMenu() {
 std::string buf;
 for (unsigned int i = 0; i < menu.size(); i++) {
  buf += menu[i] + " - " + std::to_string(price[i]) + "\n";
 }
 return buf;
}

states Automata::getState() {
 return state;
}

void Automata::choice(const std::string user_drink) {
 if (getState() == ACCEPT) {
  bool f = 0;
  user = 0;
  for (auto& drink : menu) {
   if (drink == user_drink) {
    f = 1;
    break;
   }
   else {
    user++;
   }
  }
  if (f) {
   std::cout << "order: " << menu[user] << std::endl << std::endl;
   state = CHECK;
  }
  else {
   std::cout << "no such drink in a menu." << std::endl << std::endl;
   cancel();
  }
 }
 check();
}

bool Automata::check() {
 if (getState() == CHECK) {
  if (cash >= price[user]) {
   state = CHECK;
   change = cash - price[user];
   return 1;
  }
  else {
   std::cout << "insufficient funds." << std::endl << std::endl;
   cancel();
   return 0;
  }
 }
 else
 {
  cancel();
  return 0;
 }
}

void Automata::cancel() {
 if (getState() == ACCEPT || getState() == CHECK) {
  change = cash;
  std::cout << "change: " << change << std::endl << std::endl;
  cash = 0;
  user = 0;
  state = WAIT;
 }
}

void Automata::cook() {
 if (getState() == CHECK) {
  std::cout << "cook... " << std::endl << std::endl;
  state = COOK;
 }
}

void Automata::finish() {
 if (getState() == COOK) {
  state = WAIT;
  std::cout << "change: " << change << std::endl << std::endl;
  change = 0;
  cash = 0;
  user = 0;
  cancel();
 }
}
