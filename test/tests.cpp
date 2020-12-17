#include <gtest/gtest.h>
#include "Automata.h"

TEST (automata, test1)
{
    Automata automata;
    string state = automata.getState();
    EXPECT_EQ("OFF", state);
}

TEST (automata, test2)
{
    Automata automata;
    automata.on();
    string state = automata.getState();
    EXPECT_EQ("WAIT", state);
}

TEST (automata, test3)
{
    Automata automata;
    automata.on();
    automata.coin(500);
    string state = automata.getState();
    EXPECT_EQ("ACCEPT", state);
}

TEST (automata, test4)
{
    Automata automata;
    automata.on();
    automata.coin(500);
    automata.choice(2);
    string state = automata.getState();
    EXPECT_EQ("WAIT", state);
}

TEST (automata, test5)
{
    Automata automata;
    automata.coin(500);
    string state = automata.getState();
    EXPECT_EQ("OFF", state);
}

TEST (automata, test6)
{
    Automata automata;
    automata.choice(2);
    string state = automata.getState();
    EXPECT_EQ("OFF", state);
}

TEST (automata, test7)
{
    Automata automata;
    automata.on();
    automata.choice(2);
    string state = automata.getState();
    EXPECT_EQ("WAIT", state);
}