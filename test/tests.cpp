#include "gtest/gtest.h"

#include "../include/automataNoDialog.h"

TEST(on, on1)
{
	Automata automata("data.txt");
	STATES expect = STATES::WAIT;
	EXPECT_EQ(expect, automata.getState());
}
