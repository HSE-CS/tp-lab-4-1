#include <gtest/gtest.h>
#include "Automata.h"
TEST(automata, test1) {
	AUTOMATA a;
	EXPECT_EQ(OFF, a.getState());
}

TEST(automata, test2) {
	AUTOMATA a;
	a.on();
	EXPECT_EQ(WAIT, a.getState());
}

TEST(automata, test3) {
	AUTOMATA a;
	a.on();
	a.cancel();
	EXPECT_EQ(a.getState(), WAIT);
}

TEST(automata, test4) {
	AUTOMATA a;
	a.on();
	a.coin(10.2);
	a.cancel();
	EXPECT_EQ(0, a.getCash());
}

TEST(automata, test5) {
	AUTOMATA a;
	a.on();
	a.coin(10);
	a.cancel();
	a.off();
	EXPECT_EQ(OFF, a.getState());
}

TEST(automata, test6) {
	AUTOMATA a;
	a.on();
	a.coin(10.2);
	EXPECT_EQ(ACCEPT, a.getState());
}

TEST(automata, test7) {
	AUTOMATA a;
	a.on();
	a.coin(30);
	a.choice(5);
	EXPECT_EQ(a.getState(), WAIT);
}

TEST(automata, test8) {
	AUTOMATA a;
	a.cancel();
	EXPECT_EQ(a.getState(), OFF);
}

TEST(automata, test9) {
	AUTOMATA a;
	a.on();
	a.coin(6.1);
	a.choice(5);
	EXPECT_EQ(ACCEPT, a.getState());
}

TEST(automata, test10) {
	AUTOMATA a;
	a.on();
	a.coin(30);
	a.cancel();
	EXPECT_EQ(a.getState(), WAIT);
}