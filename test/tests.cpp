#include "Automata.h"
#include "gtest/gtest.h"

TEST(automata, test1) {
	Automata tst;
	EXPECT_EQ(OFF, aut.getState());
}

TEST(automata, test2) {
	Automata tst;
	tst.on();
	EXPECT_EQ(WAIT, tst.getState());
}

TEST(automata, test3) {
	Automata tst;
	tst.off();
	EXPECT_EQ(OFF, tst.getState());
}

TEST(automata, test4) {
	Automata tst;
	tst.on();
	tst.coin(10);
	EXPECT_EQ(ACCEPT, tst.getState());
}

TEST(automata, test5) {
	Automata tst;
	tst.on();
	tst.coin(20);
	tst.choice("tea");
	EXPECT_EQ(CHECK, tst.getState());
}

TEST(automata, test6) {
	Automata tst;
	tst.on();
	tst.coin(10);
	tst.choice("");
	tst.cook();
	EXPECT_EQ(COOK, tst.getState());
}

TEST(automata, test7) {
	Automata tst;
	tst.on();
	tst.coin(30);
	tst.choice("Capuccino");
	EXPECT_TRUE(tst.check());
}

TEST(automata, test8) {
	Automata tst;
	tst.on();
	tst.coin(100);
	tst.choice("Kumis");
	EXPECT_FALSE(tst.check());
}


