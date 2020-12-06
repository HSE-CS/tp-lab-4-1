#include <gtest/gtest.h>
#include "Automata.h"

TEST(Automata, test1)
{
    Automata atom;
    STATES expected=OFF;
    EXPECT_EQ(expected, atom.getState());
}

TEST(Automata, test2)
{
    Automata atom;
    atom.on();
    STATES expected=WAIT;
    EXPECT_EQ(expected, atom.getState());
}

TEST(Automata, test3)
{
    Automata atom;
    atom.coin(20);
    STATES expected=ACCEPT;
    EXPECT_EQ(expected, atom.getState());
}

TEST(Automata, test4)
{
    Automata atom;
    atom.on();
    atom.coin(100);
    atom.choice(2);
    STATES expected=WAIT;
    EXPECT_EQ(expected, atom.getState());
}

TEST(Automata, test5)
{
    Automata atom;
    atom.on();
    string expected="tea 40\nmilk 50\ncoffee 90\nchocolate 75";
    EXPECT_EQ(expected, atom.getMenu());
}

TEST(Automata, test6)
{
    Automata atom;
    atom.off();
    STATES expected=OFF;
    EXPECT_EQ(expected, atom.getState());
}

TEST(Automata, test7)
{
    Automata atom;
    atom.on();
    atom.coin(100);
    atom.choice(3);
    STATES expected = WAIT;
    EXPECT_EQ(expected, atom.getState());
}

TEST(Automata, test8)
{
    Automata atom;
    atom.choice(3);
    STATES expected = OFF;
    EXPECT_EQ(expected, atom.getState());
}

TEST(Automata, test9)
{
    Automata atom;
    atom.on();
    atom.coin(100);
    atom.cancel();
    STATES expected = WAIT;
    EXPECT_EQ(expected, atom.getState());
}


