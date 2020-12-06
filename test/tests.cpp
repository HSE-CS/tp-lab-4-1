// Copyright 2020 dash
#include <gtest/gtest.h>
#include "Automata.h"

TEST(aut_test, test1) {
	Automata a;
	a.on();
	STATES expect = WAIT;
	EXPECT_EQ(expect, a.getState());
}

TEST(aut_test, test2) {
	Automata b;
	STATES expect = OFF;
	EXPECT_EQ(expect, b.getState());
}

TEST(aut_test, test3) {
	Automata c;
	c.off();
	STATES expect = OFF;
	EXPECT_EQ(expect, c.getState());
}

TEST(aut_test, test4) {
	Automata d;
	d.on();
	d.coin(60);
	EXPECT_EQ(WAIT, d.getState());
}

TEST(aut_test, test5) {
	Automata e;
	e.on();
	e.coin(60);
	e.choice(2);
	STATES expect = WAIT;
	EXPECT_EQ(expect, e.getState());
}

TEST(aut_test, test6) {
	Automata f;
	f.on();
	f.coin(60);
	f.choice(2);
	f.check(2);
	STATES expect = WAIT;
	EXPECT_EQ(expect, f.getState());
}

TEST(aut_test, test7) {
	Automata g;
	g.on();
	g.coin(50);
	g.choice(7);
	g.check(7);
	g.cancel();
	STATES expect = WAIT;
	EXPECT_EQ(expect, g.getState());
}

TEST(aut_test, test8) {
	Automata h;
	h.choice(3);
	STATES expect = OFF;
	EXPECT_EQ(expect, h.getState());
}

TEST(aut_test, test9) {
	Automata k;
	k.coin(60);
	STATES expect = OFF;
	EXPECT_EQ(expect, k.getState());
}

TEST(aut_test, test10) {
	Automata m;
	m.coin(60);
	m.check(3);
	STATES expect = OFF;
	EXPECT_EQ(expect, m.getState());
}


