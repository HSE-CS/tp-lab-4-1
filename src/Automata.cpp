#include"Automata.h"
#include<iostream>

std::string states[5] = {
  "OFF",
  "WAIT",
  "ACCEPT",
  "CHECK",
  "COOK"
};

Automata::Automata() {
  cash = 0;
  state = OFF;
  ch = 1000;
}

void Automata::on() {
  state = WAIT;
}

void Automata::off() {
  state = OFF;
}
void Automata::coin(int c) {

  if (state == WAIT) {
  cash = c;
  state = ACCEPT;
  } else {
  cash += c;
  }


 
}
void Automata::getMenu() {
  for (int i = 0; i < 6; i++) {
  std::cout << i << " " << menu[i] << std::endl;
  }
  std::cout << std::endl;
}
void Automata::getState() {

  std::cout << states[state] << std::endl;

}
void Automata::choice( unsigned int str) {

  state = CHECK;
  ch = str;
}
bool Automata::check() {

  if (ch >= 0 && ch < 7) {
  if (cash == prices[ch])
     return true;
  else 
     return false;
  } else {
     return false;
  }

}
void Automata::cancel() {

  state = WAIT;
  cash = 0;
  ch = 1000;


}
void Automata::cook() {
  state = COOK;
  std::cout << " cooking... " << std::endl;
  //  Sleep(5000);
}
void Automata::finish() {
  std::cout << " your drink is make " << std::endl;
  state = WAIT;
  cash = 0;
  ch = 1000;
}

int Automata::get_cash() {
  return this->cash;
}

unsigned int Automata::get_ch() {
  return this->ch;
}
