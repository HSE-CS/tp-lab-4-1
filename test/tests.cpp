#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(Automata, test1) {
    Automata a;
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test2) {
    Automata a;
    a.on();
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test3) {
    Automata a;
    a.on();
    a.off();
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test4) {
    Automata a;
    a.coin(10);
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test5) {
    Automata a;
    a.cancel();
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test6) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test7) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice("Tea");
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test8) {
    Automata a;
    a.on();
    a.coin(100);
    STATES expected = ACCEPT;
    EXPECT_EQ(expected, a.getState());
}

TEST(Automata, test9) {
    Automata a;
    a.on();
    a.coin(100);
    a.coin(50);
    STATES expected = ACCEPT;
    EXPECT_EQ(expected, a.getState());
}




