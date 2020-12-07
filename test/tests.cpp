// Copyright 2020 test
#include "gtest/gtest.h"
#include "Automata.h"

TEST(AutomataTest, test1) {
    Automata test;
    EXPECT_EQ(test.sgetState(), "State: OFF");
}

TEST(AutomataTest, test2) {
    Automata test;
    test.on();
    EXPECT_EQ(test.sgetState(), "State: WAIT");
}

TEST(AutomataTest, test3) {
    Automata test;
    test.on();
    test.coin(10);
    EXPECT_EQ(test.sgetState(), "State: ACCEPT");
}

TEST(AutomataTest, test4) {
    Automata test;
    test.on();
    test.coin(10);
    test.choice(1);
    EXPECT_EQ(test.sgetState(), "State: CHECK");
}

TEST(AutomataTest, test5) {
    Automata test;
    test.on();
    test.coin(40);
    test.choice(1);
    EXPECT_EQ(test.sgetState(), "State: CHECK");
}

TEST(AutomataTest, test6) {
    Automata test;
    test.on();
	test.coin(500);
	test.choice(1);
    test.cook();
    EXPECT_EQ(test.sgetState(), "State: WAIT");
}

TEST(AutomataTest, test7) {
    Automata test;
    test.cancel();
    EXPECT_EQ(test.sgetState(), "State: OFF");
}

TEST(AutomataTest, test8) {
    Automata test;
    test.cook();
    EXPECT_EQ(test.sgetState(), "State: OFF");
}