#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test) {
  Automata test;
  STATES expected = OFF;
  EXPECT_EQ(expected, test.getState());
}

TEST(automata, test) {
  Automata test;
  test.on();
  STATES expected = WAIT;
  EXPECT_EQ(expected, test.getState());
}


TEST(automata, test) {
  Automata test;
  test.on();
  test.coin(2);
  STATES expected = ACCEPT;
  EXPECT_EQ(expected, test.getState());
}

TEST(automata, test) {
  Automata test;
  test.coin(2);
  STATES expected = OFF;
  EXPECT_EQ(expected, test.getState());
}


TEST(automata, test) {
  Automata test;
  test.on();
  test.coin(2);
  test.choice();
  STATES expected = CHECK;
  EXPECT_EQ(expected, test.getState());
}

TEST(automata, test) {
  Automata test;
  test.on();
  test.coin(1);
  test.choice();
  test.check(1);
  STATES expected = CHECK;
  EXPECT_EQ(expected, test.getState());
}

