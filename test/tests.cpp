#include <gtest/gtest.h>
#include "Automata.h"

TEST(Automata, on) {
    Automata automata;
    automata.on();
    EXPECT_EQ(automata.getState(), states::WAIT);
}

TEST(Automata, off) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), states::OFF);
}

TEST(Automata, coin) {
    Automata automata;
    automata.on();
    automata.coin(10);
    EXPECT_EQ(automata.getCash(), 10);
}

TEST(Automata, cancel) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.cancel();
    EXPECT_EQ(automata.getState(), states::WAIT);
}

TEST(Automata, choice) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice("coffee");
    EXPECT_EQ(automata.getCash(), 0);
}
