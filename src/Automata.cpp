#include"Automata.h"
#include<iostream>

std::string menu_array[5] = {
  "tea",
  "lemonade",
  "cofee",
  "water",
  "hot chocolate",
};

int price_array[6] = { 15, 30, 45, 50, 90 };

Automata::Automata() {

  state = OFF;
  cash = 0;
  menu = menu_array;
  prices = price_array;
  c = -1;

}

void Automata::on() {

  state = WAIT;

}

void Automata::off() {

  state = OFF;

}

void Automata::coin(int counts) {

  if ( state == WAIT || state == ACCEPT ) {
  state = ACCEPT;
  cash = cash + counts;
  }

}

int Automata::gcash() {

   return cash;

}

void Automata::getMenu() {

  if (state != OFF) {
  for (int i = 0; i < 5; i++) {

  std::cout << i << " -  " << menu[i] << std::endl;

  }
  std::cout << std::endl;
  }

}

int Automata::getState() {

  return state;

}

void Automata::choice( std::string str) {

  state = CHECK;
  for (int i = 0; i < 5; i++) {
    if (str == menu[i]) {
       c = i;
       break;
    }
  }
}

int Automata::gchoice() {

    return c;

}

bool Automata::check() {

  if ( c < 5 && prices[c] == cash )
     return true;
  else 
     return false;
}

void Automata::cancel() {

  cash = 0;
  state = WAIT;
  c = -1;

}

void Automata::cook() {

  state = COOK;
  std::cout << " please wait, drink cook **** " << std::endl;

}

void Automata::finish() {

  std::cout << " done! you can pick up your drink! " << std::endl;
  cancel();

}
