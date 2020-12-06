// Copyright 2020 Nikita Naumov
#include "gtest/gtest.h"
#include "Automata.h"

TEST(AutomataTest, test1) {
    Automata example;
    int st = example.getState();
    EXPECT_EQ(st, offline);
}

TEST(AutomataTest, test2) {
    Automata example;
    example.on();
    int st = example.getState();
    EXPECT_EQ(st, waiting);
}

TEST(AutomataTest, test3) {
    Automata example;
    std::string str = example.getMenu();
    EXPECT_EQ(str, "");
}

TEST(AutomataTest, test4) {
    Automata example;
    example.on();
    std::string strEq = "10 Latte 30\n11 Milk 25\n12 Black Tea 15\n13 Karkade 20\n14 Espresso 25\n";
    std::string str = example.getMenu();
    EXPECT_EQ(str, strEq);
}

TEST(AutomataTest, test5) {
    Automata example;
    example.on();
    example.coin();
    example.cancel();
    int st = example.getState();
    EXPECT_EQ(st, waiting);
}

TEST(AutomataTest, test6) {
    Automata example;
    example.coin(1);
    example.choice(10);
    bool st = example.check(10);
    EXPECT_EQ (st, false);
}

TEST(AutomataTest, test7) {
    Automata example;
    example.coin(1);
    example.cancel();
    int st = example.getState();
    EXPECT_EQ(st, waiting);
}

TEST(AutomataTest, test8) {
    Automata example;
    example.coin(10);
    example.coin(10);
    example.coin(10);
    example.choice(10);
    int st = example.getState();
    EXPECT_EQ (st, waiting);
}