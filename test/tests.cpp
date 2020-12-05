// Copyright 2020 <Jiiijyyy>
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, test1) {
    Automata test;
    EXPECT_EQ(test.getState(), OFF);
}

TEST(AutomataTest, test2) {
    Automata test;
    test.on();
    EXPECT_EQ(test.getState(), WAIT);
}

TEST(AutomataTest, test3) {
    Automata test;
    test.on();
    test.coin(123);
    EXPECT_EQ(test.getState(), ACCEPT);
}

TEST(AutomataTest, test4) {
    Automata test;
    test.on();
    test.coin(123);
    EXPECT_EQ(test.getCoin(), 123);
}

TEST(AutomataTest, test5) {
    Automata test;
    test.on();
    test.choice(0);
    std::string Choice = "Tea - you have chosen\n";
    EXPECT_EQ(test.retChoice(), Choice);
}

TEST(AutomataTest, test6) {
    Automata test;
    test.on();
    test.choice(0);
    EXPECT_EQ(test.getChoice(), 0);
}

TEST(AutomataTest, test7) {
    Automata test;
    test.on();
    test.coin(123);
    test.choice(0);
    EXPECT_EQ(test.getState(), ACCEPT);
}

TEST(AutomataTest, test8) {
    Automata test;
    test.on();
    test.coin(123);
    test.choice(1);
    test.check();
    EXPECT_EQ(test.getChoice(), 8);
    EXPECT_EQ(test.getState(), ACCEPT);
}

TEST(AutomataTest, test9) {
    Automata test;
    test.cook();
    EXPECT_EQ(test.getState(), 0);
}

TEST(AutomataTest, test10) {
    Automata test;
    test.on();
    test.coin(25);
    test.coin(15);
    EXPECT_EQ(test.getCoin(), 40);
    test.choice(6);
    EXPECT_EQ(test.getChoice(), 6);
    test.check();
    EXPECT_EQ(test.getCoin(), 0);
    EXPECT_EQ(test.getChoice(), 8);
    EXPECT_EQ(test.getState(), WAIT);
}
