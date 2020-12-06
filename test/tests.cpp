#include<gtest/gtest.h>
#include"Automata.h"

TEST(automata_t, test1) {

  Automata avt;
  EXPECT_EQ(OFF, avt.getState());

}

TEST(automata_t, test2) {
  Automata avt;
  avt.on();
  EXPECT_EQ(WAIT, avt.getState());
}

TEST(automata_t, test3) {

  Automata avt;
  avt.on();
  avt.coin(30);
  EXPECT_EQ(30, avt.get_cash());

}

TEST(automata_t, test4) {

  Automata avt;
  avt.on();
  avt.coin(3);
  avt.coin(3);
  EXPECT_EQ(6, avt.get_cash());

}

TEST(automata_t, test5) {

  Automata avt;
  avt.on();
  avt.coin(30);
  avt.cancel();
  EXPECT_EQ(WAIT, avt.getState());

}

TEST(automata_t, test6) {

  Automata avt;
  avt.on();
  avt.coin(330);
  avt.choice(3);
  EXPECT_EQ(3, avt.get_ch());

}

TEST(automata_t, test7) {

  Automata avt;
  avt.on();
  avt.coin(30);
  avt.choice(1);
  EXPECT_FALSE(avt.check());

}

TEST(automata_t, test8) {

  Automata avt;
  avt.on();
  avt.coin(300);
  avt.choice(5);
  EXPECT_TRUE(avt.check());

}

TEST(automata_t, test9) {

  Automata avt;
  avt.on();
  avt.coin(130);
  avt.choice(3);
  EXPECT_EQ(CHECK, avt.getState());

}

TEST(automata_t, test10) {

  Automata avt;
  avt.on();
  avt.coin(130);
  avt.choice(3);
  avt.cancel();
  EXPECT_EQ(WAIT, avt.getState());

}

TEST(automata_t, test11) {

  Automata avt;
  avt.on();
  avt.coin(130);
  avt.choice(3);
  avt.cook();
  EXPECT_EQ(COOK, avt.getState());

}

TEST(automata_t, test12) {

  Automata avt;
  avt.on();
  avt.coin(130);
  avt.choice(3);
  if (avt.check() == true) avt.cook();
  avt.finish();
  EXPECT_EQ(WAIT, avt.getState());

}


TEST(automata_t, test13) {

  Automata avt;
  avt.on();
  avt.off();
  EXPECT_EQ(OFF, avt.getState());

}
