#include <gtest/gtest.h>
#include "Automata.h"

TEST(test_off, test1)
{
    Automata A;
    EXPECT_EQ(OFF, A.getState());
}

TEST(test_on, test2)
{
    Automata A;
    A.on();
    EXPECT_EQ(WAIT, A.getState());
}

TEST(test_coin, test3)
{
    Automata A;
    A.on();
    A.coin(5);
    EXPECT_EQ(ACCEPT, A.getState());
}

TEST(test_cancel, test4)
{
    Automata A;
    A.on();
    A.coin(3);
    EXPECT_EQ(3, A.cancel());
}

TEST(test_cancel, test5)
{
    Automata A;
    A.on();
    EXPECT_EQ(-1, A.cancel());
}

TEST(test_cancdrink, test6)
{
    Automata A;
    A.on();
    A.coin(20);
    EXPECT_EQ(20, A.choice("milk"));
}

TEST(test_drink, test7)
{
    Automata A;
    A.on();
    A.coin(13);
    EXPECT_EQ(3, A.choice("hot water"));
}

TEST(test_drink, test8)
{
  Automata A;
  A.on();
  A.coin(15);
  A.coin(50);
  EXPECT_EQ(30, A.choice("americano"));
  EXPECT_TRUE(A.takeDrink() == "americano");
}

TEST(test_drink, test9)
{
  Automata A;
  A.on();
  A.coin(15);
  A.coin(50);
  EXPECT_EQ(25, A.choice("hot chocolate"));
  EXPECT_TRUE(A.takeDrink() == "hot chocolate");
  EXPECT_EQ(WAIT, A.getState());
}

TEST(test_no_drink, test10)
{
  Automata A;
  A.on();
  A.coin(15);
  A.coin(50);
  EXPECT_EQ(43, A.choice("milk"));
  EXPECT_TRUE(A.takeDrink() == "milk");
  EXPECT_EQ(WAIT, A.getState());
  EXPECT_TRUE(A.takeDrink() == "None");
}

TEST(test_no_drink, test11)
{
  Automata A;
  EXPECT_TRUE(A.takeDrink() == "None");
  EXPECT_EQ(OFF, A.getState());
}

TEST(test_no_drink, test12)
{
  Automata A;
  A.on();
  A.coin(15);
  A.coin(33);
  EXPECT_EQ(48, A.cancel());
  EXPECT_EQ(WAIT, A.getState());
  EXPECT_TRUE(A.takeDrink() == "None");
}









