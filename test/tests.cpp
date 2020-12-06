// Copyright 2020 mkhorosh
#include "gtest/gtest.h"
#include "Automata.h"
#include <string>

TEST(AutomataTest, constractor){
Automata Coffee;
std::string expect = "OFF";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, on){
Automata Coffee;
Coffee.on();
std::string expect = "WAIT";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, off){
Automata Coffee;
Coffee.on();
Coffee.off();
std::string expect = "OFF";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test1){
Automata Coffee;
Coffee.on();
Coffee.coin(100);
std::string expect = "ACCEPT";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test2){
Automata Coffee;
Coffee.on();
Coffee.coin(100);
Coffee.cancel();
std::string expect = "WAIT";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test3){
Automata Coffee;
Coffee.on();
Coffee.coin(200);
Coffee.choice("late latte");
std::string expect = "WAIT";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test4){
Automata Coffee;
Coffee.on();
Coffee.coin(100);
Coffee.choice("late latte");
std::string expect = "CHECK";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test5){
Automata Coffee;
Coffee.on();
Coffee.coin(100);
Coffee.choice("late latte");
Coffee.cancel();
std::string expect = "WAIT";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test6){
Automata Coffee;
Coffee.on();
Coffee.coin(100);
Coffee.coin(100);
Coffee.coin(100);
Coffee.coin(100);
std::string expect = "ACCEPT";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test7){
Automata Coffee;
Coffee.on();
Coffee.coin(100);
Coffee.coin(100);
Coffee.coin(100);
Coffee.coin(100);
Coffee.cancel();
std::string expect = "WAIT";
EXPECT_EQ(expect, Coffee.getState());
}

TEST(AutomataTest, test8){
Automata Coffee;
Coffee.on();
Coffee.coin(200);
Coffee.choice("latte lalala");
std::string expect = "WAIT";
EXPECT_EQ(expect, Coffee.getState());
}
