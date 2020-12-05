// Copyright 2020 Lab_4 TiNa
#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
	Automata aut1;
	aut1.on();
	STATES expect = WAIT;
	EXPECT_EQ(expect, aut1.getState());
}

TEST(automata, test2) {
	Automata aut2;
	STATES expect = OFF;
	EXPECT_EQ(expect, aut2.getState());
}

TEST(automata, test3) {
	Automata aut3;
	aut3.off();
	STATES expect = OFF;
	EXPECT_EQ(expect, aut3.getState());
}

TEST(automata, test4) {
	Automata aut4;
	aut4.on();
	aut4.coin(100);
	STATES expect = WAIT;
	EXPECT_EQ(expect, aut4.getState());
}

TEST(automata, test5) {
	Automata aut5;
	aut5.on();
	aut5.coin(100);
	aut5.choice(7);
	STATES expect = WAIT;
	EXPECT_EQ(expect, aut5.getState());
}

TEST(automata, test6) {
	Automata aut6;
	aut6.on();
	aut6.coin(100);
	aut6.choice(7);
	aut6.check(7);
	STATES expect = WAIT;
	EXPECT_EQ(expect, aut6.getState());
}

TEST(automata, test7) {
	Automata aut7;
	aut7.on();
	aut7.coin(10);
	aut7.choice(7);
	aut7.check(7);
	aut7.cancel();
	STATES expect = WAIT;
	EXPECT_EQ(expect, aut7.getState());
}

TEST(automata, test8) {
	Automata aut8;
	aut8.choice(6);
	STATES expect = OFF;
	EXPECT_EQ(expect, aut8.getState());
}

TEST(automata, test9) {
	Automata aut9;
	aut9.coin(60);
	STATES expect = OFF;
	EXPECT_EQ(expect, aut9.getState());
}

TEST(automata, test10) {
	Automata aut10;
	aut10.coin(60);
	aut10.check(7);
	STATES expect = OFF;
	EXPECT_EQ(expect, aut10.getState());
}
