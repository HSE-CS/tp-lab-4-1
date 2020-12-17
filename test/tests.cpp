#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, test1) {
    AUTOMATA a;
    EXPECT_EQ(OFF, a.getState());
}

TEST(automata, test2) {
    AUTOMATA a;
    a.on();
    EXPECT_EQ(WAIT, a.getState());
}

TEST(automata, test3) {
    AUTOMATA a;
    a.on();
    a.coin(100)
    EXPECT_EQ(100, a.getCash());
}

TEST(automata, test4) {
    AUTOMATA a;
    a.on();
    a.coin(100);
    a.cancel();
    a.off();
    EXPECT_EQ(OFF, a.getState());
}

TEST(automata, test5){
Automata automata = Automata();
automata.on();
automata.coin(50);
automata.coin(100);
automata.choice(1);
EXPECT_EQ(WAIT, automata.getState());
}