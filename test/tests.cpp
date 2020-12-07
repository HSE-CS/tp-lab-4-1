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
	a.coin(20);
	EXPECT_EQ(ACCEPT, a.getState());
}

TEST(automata_test, test4)
{
	Automata a;
	a.on();
	a.coin(50);
	a.choice(3);
	EXPECT_EQ(WAIT, a.getState());
}


