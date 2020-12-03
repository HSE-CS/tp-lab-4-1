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
  a.addCash(10);
  STATES expected = ACCEPT;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test4) {
  Automata a;
  a.on();
  a.addCash(10);
  a.choice("Cofee");
  STATES expected = CHECK;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test5) {
  Automata a;
  a.on();
  a.addCash(10);
  a.choice("Cofee");
  a.cancel()
  STATES expected = WAIT;
  EXPECT_EQ(expected, a.getState());
}

TEST(automata, test6) {
  Automata a;
  a.on();
  a.addCash(10);
  EXPECT_EQ(10, a.getCash());
}

TEST(automata, test7) {
  Automata a;
  a.addCash(10);
  EXPECT_EQ(0, a.getCash());
}

TEST(automata, test8) {
  Automata a;
  a.on();
  a.addCash(10);
  EXPECT_EQ(1, a.choice("Tea"));
}

TEST(automata, test9) {
  Automata a;
  a.on();
  a.addCash(10);
  EXPECT_EQ(0, a.choice("Cofee"));
}

TEST(automata, test10) {
  Automata a;
  a.on();
  a.addCash(100);
  EXPECT_EQ(0, a.choice("Milk"));
}

TEST(automata, test11) {
  Automata a;
  a.on();
  a.addCash(100);
  a.choice("Cofee");
  EXPECT_EQ(-1, a.choice("Cofee"));
}

TEST(automata, test12) {
  Automata a;
  a.on();
  a.off()
  STATES expected = OFF;
  EXPECT_EQ(expected, a.getState());
}
