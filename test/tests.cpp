#include "gtest/gtest.h"

#include "../include/automataNoDialog.h"

TEST(on, on1)
{
	Automata automata("data.txt");
	STATES expect = STATES::OFF;
	EXPECT_EQ(expect, automata.getState());
}

TEST(on, on2)
{
	Automata automata("data.txt");
	automata.on();
	STATES expect = STATES::WAIT;
	EXPECT_EQ(expect, automata.getState());
}

TEST(coin, coin1)
{
	Automata automata("data.txt");
	automata.on();
	automata.coin(1);
	STATES expect = STATES::ACCEPT;
	EXPECT_EQ(expect, automata.getState());
}

TEST(choice, choice1)
{
	Automata automata("data.txt");
	automata.on();
	automata.coin(1);
	int expect = -1;
	EXPECT_EQ(expect, automata.choice(0));
}

TEST(choice, choice2)
{
	Automata automata("data.txt");
	automata.on();
	automata.coin(200);
	int expect = 0;
	EXPECT_EQ(expect, automata.choice(0));
}

TEST(choice, check1)
{
	Automata automata("data.txt");
	automata.on();
	automata.coin(200);
	int expect = STATES::CHECK;
	automata.check(0);
	EXPECT_EQ(expect, automata.getState());
}