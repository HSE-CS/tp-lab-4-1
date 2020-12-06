#include <gtest/gtest.h>
#include "Automata.h"
TEST(lab4, test1)
{
Automata automata;
EXPECT_EQ(0, automata.getState());
}

TEST(lab4, test2)
{
Automata automata;
automata.on();
EXPECT_EQ(1, automata.getState());
}

TEST(lab4, test3)
{
Automata automata;
automata.on();
automata.coin(10);
EXPECT_EQ(2, automata.getState());
}

TEST(lab4, test4)
{
Automata automata;
automata.on();
automata.coin(10);
automata.cancel();
EXPECT_EQ(0, automata.getValue());
}

TEST(lab4, test5)
{
Automata automata;
automata.on();
automata.coin(10);
automata.choice("Double Hot Chocolate");
automata.cancel();
EXPECT_EQ(1, automata.getState());
}

TEST(lab4, test6)
{
Automata automata;
automata.on();
automata.choice("Tea");
EXPECT_EQ(1, automata.getState());
}
TEST(lab4, test7)
{
Automata automata;
automata.on();
automata.coin(80);
automata.choice("Premium Americano");
EXPECT_EQ(70, automata.getValue());
}

TEST(lab4, test8)
{
Automata automata;
automata.on();
automata.coin(80);
automata.choice("Premium Americano");
automata.coin(20);
automata.choice("Water");
EXPECT_EQ(90, automata.getValue());
}
TEST(lab4, test9)
{
Automata automata;
automata.on();
automata.coin(80);
automata.choice("Latte");
automata.coin(20);
automata.cancel();
automata.off();
automata.choice("Water");
EXPECT_EQ(0, automata.getState());
}



