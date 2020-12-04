#include "Automata.h"

#include "gtest/gtest.h"
#include <string>

TEST(AutomataTest, test1) {
	Automata a;
	int st = a.getState();
	EXPECT_EQ(0, st);
}

TEST(AutomataTest, test2) {
	Automata a;
	a.on();
	int st = a.getState();
	EXPECT_EQ(1, st);
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
	int st = a.getState();
    EXPECT_EQ(1, st);
}

TEST(AutomataTest, test6) {
	Automata a;
    a.on();
    a.coin(100);
    a.choice("green tea");
    a.check();
    a.cook();  
    a.finish();
	int st = a.getState();
    EXPECT_EQ(1, st);
}

TEST(AutomataTest, test7) {
	Automata a;
    a.on();
    a.coin(100);
	int st = a.getState();
    EXPECT_EQ(2, st);
}

TEST(AutomataTest, test8) {
	Automata a;
    a.on();
    a.coin(100);
    a.choice("latte");
    a.check();
    a.cook();  
	int st = a.getState();
    EXPECT_EQ(4, st);
}

TEST(AutomataTest, test9) {
	Automata a;
    a.on();
    a.coin(5);
    a.coin(5);
    a.coin(5);
	int st = a.getState();
    EXPECT_EQ(2, st);
}

TEST(AutomataTest, test10) {
	Automata a;
    a.on();
    a.coin(5);
    a.coin(5);
    a.coin(5);
	int st = a.getState();
    EXPECT_EQ(2, st);
}

TEST(AutomataTest, test11) {
	Automata a;
    EXPECT_EQ(a.getMenu(), "Error, automata is off\n");
}
