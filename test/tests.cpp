#include "Automata.h"
#include "gtest/gtest.h"

TEST(automata, test1) {
	Automata aut;
	EXPECT_EQ(OFF, aut.getState());
}

TEST(automata, test2) {
	Automata aut;
	aut.on();
	EXPECT_EQ(WAIT, aut.getState());
}

TEST(automata, test3) {
	Automata aut;
	aut.off();
	EXPECT_EQ(OFF, aut.getState());
}

TEST(automata, test4) {
	Automata aut;
	aut.on();
	aut.coin(10);
	EXPECT_EQ(ACCEPT, aut.getState());
}

TEST(automata, test5) {
	Automata aut;
	aut.on();
	aut.coin(10);
	aut.choice("hot water");
	EXPECT_EQ(CHECK, aut.getState());
}

TEST(automata, test6) {
	Automata aut;
	aut.on();
	aut.coin(10);
	aut.choice("hot water");
	aut.cook();
	EXPECT_EQ(COOK, aut.getState());
}

TEST(automata, test7) {
	Automata aut;
	aut.on();
	aut.coin(10);
	aut.choice("hot water");
	EXPECT_TRUE(aut.check());
}

TEST(automata, test8) {
	Automata aut;
	aut.on();
	aut.coin(5);
	aut.choice("hot water");
	EXPECT_FALSE(aut.check());
}

TEST(automata, test9) {
	Automata aut;
	aut.on();
	aut.coin(10);
	aut.choice("hot water");
	aut.check();
	EXPECT_EQ(CHECK, aut.getState());
}

TEST(automata, test10) {
	Automata aut;
	aut.on();
	aut.coin(10);
	aut.choice("hot water");
	aut.cancel();
	EXPECT_EQ(WAIT, aut.getState());
}

TEST(automata, test11) {
	Automata aut;
	aut.on();
	aut.coin(10);
	aut.choice("hot water");
	aut.cook();
	aut.finish();
	EXPECT_EQ(WAIT, aut.getState());
}
