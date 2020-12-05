#include "Automata.h"


Automata::Automata() {
  state = OFF;
  cash = 0;
}

bool Automata::on(){
  if (state == OFF){
    state = WAIT;
    return true;
  } else {
    return false;
  }
}
bool Automata::off(){
  if (state == WAIT){
    state = OFF;
    return true;
  } else {
    return false;
  }
}
bool Automata::coin(int c){
  if (state == WAIT || state == ACCEPT){
    cash += c;
    state = ACCEPT;
    return true;
  } else {
    return false;
  }
}
string Automata::getMenu(){
  string s = "";
  for (int i = 0; i < 6; i++){
    s += menu[i] + ": " + to_string(prices[i]) + " RUB\n";
  }
  return s;
}
STATES Automata::getState(){
  return state;
}

int Automata::get_cash() {
  return cash;
}
bool Automata::choice(int n){
  if (state == ACCEPT && n < 6 && n >= 0){
    chosen = n;
    state = CHECK;
    return true;
  } else {
    return false;
  }
}
bool Automata::check(){ return state == CHECK && prices[chosen] <= cash; }
bool Automata::cancel(){
  if (state == ACCEPT || state == CHECK){
    state = WAIT;
    return true;
  } else {
    return false;
  }
}
bool Automata::cook(){
  if (state == CHECK && check()){
    state = COOK;
    return true;
  } else {
    return false;
  }
}
bool Automata::finish(){
  if (state == COOK){
    state = WAIT;
    cash -= prices[chosen];
    return true;
  } else {
    return false;
  }
}

