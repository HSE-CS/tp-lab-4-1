#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
  Automata test;
  STATES expected = OFF;
  EXPECT_EQ(expected, test.getState());
}

TEST(automata, test2) {
  Automata test;
  STATES expected = WAIT;
  EXPECT_EQ(expected, test.getState());
}


TEST(automata, test3) {
  Automata test;
  test.coin(2);
  STATES expected = ACCEPT;
  EXPECT_EQ(expected, test.getState());
}

TEST(automata, test4) {
  Automata test;
  test.coin(2);
  STATES expected = OFF;
  EXPECT_EQ(expected, test.getState());
}


TEST(automata, test5) {
  Automata test;
  test.on();
  test.coin(2);
  test.choice();
  STATES expected = CHECK;
  EXPECT_EQ(expected, test.getState());
}

TEST(automata, test6) {
  Automata test;
  test.on();
  test.coin(1);
  test.choice();
  test.check(1);
  STATES expected = CHECK;
  EXPECT_EQ(expected, test.getState());
}

