// Copyright 2020 Drobot Elizaveta
#include "gtest/gtest.h"
#include "Automata.h"

TEST(AutomataTest, test1) {
	Automata example;
	int st = example.printState();
	EXPECT_EQ(st, off_automat);
}

TEST(AutomataTest, test2) {
	Automata example;
	example.on();
	int st = example.printState();
	EXPECT_EQ(st, on_automat);
}

TEST(AutomataTest, test3) {
	Automata example;
	example.on();
	example.coin(2);
	example.cancel();
	int st = example.printState();
	EXPECT_EQ(st, off_automat);
}

TEST(AutomataTest, test4) {
	Automata example;
	example.coin(2);
	example.choice(12);
	bool st = example.check(12);
	EXPECT_EQ(st, false);
}

TEST(AutomataTest, test5) {
	Automata example;
	example.coin(100);
	bool st = example.choice(12);
	EXPECT_EQ(st, true);
}

TEST(AutomataTest, test6) {
	Automata example;
	example.coin(1);
	example.cancel();
	int st = example.printState();
	EXPECT_EQ(st, off_automat);
}

TEST(AutomataTest, test7) {
	Automata example;
	example.coin(10);
	example.coin(10);
	example.coin(10);
	example.coin(10);
	bool st = example.choice(10);
	EXPECT_EQ(st, true);
}
