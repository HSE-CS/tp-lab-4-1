#include "gtest/gtest.h"
#include "Automata.h"

TEST(AutomataTest, test1) {
    Automata a;
    int stage = a.getState();
    EXPECT_EQ(0, stage);
}

TEST(AutomataTest, test2) {
    Automata a;
    a.on();
    int stage = a.getState();
    EXPECT_EQ(1, stage);
}

TEST(AutomataTest, test3) {
    Automata a;
    a.on();
    a.coin(50);
    int stage = a.getState();
    EXPECT_EQ(2, stage);
}

TEST(AutomataTest, test4) {
    Automata a;
    a.on();
    a.coin(5);
    a.choice(6);
    EXPECT_EQ(0, a.check(6));
}

TEST(AutomataTest, test5) {
    Automata a;
    a.on();
    a.coin(7);
    a.choice(0);
    a.cancel();
    int stage = a.getState();
    EXPECT_EQ(1, stage);
}

TEST(AutomataTest, test6) {
    Automata a;
    a.on();
    a.coin(250);
    a.choice(3);
    int stage = a.getState();
    EXPECT_EQ(1, stage);
}

TEST(AutomataTest, test7) {
    Automata a;
    a.on();
    a.coin(100);
    double res = a.cancel();
    EXPECT_EQ(100, res);
}

TEST(AutomataTest, test8) {
    Automata a;
    a.on();
    a.coin(10);
    a.coin(10);
    a.coin(10);
    a.coin(15);
    double res = a.cancel();
    EXPECT_EQ(45, res);
}

TEST(AutomataTest, test9) {
    Automata a;
    a.on();
    a.coin(6);
    a.coin(15);
    a.coin(3);
    int stage = a.getState();
    EXPECT_EQ(2, stage);
}

TEST(AutomataTest, test10) {
    Automata a;
    a.on();
    a.coin(5);
    a.choice(5);
    int stage = a.getState();
    EXPECT_EQ(2, stage);
}
