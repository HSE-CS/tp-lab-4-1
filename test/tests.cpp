#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
    Automata a;
    std::string expected = "OFF";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test2) {
    Automata a;
    a.on();
    std::string expected = "WAIT";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test3) {
    Automata a;
    a.on();
    a.coin(50);
    std::string expected = "ACCEPT";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test4) {
    Automata a;
    a.on();
    a.coin(50);
    a.coin(20);
    int expected = 70;
    EXPECT_EQ(expected, a.getBalance());
}
