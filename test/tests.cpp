#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, test1)
{
    Automata machine;
    machine.on();
    int i = machine.getState();
    EXPECT_EQ(1, i);
}

TEST(lab4, test2)
{
    Automata machine;
    machine.on();
    machine.coin(60);
    int i = machine.getState();
    EXPECT_EQ(2, i);
}

TEST(lab4, test3)
{
    Automata machine;
    machine.on();
    machine.coin(60);
    machine.choice(10);
    int i = machine.getState();
    EXPECT_EQ(1, i);
}

TEST(lab4, test4)
{
    Automata machine;
    machine.on();
    machine.coin(65);
    machine.choice(10);
    machine.cook();
    double i = machine.getCash();
    EXPECT_EQ(65, i);
}

TEST(lab4, test5)
{
    Automata machine;
    machine.on();
    machine.coin(65);
    machine.cancel();
    machine.off();
    int i = machine.getState();
    EXPECT_EQ(0, i);
}

TEST(lab4, test6)
{
    Automata machine;
    machine.on();
    machine.coin(65);
    machine.choice(10);
    machine.cancel();
    double i = machine.getCash();
    EXPECT_EQ(0, i);
}

TEST(lab4, test7)
{
    Automata machine;
    machine.on();
    machine.coin(65);
    machine.choice(10);
    int i = machine.getState();
    EXPECT_EQ(2, i);
}

TEST(lab4, test8)
{
    Automata machine;
    machine.on();
    machine.coin(65);
    machine.choice(10);
    machine.cook();
    machine.coin(60);
    machine.choice(1);
    machine.cook();
    double i = machine.getCash();
    EXPECT_EQ(120, i);

}

TEST(lab4, test9)
{
    Automata machine;
    machine.on();
    machine.coin(10);
    machine.choice(10);
    machine.coin(100);
    machine.choice(10);
    int i = machine.getState();
    machine.cook();
    machine.off();
    EXPECT_EQ(2, i);
}

TEST(lab4, test10)
{
    Automata machine;
    int i = machine.getState();
    EXPECT_EQ(0, i);
}
