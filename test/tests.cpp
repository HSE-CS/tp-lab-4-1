#include <gtest/gtest.h>
#include "Automata.h"


TEST(automata, test1) {
	Automata a;
	a.on();
	STATES expected = WAIT;
	EXPECT_EQ(expected, a.getState());
}

TEST(automata, test2) {
	Automata a;
	a.coin(30);
	a.choice(2);
	a.cancel();
	int expected = 1;
	EXPECT_EQ(expected, a.off());
}

TEST(automata, test3) {
	Automata a;
	STATES expected = OFF;
	EXPECT_EQ(expected, a.getState());
}

TEST(automata, test4) {
	Automata a;
	a.on();
	a.coin(20);
	double expected = 20;
	EXPECT_EQ(expected, a.getCash());
}

TEST(automata, test5) {
	Automata a;
	a.on();
	a.coin(20);
	a.choice(1);
	STATES expected = CHECK;
	EXPECT_EQ(expected, a.getState());
}

TEST(automata, test6) {
	Automata a;
	a.on();
	a.coin(20);
	a.choice(1);
	double expected = 0;
	EXPECT_EQ(expected, a.getCash());
}

TEST(automata, test7) {
	Automata a;
	a.on();
	a.coin(20);
	a.choice(1);
	a.cancel();
	STATES expected = WAIT;
	EXPECT_EQ(expected, a.getState());
}

TEST(automata, test8) {
	Automata a;
	a.choice(2);
	STATES expected = OFF;
	EXPECT_EQ(expected, a.getState());
}

TEST(automata, test9) {
	Automata a;
	a.on();
	a.coin(50);
	STATES expected = ACCEPT;
	EXPECT_EQ(expected, a.getState());
}