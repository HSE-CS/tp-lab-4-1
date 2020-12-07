#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1){
  Automata automata;
  automata.on();
  EXPECT_EQ(1, automata.getState());
}

TEST(automata, test2){
Automata automata;
automata.on();
automata.off();
EXPECT_EQ(0, automata.getState());
}

TEST(automata, test3){
Automata automata;
automata.on();
automata.coin(4);
automata.choice(4);
EXPECT_EQ(2, automata.getState());
}

TEST(automata, test4){
Automata automata;
automata.on();
automata.coin(4);
automata.choice(4);
automata.coin(1);
automata.choice(4);
EXPECT_EQ(1, automata.getState());
}

TEST(automata, test5){
Automata automata;
automata.on();
automata.coin(4);
automata.choice(4);
automata.coin(1);
automata.cancel();
EXPECT_EQ(1, automata.getState());
}

TEST(automata, test6){
Automata automata;
automata.on();
automata.coin(5);
automata.coin(35);
automata.choice(1);
automata.off();
EXPECT_EQ(0, automata.getState());
}