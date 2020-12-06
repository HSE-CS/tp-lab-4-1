#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(Automata, test1) {
    Automata a;
    EXPECT_EQ("OFF", a.getState());
}

TEST(Automata, test2) {
    Automata a;
    a.on();
    EXPECT_EQ("WAIT", a.getState());
}

TEST(Automata, test3) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ("OFF", a.getState());
}

TEST(Automata, test4) {
    Automata a;
    a.coin(10);
    EXPECT_EQ("OFF", a.getState());
}

TEST(Automata, test5) {
    Automata a;
    a.cancel();
    EXPECT_EQ("OFF", a.getState());
}

TEST(Automata, test6) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ("WAIT", a.getState());
}

TEST(Automata, test7) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice("Tea")
    EXPECT_EQ("WAIT", a.getState());
}

TEST(Automata, test8) {
    Automata a;
    a.on();
    a.coin(100);
EXPECT_EQ("ACCEPT", a.getState());
}

TEST(Automata, test9) {
    Automata a;
    a.on();
    a.coin(100);
    a.coin(50);
    EXPECT_EQ("ACCEPT", a.getState());
}




