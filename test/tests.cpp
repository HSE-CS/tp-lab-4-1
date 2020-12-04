#include <gtest/gtest.h>
#include <iostream>
#include "Automata.h"

TEST(AutomataTest, test1) {
  Automata a(std::cout);
  std::string s1 = a.getState();
  std::string s2("OFF");
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test2) {
  Automata a(std::cout);
  a.on();
  a.coin(213);
  int money = a.refund();
  EXPECT_EQ(213, money);
}

TEST(AutomataTest, test3) {
  Automata a(std::cout);
  a.on();
  std::string s1 = a.getState();
  std::string s2("WAIT");
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test4) {
  Automata a(std::cout);
  a.on();
  a.addToMenu("Juice $5");
  a.coin(5);
  a.choice(1);
  a.cook();
  a.refund();
  a.finish();
  std::string s1 = a.getState();
  std::string s2 = "WAIT";
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test5) {
  Automata a(std::cout);
  a.on();
  a.addToMenu("Juice 5$");
  a.coin(5);
  a.choice(1);
  a.cook();
  int money = a.refund();
  EXPECT_EQ(0, money);
}

TEST(AutomataTest, test6) {
  Automata a(std::cout);
  a.on();
  a.coin(5);
  std::string s1 = a.getState();
  std::string s2 = "ACCEPT";
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test7) {
  Automata a(std::cout);
  a.on();
  a.coin(5);
  a.cancel();
  std::string s1 = a.getState();
  std::string s2 = "WAIT";
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test8) {
  Automata a(std::cout);
  a.on();
  a.off();
  std::string s1 = a.getState();
  std::string s2 = "OFF";
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test9) {
  Automata a(std::cout);
  a.on();
  a.addToMenu("Juice $5");
  a.coin(5);
  a.choice(1);
  std::string s1 = a.getState();
  std::string s2 = "CHECK";
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test10) {
  Automata a(std::cout);
  a.on();
  a.addToMenu("Juice $5");
  a.addToMenu("Coca cola $6");
  std::string s1 = a.getMenu(2);
  std::string s2("2 Coca cola $6");
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test11) {
  Automata a(std::cout);
  a.on();
  a.addToMenu("Juice $5");
  a.addToMenu("Coca cola $6");
  std::string s1 = a.getMenu(3);
  std::string s2("Bad id");
  EXPECT_EQ(s1, s2);
}

TEST(AutomataTest, test12) {
  Automata a(std::cout);
  a.on();
  a.addToMenu("Juice $5");
  a.coin(5);
  a.choice(1);
  a.cook();
  std::string s1 = a.getState();
  std::string s2 = "COOK";
  EXPECT_EQ(s1, s2);
}
