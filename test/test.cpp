#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataON, Test1) {
	Automata a;
	a.on();
	ASSERT_EQ(1, a.getState());
}
TEST(AutomataON, Test2) {
	Automata a;
	a.choice(1);
	ASSERT_NE(1, a.getState());
}
TEST(Automata_CHOIS, Test1) {
	Automata a;
	a.on();
	a.choice(1);
	ASSERT_EQ(2, a.getState());
}
TEST(Automata_CHOIS, Test2) {
	Automata a;
	a.on();
	a.cook();
	ASSERT_NE(2, a.getState());
}
TEST(Automata_COIN,Test1){
	Automata a;
	a.on();
	a.choice(1);
	a.coin(10);
	ASSERT_EQ(10,a.getCash());
}
TEST(Automata_COIN, Test2) {
	Automata a;
	a.on();
	a.choice(1);
	a.coin(-19);
	ASSERT_EQ(0, a.getCash());
}
TEST(Automata_CHECK, Test1) {
	Automata a;
	a.on();
	a.choice(1);
	a.coin(100);
	a.check();
	ASSERT_EQ(4, a.getState());
}
TEST(Automata_CHECK, Test2) {
	Automata a;
	a.on();
	a.choice(1);
	a.coin(1);
	ASSERT_EQ(false, a.check());
}
TEST(Automata_COOK, Test1) {
	Automata a;
	a.on();
	a.choice(1);
	a.coin(100);
	a.check();
	a.cook();
	ASSERT_EQ(5, a.getState());
}
TEST(Automata_COOK, Test2) {
	Automata a;
	a.on();
	a.choice(1);
	a.cook();
	ASSERT_NE(5, a.getState());
}
TEST(Automata_FINISH, Test1) {
	Automata a;
	a.on();
	a.choice(1);
	a.coin(100);
	a.check();
	a.cook();
	a.finish();
	ASSERT_EQ(1, a.getState());
}
TEST(Automata_FINISH, Test2) {
	Automata a;
	a.on();
	a.choice(0);
	a.coin(100);
	a.check();
	a.cook();
	ASSERT_EQ(50, a.finish());
}
int main(int argc, char *argv[])
{

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
