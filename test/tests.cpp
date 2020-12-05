#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
    Automata a;
    a.on();
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test2) {
    Automata a;
    a.on();
    a.coin(50);
    STATES expected = ACCEPT;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test3) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(4);
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test4) {
    Automata a;
    a.on();
    a.coin(55);
    a.choice(4);
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test5) {
    Automata a;
    a.on();
    a.coin(55);
    a.off();
    STATES expected = ACCEPT;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test6) {
    Automata a;
    a.on();
    a.off();
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test7) {
    Automata a;
    a.on();
    a.coin(200);
    a.cancel();
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test8) {
    Automata a;
    a.coin(50);
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test9) {
    Automata a;
    a.choice(1);
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test10) {
    Automata a;
    a.on();
    a.choice(1);
    STATES expected = WAIT;
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test11) {
    Automata a;
    a.on();
    a.coin(40);
    a.choice(1);
    a.off();
    STATES expected = OFF;
    EXPECT_EQ(expected, a.getState());
}
TEST(automata, test11) {
    Automata automat;
    automat.on();
    automat.coin(400);
    automat.choice(1);
    automat.off();
    STATES expected = OFF;
    EXPECT_EQ(expected, automat.getState());
}