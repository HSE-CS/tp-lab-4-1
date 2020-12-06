// Copyright 2020 Drobot Elizaveta
#include "gtest/gtest.h"
#include "automata.h"

TEST(automataTest, test1) {
	automata example;
	int st = example.printState();
	EXPECT_EQ(st, off_automat);
}

TEST(automataTest, test2) {
	automata example;
	example.on();
	int st = example.printState();
	EXPECT_EQ(st, on_automat);
}

TEST(automataTest, test3) {
	automata example;
	example.on();
	example.coin(2);
	example.cancel();
	int st = example.printState();
	EXPECT_EQ(st, off_automat);
}

TEST(automataTest, test4) {
	automata example;
	example.coin(2);
	example.choice(12);
	bool st = example.check(12);
	EXPECT_EQ(st, false);
}

TEST(automataTest, test5) {
	automata example;
	example.coin(100);
	example.choice(12);
	bool st = example.check(12);
	EXPECT_EQ(st, true);
}

TEST(automataTest, test6) {
	automata example;
	example.coin(1);
	example.cancel();
	int st = example.printState();
	EXPECT_EQ(st, off_automat);
}

TEST(automataTest, test7) {
	automata example;
	example.coin(10);
	example.coin(10);
	example.coin(10);
	example.choice(10);
	int st = example.printState();
	EXPECT_EQ(st, off_automat);
}
