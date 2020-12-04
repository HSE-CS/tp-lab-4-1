/*#include "gtest/gtest.h"
#include "Automata.h"

TEST(automata, on)
{
    Automata automata1;
    std::string expect = "WAIT";
    EXPECT_EQ(expect, automata1.getState());
}
TEST(automata, off)
{
    Automata automata1;
    std::string expect = "OFF";
    EXPECT_EQ(expect, automata1.getState());
}
TEST(automata, coin)
{
    Automata automata1;
    automata1.coin(10);
    EXPECT_EQ(10, automata1.getCoin());
}
TEST(automata, coin2)
{
    Automata automata1;
    automata1.coin(10);
    automata1.coin(20);
    EXPECT_EQ(30, automata1.getCoin());
}
TEST(automata, menu)
{
    string menu[3] = { "coffee", "tea", "milk" };
    int prices[3] = { 10, 15, 20 };
    Automata automata1(menu, prices);
    EXPECT_EQ(menu, automata1.getMenu());
}
TEST(automata, choice)
{
    string menu[3] = { "coffee", "tea", "milk" };
    int prices[3] = { 10, 15, 20 };
    Automata automata1(menu, prices);
    automata1.choice("tea");
    std::string expect = "WAIT";
    EXPECT_EQ(expect, automata1.getState());
}
TEST(automata, coin3)
{
    string menu[3] = { "coffee", "tea", "milk" };
    int prices[3] = { 10, 15, 20 };
    Automata automata1(menu, prices);
    automata1.coin(10);
    std::string expect = "ACCEPT";
    EXPECT_EQ(expect, automata1.getState());
}*/