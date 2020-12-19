#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, automata_1)
{
	Automata atm;
	atm.on();
	atm.coin(100);
	bool flag = atm.check(0);
	EXPECT_EQ(flag, true);
}

TEST(lab4, automata_2)
{
	Automata atm;
	atm.on();
	atm.coin(10);
	bool flag = atm.check(3);
	EXPECT_EQ(flag, false);
}

TEST(lab4, automata_3)
{
	Automata atm;
	atm.on();
	atm.coin(100);
	int change = atm.finish();
	EXPECT_EQ(change, -1);
}

TEST(lab4, automata_4)
{
	Automata atm;
	atm.on();
	atm.coin(100);
	atm.choice(0);
	int change = atm.finish();
	EXPECT_EQ(change, 90);
}

TEST(lab4, automata_5)
{
	Automata atm;
	atm.on();
	string state = atm.printState();
	EXPECT_EQ(state, "WAIT");
}