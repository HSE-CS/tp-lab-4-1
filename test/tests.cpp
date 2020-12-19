#include <gtest/gtest.h>
#include "Automata.h"

TEST(Automata, test1) {
	Automata tst;
	tst.on();
	EXPECT_EQ(WAIT, tst.getState());
}

TEST(Automata, test2) {
	Automata tst;
	tst.on();
	tst.off();
	EXPECT_EQ(OFF, tst.getState());
}

TEST(Automata, test3) {
	Automata tst;
	tst.on();
	tst.coin(123);
	EXPECT_EQ(ACCEPT, tst.getState());
}

TEST(Automata, test4) {
	Automata tst;
	tst.on();
	tst.coin(300);
	tst.choice(1);
	EXPECT_EQ(COOK, tst.getState());
}

TEST(Automata, test5) {
	Automata tst;
	tst.on();
	tst.coin(50);
	tst.choice(3);
	tst.finish();
	EXPECT_EQ(WAIT, tst.getState());
}