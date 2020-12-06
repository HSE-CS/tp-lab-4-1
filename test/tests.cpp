#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, on)
{
    Automata automata1;
    automata1.on();
    EXPECT_EQ(1, automata1.getState());
}
TEST(automata, off)
{
    Automata automata1;
    EXPECT_EQ(0, automata1.getState());
}
TEST(automata, coin)
{
    Automata automata1;
    automata1.on();
    automata1.coin(10);
    EXPECT_EQ(10, automata1.getCoin());
}
TEST(automata, coin2)
{
    Automata automata1;
    automata1.on();
    automata1.coin(10);
    automata1.coin(20);
    EXPECT_EQ(30, automata1.getCoin());
}

TEST(automata, coin3)
{
    Automata automata1;
    automata1.on();
    automata1.coin(10);
    EXPECT_EQ(2, automata1.getState());
}

TEST(automata, finish)
{
    Automata automata1;
    automata1.on();
    automata1.coin(10);
    automata1.finish();
    EXPECT_EQ(1, automata1.getState());
}

TEST(automata, choices)
{
    Automata automata1;
    automata1.on();
    automata1.coin(42);
    automata1.choice(2);
    EXPECT_EQ(22, automata1.getCoin());
}
