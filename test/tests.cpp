#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
  Automata a;
  EXPECT_EQ(OFF, a.getState());
}

TEST(automata, test2) {
  Automata a;
  a.on();
  EXPECT_EQ(WAIT, a.getState());
}

TEST(automata, test3) {
  Automata a;
  a.on();
  EXPECT_EQ(0, a.getCash());
}

TEST(automata, test4) {
  Automata a;
  a.on();
  a.coin(-1);
  EXPECT_EQ(0, a.getCash());
}

TEST(automata, test5) {
  Automata a;
  a.on();
  a.coin(10.2);
  EXPECT_EQ(10.2, a.getCash());
}

TEST(automata, test6) {
  Automata a;
  a.on();
  a.coin(10.2);
  EXPECT_EQ(ACCEPT, a.getState());
}

TEST(automata, test7) {
  Automata a;
  a.on();
  a.coin(10.2);
  a.cacel();
  EXPECT_EQ(0, a.getCash());
}

TEST(automata, test8) {
  Automata a;
  a.on();
  a.coin(10.2);
  a.cancel();
  EXPECT_EQ(WAIT, a.getState());
}

TEST(automata, test9) {
  Automata a;
  a.on();
  a.coin(10.2);
  a.choice(5);
  EXPECT_EQ(ACCEPT, a.getState());
}

TEST(automata, test10) {
  Automata a;
  a.on();
  a.coin(100);
  a.choice(5);
  EXPECT_EQ(0, a.getCash());
}