#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata_test, test1){
    Automata bar;
    bar.on();
    EXPECT_EQ(WAIT, bar.getCondition());
}

TEST(automata_test, test2){
    Automata bar;
    bar.on();
    bar.coin(128);
    EXPECT_EQ(128, bar.getMoneyAmount());
}

TEST(automata_test, test3){
    Automata bar;
    bar.on();
    bar.coin(128);
    EXPECT_EQ(bar.getCondition(), ACCEPT);
}

TEST(automata_test, test4){
    Automata bar;
    bar.on();
    bar.coin(128);
    bar.choice(3);
    EXPECT_EQ(bar.getCondition(), CHECK);
}

TEST(automata_test, test5){
    Automata bar;
    bar.on();
    bar.coin(128);
    int choice{3};
    bar.choice(choice);
    EXPECT_EQ(bar.getChoice(), choice);
}

TEST(automata_test, test6){
    Automata bar;
    bar.on();
    bar.coin(128);
    int choice{3};
    bar.choice(choice);
    EXPECT_TRUE(bar.check());
}

TEST(automata_test, test7){
    Automata bar;
    bar.on();
    bar.coin(128);
    int choice{5};
    bar.choice(choice);
    EXPECT_FALSE(bar.check());
}

TEST(automata_test, test8){
    Automata bar;
    bar.on();
    bar.coin(128);
    int choice{3};
    bar.choice(choice);
    bar.cook();
    EXPECT_EQ(bar.getCondition(), COOK);
}

TEST(automata_test, test9){
    Automata bar;
    bar.on();
    bar.coin(128);
    int choice{3};
    bar.choice(choice);
    bar.cook();
    bar.finish();
    EXPECT_EQ(bar.getCondition(), WAIT);
}

TEST(automata_test, test10){
    Automata bar;
    bar.on();
    bar.coin(128);
    int choice{3};
    bar.choice(choice);
    bar.cancel();
    EXPECT_EQ(bar.getCondition(), WAIT);
}
