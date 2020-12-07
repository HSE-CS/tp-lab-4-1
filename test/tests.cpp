#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, automata_on_1) {
    Automata test;
    EXPECT_EQ(OFF, test.getState());
}

TEST(automata, automata_on_2) {
    Automata test("file.txt");
    EXPECT_EQ(OFF, test.getState());
}

TEST(automata, automata_coin_1) {
    Automata test;
    test.on();
    test.coin(0);
    STATES expect = STATES::WAIT;
    EXPECT_EQ(expect, test.getState());
}

TEST(automata, automata_coin_2) {
    Automata test("file.txt");
    test.on();
    test.coin(100);
    STATES expect = STATES::ACCEPT;
    EXPECT_EQ(expect, test.getState());
}

TEST(automata, automata_choice_1) {
    Automata test;
    test.on();
    test.coin(50);
    test.choice("latte");
    STATES expect = STATES::CHECK;
    EXPECT_EQ(expect, test.getState());
}

TEST(automata, automata_choice_2) {
    Automata test("file.txt");
    test.on();
    test.coin(50);
    test.choice("coffee");
    STATES expect = STATES::WAIT;
    EXPECT_EQ(expect, test.getState());
}

TEST(automata, automata_cook_1) {
    Automata test;
    test.on();
    test.coin(50);
    test.choice("latte");
    test.cook();
    STATES expect = STATES::COOK;
    EXPECT_EQ(expect, test.getState());
}

TEST(automata, automata_cook_2) {
    Automata test("file.txt");
    test.on();
    test.coin(50);
    test.choice("coffee");
    test.cook();
    STATES expect = STATES::WAIT;
    EXPECT_EQ(expect, test.getState());
}

TEST(automata, automata_finish_1) {
    Automata test("file.txt");
    test.on();
    test.coin(50);
    test.choice("latte");
    test.cook();
    test.finish();
    STATES expect = STATES::WAIT;
    EXPECT_EQ(expect, test.getState());
}

TEST(automata, automata_off_1) {
    Automata test("file.txt");
    test.on();
    test.coin(50);
    test.choice("latte");
    test.cook();
    test.finish();
    test.off();
    STATES expect = STATES::OFF;
    EXPECT_EQ(expect, test.getState());
}
