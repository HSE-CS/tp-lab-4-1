// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST (AutomataTest, test1) {
    Automata c;
    EXPECT_STREQ("off", c.getState());
}

TEST (AutomataTest, testOn1) {
    Automata c;
    c.on();
    EXPECT_STREQ("wait", c.getState());
}

TEST (Automata, testOn2) {
    Automata c;
    c.on();
    c.coin(3.0);
    EXPECT_STREQ("accept", c.getState());
}

TEST (Automata, testOff1) {
    Automata c;
    c.on();
    c.coin(5.0);
    c.off();
    EXPECT_STREQ("accept", c.getState());
    c.cancel();
    EXPECT_EQ(5.0, c.getReminder());
    c.off();
    EXPECT_STREQ("off", c.getState());
}

TEST (Automata, testCoin1) {
    Automata c;
    c.on();
    c.coin(50.0);
    EXPECT_EQ(50.0, c.getReminder());
}

TEST (Automata, testCoin2) {
    Automata c;
    c.on();
    c.coin(50.0);
    c.coin(45.0);
    EXPECT_EQ(95.0, c.getReminder());
}

TEST (Automata, testMenu1) {
    Automata c;
    c.on();
    std::vector<std::string> menu{
        "Tea",
        "Cappuccino",
        "Americano",
        "Latte",
        "Cocoa",
        "Hot milk",
    };
    c.coin(10.0);
    c.choice(menu.at(0));
    EXPECT_STREQ("wait", c.getState());
    EXPECT_EQ(0.0, c.getReminder());
}


TEST (Automata, testMenu2) {
    Automata c;
    std::vector<std::string> menu{
        "Tea",
        "Cappuccino",
        "Americano",
        "Latte",
        "Cocoa",
        "Hot milk",
    };
    c.on();
    c.coin(2.0);
    c.choice(menu.at(3));
    EXPECT_STREQ("wait", c.getState());
    EXPECT_EQ(2.0, c.getReminder());
}

TEST (Automata, testCancel1) {
    Automata c;
    c.cancel();
    EXPECT_STREQ("off", c.getState());
}

TEST (Automata, testCancel2) {
    Automata c;
    c.on();
    c.coin(50.0);
    c.cancel();
    EXPECT_STREQ("wait", c.getState());
    EXPECT_EQ(50.0, c.getReminder());
}

TEST (Automata, testAll1) {
    Automata c;
    c.on();
    c.coin(50.0);
    std::vector<std::string> _menu = c.getMenu();
    c.choice(_menu.at(0));
    EXPECT_STREQ("wait", c.getState());
    EXPECT_EQ(40.0, c.getReminder());
    c.off();
    EXPECT_STREQ("off", c.getReminder());
    EXPECT_EQ(0.0, c.getReminder());
}

TEST (Automata, testAll2) {
    Automata c;
    c.on();
    c.coin(5.0);
    std::vector<std::string> _menu = c.getMenu();
    c.choice(_menu.at(2));
    EXPECT_STREQ("wait", c.getState());
    EXPECT_EQ(5.0, c.getReminder());
    c.coin(80);
    c.choice(_menu.at(5));
    EXPECT_STREQ("wait", c.getState());
    EXPECT_EQ(40.0, c.getReminder());
    c.off();
    EXPECT_STREQ("off", c.getReminder());
}
