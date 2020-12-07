//
//  tests.cpp
//  laba
//
//  Created by Anastasiya Rogozyan on 06.12.2020.


#include <gtest/gtest.h>
#include "../include/Automata.h"

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
    test.coin(20);
    EXPECT_EQ(test.getState(), ACCEPT);
}
TEST(AutomataTest, test7) {
    Automata test;
    test.on();
    test.coin(12);
    test.choice(1);
    EXPECT_EQ(test.getState(), ACCEPT);
    EXPECT_EQ(test.getState(), CHECK);
}


TEST(AutomataTest, test8) {
    Automata test;
    test.on();
    test.coin(12);
    test.choice(1);
    test.check();
    EXPECT_EQ(test.getState(), ACCEPT);
    EXPECT_EQ(test.check(), true);
}

TEST(AutomataTest, test10) {
    Automata test;
    test.on();
    test.coin(12);
    test.choice(2);
    test.check();
    EXPECT_EQ(test.getState(), WAIT);
}
TEST(AutomataTest, test11) {
    Automata test;
    test.on();
    test.coin(23);
    test.choice(2);
    test.check();
    test.cook();
    EXPECT_EQ(test.getState(), COOK);
}
TEST(AutomataTest, test12) {
    Automata test;
    test.on();
    test.coin(23);
    test.choice(2);
    test.check();
    test.cook();
    test.finish();
    EXPECT_EQ(test.getState(), WAIT);
}
TEST(AutomataTest, test13) {
    Automata test;
    test.on();
    test.cook();
    EXPECT_EQ(test.getState(), WAIT);
}
TEST(AutomataTest, test14) {
    Automata test;
    test.on();
    test.off();
    EXPECT_EQ(test.getState(), OFF);
}
