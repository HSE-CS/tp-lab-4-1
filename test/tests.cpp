#include <gtest/gtest.h>

#include "Automata.h"

const std::map<std::string, int> MENU = {
    {"Coffee", 50},
    {"Milk", 35},
    {"Water", 20},
    {"Lemonade", 25},
    {"Juice", 30}
};


TEST(automata, test1) {
    Automata test;
    EXPECT_EQ(OFF, test.getState());
}

TEST(automata, test2) {
    Automata test;
    test.on();
    EXPECT_EQ(WAIT, test.getState());
}

TEST(automata, test3) {
    Automata test;
    test.on();
    test.coin(100);
    EXPECT_EQ(ACCEPT, test.getState());
}
TEST(automata, test4) {
    Automata test;
    test.on();
    test.coin(35);
    test.choice("Milk");
    test.check();
    EXPECT_EQ(CHECK, test.getState());
}
TEST(automata, test5) {
    Automata test;
    test.on();
    test.coin(20);
    test.choice("Lemon tea");
    test.check();
    test.cook();
    EXPECT_EQ(COOK, test.getState());
}
TEST(automata, test6) {
    Automata test;
    test.on();
    test.coin(100);
    test.cancel();
    EXPECT_EQ(WAIT, test.getState());
}
TEST(automata, test7) {
    Automata test;
    test.on();
    test.coin(100);
    test.choice("juice");
    test.check();
    EXPECT_EQ(ACCEPT, test.getState());
}
TEST(automata, test8) {
    Automata test;
    test.on();
    test.coin(70);
    test.choice("Water");
    test.check();
    test.cook();
    EXPECT_EQ(COOK, test.getState());
}