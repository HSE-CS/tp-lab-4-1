#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, test1)
{
	Automata newAutomata;
	int state = newAutomata.getState();
	EXPECT_EQ(0, state);
}

TEST(lab4, test2)
{
	Automata newAutomata;

	newAutomata.on();

	int state = newAutomata.getState();
	EXPECT_EQ(1, state);
}

TEST(lab4, test3)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.off();

	int state = newAutomata.getState();
	EXPECT_EQ(0, state);
}

TEST(lab4, test4)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(23);

	int state = newAutomata.getState();
	EXPECT_EQ(2, state);
}

TEST(lab4, test5)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(23);
	newAutomata.coin(34);
	newAutomata.coin(733);
	newAutomata.coin(594);
	newAutomata.coin(943);
	newAutomata.coin(3);

	int state = newAutomata.getState();
	EXPECT_EQ(2, state);
}

TEST(lab4, test6)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(23);
	newAutomata.choice(CAPPU);

	int state = newAutomata.getState();
	EXPECT_EQ(3, state);
}

TEST(lab4, test7)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(23);
	newAutomata.choice(CAPPU);
	newAutomata.check();

	int state = newAutomata.getState();
	EXPECT_EQ(2, state);
}

TEST(lab4, test8)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(50);
	newAutomata.choice(CAPPU);
	newAutomata.check();

	int state = newAutomata.getState();
	EXPECT_EQ(4, state);
}

TEST(lab4, test9)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(50);
	newAutomata.choice(CAPPU);
	newAutomata.check();
	newAutomata.cook();

	int state = newAutomata.getState();
	EXPECT_EQ(5, state);
}

TEST(lab4, test10)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(50);
	newAutomata.choice(CAPPU);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();

	int state = newAutomata.getState();
	EXPECT_EQ(1, state);
}

TEST(lab4, test11)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(100);
	newAutomata.choice(CAPPU);
	newAutomata.check();
	newAutomata.cook();
	int returned =  newAutomata.finish();

	EXPECT_EQ(55, returned);
}

TEST(lab4, test12)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(50);
	newAutomata.choice(CAPPU);

	newAutomata.cancel();

	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();

	int state = newAutomata.getState();
	EXPECT_EQ(1, state);
}

TEST(lab4, test13)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(50);
	newAutomata.choice(CAPPU);

	newAutomata.off();

	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();

	int state = newAutomata.getState();
	EXPECT_EQ(1, state);
}

TEST(lab4, test14)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(50);
	newAutomata.choice(CAPPU);

	newAutomata.cancel();
	newAutomata.off();

	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();

	int state = newAutomata.getState();
	EXPECT_EQ(0, state);
}

TEST(lab4, test15)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.coin(25);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(LATTE);
	newAutomata.check();
	newAutomata.choice(ESPRS);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	int state = newAutomata.getKeptSum();
	EXPECT_EQ(80, state);
}

TEST(lab4, test16)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.coin(25);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	newAutomata.coin(30);
	newAutomata.choice(LATTE);
	newAutomata.check();
	newAutomata.choice(ESPRS);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	int state = newAutomata.getKeptSum();
	EXPECT_EQ(50, state);
}

TEST(lab4, test17)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.coin(25);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(LATTE);
	newAutomata.check();
	newAutomata.choice(ESPRS);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(LATTE);
	newAutomata.check();
	newAutomata.cancel();
	newAutomata.off();

	int state = newAutomata.getKeptSum();
	EXPECT_EQ(80, state);
}

TEST(lab4, test18)
{
	Automata newAutomata;

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.coin(25);
	newAutomata.choice(HOTCH);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(LATTE);
	newAutomata.check();
	newAutomata.choice(ESPRS);
	newAutomata.check();
	newAutomata.cook();
	newAutomata.finish();
	newAutomata.off();

	newAutomata.on();
	newAutomata.coin(30);
	newAutomata.choice(LATTE);
	newAutomata.check();
	int returned = newAutomata.cancel();
	newAutomata.off();

	EXPECT_EQ(30, state);
}