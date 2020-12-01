//Copyright 2020 Dev-will-work
#include "gtest/gtest.h"
#include "Automata.h"
#include <string>
#include <cstdlib>
#include <iostream>

Automata::Automata() {
  this->state = STATES::OFF;
  this->all_income = 0;
  this->cash = 0;
  this->sugar = 0;
}

void Automata::on() {
  if (this->state != STATES::OFF) return;
  this->state = STATES::WAIT;
}

void Automata::off() {
  if (this->state != STATES::WAIT) return;
  this->state = STATES::OFF;
}

void Automata::coin(int money) {
  if (this->state != STATES::WAIT && this->state != STATES::ACCEPT) return;
  this->state = STATES::ACCEPT;
  this->cash += money;
  this->all_income += money;
}

const std::map<std::string, size_t>& Automata::getMenu() {
  return this->menu;
}

const STATES Automata::getState() {
  return this->state;
}

const size_t Automata::getBalance() {
  return this->cash;
}

void Automata::choice(std::string name, unsigned short sugar_count = 1) {
  if (this->state != STATES::ACCEPT) return;
  this->sugar = sugar_count;
  this->state = STATES::CHECK;
  check(name);
}

void Automata::check(std::string name) {
  if (this->state != STATES::CHECK) return;
    if (this->menu[name] > this->cash) {
      cancel();
    }
    else {
      this->cash -= this->menu[name];
      cook(name);
    }
}

void Automata::cancel() {
  if (this->state != STATES::CHECK && this->state != STATES::ACCEPT) return;
  if (this->state == STATES::ACCEPT) this->cash = 0;
  this->state = STATES::WAIT;
}

void Automata::cook(std::string name) {
  if (this->state != STATES::CHECK) return;
  this->state = STATES::COOK;
  while (rand() % 1000 != 1 + this->sugar);
  finish();
}

void Automata::finish() {
  if (this->state != STATES::COOK) return;
  this->sugar = 0;
  this->state = STATES::WAIT;
}

void printMenu(std::map<std::string, size_t> menu) {
  for (auto it : menu)
  {
      std::cout << "  " << it.first << "  " << it.second << std::endl;
  }
}





TEST(Automate, on_creation) {
  Automata automate;
  EXPECT_EQ(automate.getState(), STATES::OFF);
}

TEST(Automate, enable) {
  Automata automate;
  automate.on();
  EXPECT_EQ(automate.getState(), STATES::WAIT);
}

TEST(Automate, disable) {
  Automata automate;
  automate.on();
  automate.off();
  EXPECT_EQ(automate.getState(), STATES::OFF);
}

TEST(Automate, money_taking1) {
  Automata automate;
  automate.on();
  automate.coin(50);
  EXPECT_EQ(automate.getState(), STATES::ACCEPT);
  EXPECT_EQ(automate.getBalance(), 50);
}

TEST(Automate, money_taking2) {
  Automata automate;
  int counter = 5;
  automate.on();
  while (counter > 0) {
      automate.coin(50);
      counter--;
  }
  EXPECT_EQ(automate.getState(), STATES::ACCEPT);
  EXPECT_EQ(automate.getBalance(), 250);
}

TEST(Automate, stop1) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.cancel();
  EXPECT_EQ(automate.getState(), STATES::WAIT);
  EXPECT_EQ(automate.getBalance(), 0);
}

TEST(Automate, stop2) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.choice("latte", 2);
  EXPECT_EQ(automate.getBalance(), 50);
  EXPECT_EQ(automate.getState(), STATES::WAIT);
}

TEST(Automate, choose) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.choice("tea", 1);
  EXPECT_EQ(automate.getBalance(), 20);
  EXPECT_EQ(automate.getState(), STATES::WAIT);
}

TEST(Automate, wrong_order) {
  Automata automate;
  automate.coin(100);
  EXPECT_EQ(automate.getBalance(), 0);
  EXPECT_EQ(automate.getState(), STATES::OFF);
}

TEST(Automate, cook) {
  Automata automate;
  automate.on();
  automate.coin(50);
  automate.choice("hot chocolate", 1);
  EXPECT_EQ(automate.getState(), STATES::WAIT);
  EXPECT_EQ(automate.getBalance(), 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}
