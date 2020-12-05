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

TEST(automata, test5) {
    Automata a;
    std::unordered_map<std::string, int> menu = {
            {"coffee", 200}, {"tea", 150},
            {"milk", 100},{"water", 50},
            {"cola", 175}};
    EXPECT_EQ(menu, a.getMenu());
}

TEST(automata, test6) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    std::string expected = "WAIT";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test7) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("coffee");
    std::string expected = "CHECK";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test8) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("coffee");
    a.cancel();
    std::string expected = "WAIT";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test9) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice("coffee");
    a.check();
    std::string expected = "ACCEPT";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test10) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("coffee");
    a.check();
    std::string expected = "CHECK";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test11) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("coffee");
    a.check();
    a.cook();
    std::string expected = "COOK";
    EXPECT_EQ(expected, a.getState());
}

TEST(automata, test12) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("coffee");
    a.check();
    a.cook();
    a.finish();
    std::string expected = "WAIT";
EXPECT_EQ(expected, a.getState());
}

TEST(automata, test13) {
    Automata a;
    a.on();
    a.coin(200);
    a.choice("coffee");
    a.check();
    a.cook();
    a.finish();
    a.off();
    std::string expected = "OFF";
    EXPECT_EQ(expected, a.getState());
}
