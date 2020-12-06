#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1)
{
	Automata a;
	EXPECT_EQ(States::OFF, a.getState());
}
TEST(automata, test2)
{
	Automata a;
	a.on();
	EXPECT_EQ(States::WAIT, a.getState());
}
TEST(automata, test3)
{
	Automata a;
	a.on();
	a.coin(35);
	EXPECT_EQ(States::ACCEPT, a.getState());
}
TEST(automata, test4)
{
	Automata a;
	a.on();
	a.coin(30);
	EXPECT_EQ(false, a.check(40));
}
TEST(automata, test5)
{
	Automata a;
	a.on();
	a.coin(30);
	EXPECT_EQ(true, a.check(25));
}
TEST(automata, test6)
{
	Automata a;
	a.on();
	a.coin(30);
	a.choise("Espresso");
	EXPECT_EQ(States::CHECK, a.getState());
}
TEST(automata, test7)
{
	Automata a;
	a.on();
	a.coin(30);
	a.choise("Americano");
	EXPECT_EQ(States::WAIT, a.getState());
}
TEST(automata, test8)
{
	Automata a;
	a.on();
	a.coin(30);
	a.cancel();
	EXPECT_EQ(States::WAIT, a.getState());
}
TEST(automata, test9)
{
	Automata a;
	a.on();
	a.coin(50);
	a.choise("Americano");
	a.cook();
	EXPECT_EQ(States::COOK, a.getState());
}
TEST(automata, test10)
{
	Automata a;
	a.on();
	a.coin(50);
	a.choise("Americano");
	a.cook();
	a.finish();
	EXPECT_EQ(States::WAIT, a.getState());
}
TEST(automata, test11)
{
	Automata a;
	a.on();
	a.coin(50);
	a.choise("Americano");
	a.cook();
	a.finish();
	a.off();
	EXPECT_EQ(States::OFF, a.getState());
}
TEST(automata, test12)
{
	Automata a;
	a.on();
	a.coin(5);
	a.coin(5);
	a.coin(5);
	a.coin(30);
	a.choise("Americano");
	a.cook();
	a.finish();
	a.off();
	EXPECT_EQ(States::OFF, a.getState());
}