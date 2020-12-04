#include "Automata.h"

#include <gtest/gtest.h>
#include <string>

TEST(AutomataTest, test1) {
	Automata a;
	EXPECT_EQ(OFF, a.getState());
}

TEST(AutomataTest, test2) {
	Automata a;
	a.on()
	EXPECT_EQ(ON, a.getState());
}

TEST(AutomataTest, test3) {
	Automata a;
  a.on();
	a.coin(50);
	a.choice("cocoa");
	EXPECT_EQ(true, a.check());
}

TEST(AutomataTest, test4) {
	Automata a;
  a.on();
  a.coin(10);
  a.choice("black tea");
  EXPECT_EQ(false, a.check());
}

TEST(AutomataTest, test5) {
	Automata a;
  a.on();
  a.coin(10);
  a.choice("coffee");
  a.cancel(); 
  EXPECT_EQ(WAIT, a.getStatus());
}

TEST(AutomataTest, test6) {
	Automata a;
  a.on();
  a.coin(100);
  a.choice("green tea");
  a.check();
  a.cook();  
  a.finish();
  EXPECT_EQ(WAIT, a.getStatus());
}

TEST(AutomataTest, test7) {
	Automata a;
  a.on();
  a.coin(100);
  EXPECT_EQ(ACCEPT, a.getStatus());
}

TEST(AutomataTest, test8) {
	Automata a;
  a.on();
  a.coin(100);
  a.choice("latte");
  a.check();
  a.cook();  
  EXPECT_EQ(COOK, a.getStatus());
}

TEST(AutomataTest, test9) {
	Automata a;
  a.on();
  a.coin(5);
  a.coin(5);
  a.coin(5);
  EXPECT_EQ(ACCEPT, a.getStatus());
}

TEST(AutomataTest, test10) {
	Automata a;
  a.on();
  a.coin(5);
  a.coin(5);
  a.coin(5);
  EXPECT_EQ(ACCEPT, a.getStatus());
}

TEST(AutomataTest, test11) {
	Automata a;
  EXPECT_EQ(a.getMenu(), "coffee -> 40\n"\
		                   "cocao -> 45\n" \
		                   "latte -> 50\n" \
		                   "black tea -> 30\n"\
		                   "green tea -> 35\n");
}
