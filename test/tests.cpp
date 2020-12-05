// Copyright 2020 Polina Lukicheva
#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
  Automata a;
  STATES expected = OFF;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test2) {
  Automata a;
  a.on();
  STATES expected = WAIT;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test3) {
  Automata a;
  a.on();
  a.coin(100);
  STATES expected = ACCEPT;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test4) {
  Automata a;
  a.on();
  std::string expected = "Americano\t40.000000\nBlack tea\t40.000000\nCacao\t50.000000\nCappuccino\t100.000000\nDouble espresso\t80.000000\nEspresso\t50.000000\nGreen tea\t40.000000\nHot chokolate\t90.000000\nHot water\t200.000000\nLatte\t100.000000\n";
  EXPECT_EQ(expected, a.getMenu());
}

TEST(automata, test5) {
  Automata a;
  a.on();
  a.off();
  STATES expected = OFF;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test6) {
  Automata a;
  a.on();
  a.coin(200);
  a.select("Cacao");
  STATES expected = WAIT;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test7) {
  Automata a;
  a.on();
  a.coin(200);
  a.select("Coffee");
  STATES expected = WAIT;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test8) {
  Automata a;
  a.on();
  a.coin(50);
  a.select("Latte");
  STATES expected = CHECK;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test9) {
  Automata a;
  a.on();
  a.coin(200);
  a.cancel();
  STATES expected = WAIT;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test10) {
  Automata a;
  a.on();
  a.coin(200);
  a.select("Cappuccino");
  a.cancel();
  STATES expected = WAIT;
  EXPECT_EQ(expected, a.getState());
}
