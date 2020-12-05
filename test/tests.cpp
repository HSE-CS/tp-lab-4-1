// Copyright 2020 FOM
#include <gtest/gtest.h>
#include "Automata.h"

TEST(Automata_test, test1) {
    Automata automata_1;
    automata_1.on();
    EXPECT_EQ(automata_1.getState(), WAIT);
}

TEST(Automata_test, test2) {
    Automata automata_2;
    STATES expect = OFF;
    EXPECT_EQ(expect, automata_2.getState());
}

TEST(Automata_test, test3) {
    Automata automata_3;
    automata_3.cook();
    EXPECT_EQ(automata_3.getState(), COOK);
}

TEST(Automata_test, test4)
{
    Automata automata_4;
    automata_4.off();
    STATES expect = OFF;
    EXPECT_EQ(expect, automata_4.getState());
}

TEST(Automata_test, test5) {
    Automata automata_5;
    automata_5.on();
    automata_5.coin(60);
    automata_5.choice(0);
    EXPECT_EQ(automata_5.getState(), ACCEPT);
}

TEST(Automata_test, test6) {
    Automata automata_6;
    automata_6.on();
    automata_6.coin(1);
    automata_6.choice(6);
    automata_6.check(6);
    STATES expected = CHECK;
    EXPECT_EQ(expected, automata_6.getState());
}

TEST(Automata_test, test7) {
    Automata automata_7;
    automata_7.on();
    automata_7.coin(5);
    automata_7.coin(15);
    automata_7.choice(10);
    automata_7.check(10);
    EXPECT_EQ(automata_7.getState(), WAIT);
}

TEST(Automata_test, test8) {
    Automata automata_8;
    automata_8.on();
    automata_8.coin(8);
    STATES expected = ACCEPT;
    EXPECT_EQ(expected, automata_8.getState());
}

TEST(Automata_test, test9) {
    Automata automata_9;
    automata_9.coin(70);
    STATES expected = OFF;
    EXPECT_EQ(expected, automata_9.getState());
}

TEST(Automata_test, test10)
{
    Automata automata_10;
    automata_10.on();
    automata_10.coin(30);
    automata_10.coin(10);
    EXPECT_EQ(20, automata_10.choice(9));
}
