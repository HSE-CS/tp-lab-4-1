// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST (AutomataTest, test1) {
    Automata c;
    EXPECT_EQ("off", c.getState());
}

TEST (AutomataTest, testOn1) {
    Automata c;
    c.on();
    EXPECT_EQ("wait", c.getState());
}

TEST (Automata, testOn2) {
    Automata c;
    c.on();
    c.coin(3.0);
    EXPECT_EQ("accept", c.getState());
}

TEST (Automata, testOff1) {
    Automata c;
    c.on();
    c.coin(5.0);
    c.off();
    EXPECT_EQ("accept", c.getState());
    c.cancel();
    EXPECT_EQ(5.0, c.getReminder());
    c.off();
    EXPECT_EQ("off", c.getState());
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
    c.coin(45.0)
    EXPECT_EQ(95.0, c.getReminder());
}

TEST (Automata, testMenu1) {
    Automata c;
    EXPECT_EQ(std::vector<std::string>(), c.getMenu());
}

TEST (Automata, testMenu2) {
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
    EXPECT_EQ(menu, c.getMenu());
}

TEST (Automata, testPrices1) {
    Automata c;
    EXPECT_EQ(std::map<std::string, double>(), c.getPriece());
}

TEST (Automata, testPrices2) {
    Automata c;
    std::map<std::string, double> prices{
        std::make_pair("Tea", 10.0),
        std::make_pair("Cappuccino", 30.0),
        std::make_pair("Americano", 35.0),
        std::make_pair("Latte", 20.0),
        std::make_pair("Cocoa", 10.0),
        std::make_pair("Hot milk", 45.0)
    };
    c.on();
    c.coin(2.0);
    c.choice("tea");
    EXPECT_EQ("wait", c.getState());
    EXPECT_EQ(prices, c.getPriece());
}

TEST (Automata, testCancel1) {
    Automata c;
    c.cancel();
    EXPECT_EQ("off", c.getState());
}

TEST (Automata, testCancel2) {
    Automata c;
    c.on();
    c.coin(50.0);
    c.cancel();
    EXPECT_EQ("wait", c.getState());
    EXPECT_EQ(50.0, c.getReminder());
}

TEST (Automata, testAll1) {
    Automata c;
    c.on();
    c.coin(50.0);
    std::vector<std::string> _menu = c.getMenu();
    c.choice(_menu.at(0));
    EXPECT_EQ("wait", c.getState());
    EXPECT_EQ(40.0, c.getReminder());
    c.off();
    EXPECT_EQ("off", c.getReminder());
    EXPECT_EQ(0.0, c.getReminder());
}

TEST (Automata, testAll2) {
    Automata c;
    c.on();
    c.coin(5.0);
    std::vector<std::string> _menu = c.getMenu();
    c.choice(_menu.at(2));
    EXPECT_EQ("wait", c.getState());
    EXPECT_EQ(5.0, c.getReminder());
    c.coin(80);
    c.choice(_menu.at(5));
    EXPECT_EQ("wait", c.getState());
    EXPECT_EQ(40.0, c.getReminder());
    c.off();
    EXPECT_EQ("off", c.getReminder());
}
