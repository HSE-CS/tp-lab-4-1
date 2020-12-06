// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(Automata, test_on) {
	Automata automata;
	automata.on();
	EXPECT_EQ(WAIT, automata.getState());
}

TEST(Automata, test_off) {
	Automata automata;
	automata.on();
	automata.off();
	EXPECT_EQ(OFF, automata.getState());
}

TEST(Automata, test_coin) {
	Automata automata;
	automata.on();
	automata.coin(10);
	EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(Automata, test_choice) {
	Automata automata;
    	automata.on();
	automata.coin(40);
	automata.choice(1);
	EXPECT_EQ(WAIT, automata.getState());
}

TEST(Automata, test_finish) {
	Automata automata;
	automata.on();
	automata.coin(50);
	automata.choice(1);
	automata.finish();
	EXPECT_EQ(WAIT, automata.getState());
}

TEST(Automata, test_cancel) {
    	Automata automata;
    	automata.cancel();
    	EXPECT_EQ(0, automata.getState());
}
