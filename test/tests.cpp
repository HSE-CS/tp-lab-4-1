// Copyright 2020 Egor Buzanov
#include <gtest/gtest.h>

#include "Automata.h"

const std::map<std::string, int> MENU = {
    {"Americano", 25}, {"Cappuccino", 30}, {"Tea", 15}, {"Lemon tea", 20}};

TEST(automata, off1) {
  Automata coffee_machine;
  EXPECT_EQ(OFF, coffee_machine.getState());
}

TEST(automata, on) {
  Automata coffee_machine;
  coffee_machine.on();
  EXPECT_EQ(WAIT, coffee_machine.getState());
}

TEST(automata, menu) {
  Automata coffee_machine;
  coffee_machine.on();
  EXPECT_EQ(MENU, coffee_machine.getMenu());
}

TEST(automata, coin) {
  Automata coffee_machine;
  coffee_machine.on();
  coffee_machine.coin(10);
  EXPECT_EQ(ACCEPT, coffee_machine.getState());
}

TEST(automata, check) {
  Automata coffee_machine;
  coffee_machine.on();
  coffee_machine.coin(20);
  coffee_machine.choice("Lemon tea");
  coffee_machine.check();
  EXPECT_EQ(CHECK, coffee_machine.getState());
}

TEST(automata, cook) {
  Automata coffee_machine;
  coffee_machine.on();
  coffee_machine.coin(20);
  coffee_machine.choice("Lemon tea");
  coffee_machine.check();
  coffee_machine.cook();
  EXPECT_EQ(COOK, coffee_machine.getState());
}

TEST(automata, finish) {
  Automata coffee_machine;
  coffee_machine.on();
  coffee_machine.coin(20);
  coffee_machine.choice("Lemon tea");
  coffee_machine.check();
  coffee_machine.cook();
  coffee_machine.finish();
  EXPECT_EQ(WAIT, coffee_machine.getState());
}

TEST(automata, off2) {
  Automata coffee_machine;
  coffee_machine.on();
  coffee_machine.coin(20);
  coffee_machine.choice("Lemon tea");
  coffee_machine.check();
  coffee_machine.cook();
  coffee_machine.finish();
  coffee_machine.off();
  EXPECT_EQ(OFF, coffee_machine.getState());
}
