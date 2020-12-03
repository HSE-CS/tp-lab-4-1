//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>
#include "Automata.h"

Automata::Automata() {
  this->cur_state = OFF;
  this->product_menu = {{"Tea", 10}, {"Cofee", 20}};
  this->cur_choice = "";
  this->cash = 0;
}

STATES Automata::getState() {
  return this->cur_state;
}

std::map<std::string, int> Automata::getMenu() {
  return this->product_menu;
}

void Automata::on() {
  if ( this->cur_state == OFF )
    this->cur_state = WAIT;
}

void Automata::off() {
  if ( this->cur_state == WAIT )
    this->cur_state = OFF;
}

void Automata::cancel(){
  if ( this->cur_state == ACCEPT || this->cur_state == CHECK ) {
    this->cur_state = WAIT;
    this->cash = 0;
    this->cur_choice.clear();
  }
}

int Automata::choice(std::string product_name){
  if ( this->cur_state == ACCEPT ) {
    this->cur_choice = product_name;
    this->cur_state = CHECK;
    return this->check();
  }
  return -1;
}

bool Automata::check() {
  std::map<std::string, int> :: iterator it = this->product_menu.find(this->cur_choice);
  if ( it != this->product_menu.end() && this->cash >= this->product_menu[this->cur_choice] ) {
    this->cash -= this->product_menu[this->cur_choice];
    this->cook();
    return 1;
  }
  return 0;
}

void Automata::addCash(unsigned int num_of_coins) {
  if ( this->cur_state != ACCEPT && this->cur_state != WAIT )
    return;

  this->cur_state = ACCEPT;
  this->cash += num_of_coins;
}

unsigned int Automata::getCash(){
  return this->cash;
}

void Automata::cook() {
  this->cur_state = COOK;
  std::cout << "Cooking " << this->cur_choice << " ..." << std::endl;
  this->finish();
}

void Automata::finish() {
  this->cur_state = WAIT;
  this->cur_choice.clear();
  std::cout << "Finished!" << std::endl;
}
