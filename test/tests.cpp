// Copyright AndreyBakurskii
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AtomataTest, off) {
  Automata automata;

  EXPECT_EQ(STATE::OFF, automata.getState());
}

TEST(AtomataTest, on) {
  Automata automata;
  automata.on();

  EXPECT_EQ(STATE::WAIT, automata.getState());
}

TEST(AtomataTest, accept_1) {
  Automata automata;
  automata.coin(30);

  EXPECT_EQ(STATE::ACCEPT, automata.getState());
}

TEST(AtomataTest, accept_2) {
  Automata automata;
  automata.coin(30);
  automata.coin(30);
  EXPECT_EQ(STATE::ACCEPT, automata.getState());
}

TEST(AtomataTest, cash) {
  Automata automata;
  automata.coin(60);
  EXPECT_EQ(60, automata.getCash());
}

TEST(AtomataTest, cancel) {
  Automata automata;
  automata.coin(60);
  EXPECT_EQ(60, automata.cancel());
}

TEST(AtomataTest, wait) {
  Automata automata;
  automata.coin(60);
  automata.cancel();

  EXPECT_TRUE(STATE::WAIT, automata.getState());
}

TEST(AtomataTest, check_1) {
  Automata automata;
  automata.coin(60);
  automata.choice("Green tea");

  EXPECT_True(true, automata.check());
}

TEST(AtomataTest, check_2) {
  Automata automata;
  automata.coin(20);
  automata.choice("Green tea");

  EXPECT_TRUE(false, automata.check());
}

TEST(AtomataTest, check_finish) {
  Automata automata;
  automata.coin(30);
  automata.choice("Green tea");

  if (automata.check()) automata.cook();
  automata.finish();

  EXPECT_EQ(STATE::WAIT, automata.getState());
}
