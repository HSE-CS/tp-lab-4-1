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
    test.cook();
    test.finish();
    EXPECT_EQ(WAIT, test.getState());
}