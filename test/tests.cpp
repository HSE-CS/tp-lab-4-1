#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata_test, test1) 
{
	Automata a;
	EXPECT_EQ(OFF, a.getState());
}

TEST(automata_test, test2) 
{
	Automata a;
	a.on();
	EXPECT_EQ(WAIT, a.getState());
}

TEST(automata_test, test3) {
	Automata a;
	a.on();
	a.coin(10);
	EXPECT_EQ(ACCEPT, a.getState());
}

TEST(automata_test, test4) 
{
	Automata a;
	a.on();
	a.coin(50);
	a.choice(0);
	EXPECT_EQ(CHECK, a.getState());
}
TEST(automata_test, test5)
{
	Automata a;
	a.on();
	a.coin(5);
	a.choice(0);
	EXPECT_FALSE(a.check());
}
TEST(automata_test, test6)
{
	Automata a;
	a.on();
	a.coin(60);
	a.choice(5);
	EXPECT_TRUE(a.check());
}

