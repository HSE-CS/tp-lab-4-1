#include "gtest/gtest.h"
#include "Automata.h"

TEST(automata_test, test1) {
  Automata a;
  EXPECT_EQ(OFF, a.getState())
}

TEST(automata_test, test2) {
  Automata a;
  a.on();
  EXPECT_EQ(WAIT, a.getState())
}

TEST(automata_test, test3) {
  Automata a;
  a.on();
  a.coin(50);
  EXPECT_EQ(ACCEPT, a.getState())
}
TEST(automata_test, test4) {
  Automata a;
  a.on();
  a.coin(50);
  EXPECT_EQ(50, a.get_cash())
}

TEST(automata_test, test5) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(0);
  EXPECT_EQ(CHECK, a.getState())
}
TEST(automata_test, test6) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(0);
  EXPECT_TRUE(a.check())
}
TEST(automata_test, test7) {
  Automata a;
  a.on();
  a.coin(20);
  a.choice(1);
  EXPECT_FALSE(a.check())
}
TEST(automata_test, test8) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(0);
  a.cancel();
  EXPECT_EQ(WAIT, a.getState())
}
TEST(automata_test, test9) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(0);
  a.cook();
  EXPECT_EQ(COOK, a.getState())
}
TEST(automata_test, test10) {
  Automata a;
  a.on();
  a.coin(10);
  a.choice(0);
  EXPECT_FALSE(COOK, a.cook())
}
TEST(automata_test, test11) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(0);
  a.cook();
  a.finish();
  EXPECT_EQ(WAIT, a.getState())
}
TEST(automata_test, test11) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(0);
  a.cook();
  a.finish();
  a.off();
  EXPECT_EQ(OFF, a.getState())
}
TEST(automata_test, test12) {
  Automata a;
  a.on();
  a.coin(10);
  a.coin(15);
  EXPECT_EQ(25, a.get_cash())
}
TEST(automata_test, test13) {
  Automata a;
  a.on();
  a.coin(50);
  a.choice(0);
  a.cook();
  a.finish();
  EXPECT_EQ(20, a.get_cash())
}
TEST(automata_test, test14) {
  Automata a;
  a.on();
  a.coin(50);
  a.cancel();
  EXPECT_EQ(WAIT, a.getState())
}
TEST(automata_test, test15) {
  Automata a;
  a.on();
  a.coin(50);
  EXPECT_FALSE(a.off())
}
TEST(automata_test, test16) {
  Automata a;
  a.on();
  a.coin(20);
  EXPECT_FALSE(a.choice(10))
}

