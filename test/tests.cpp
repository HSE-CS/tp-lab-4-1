// Copyright 2020 test
#include "gtest/gtest.h"
#include "Automata.h"
#include <string>
#include<iostream>

TEST(Constructor, test1) {
Automata test;
EXPECT_EQ(test.getState(), "OFF");
}

TEST(STATES, test1) {
Automata test;
test.on();
EXPECT_EQ(test.getState(), "WAIT");
}

TEST(STATES, test2) {
Automata test;
test.on();
test.coin(50);
EXPECT_EQ(test.getState(), std::to_string(ACCEPT));
}

TEST(coin, test1) {
Automata test;
test.on();
test.coin(500);
EXPECT_EQ(test.getCash(), 500);
}

TEST(cook, test1) {
Automata test;
test.on();
test.coin(10);
test.choice(1);
EXPECT_EQ(test.getState(), std::to_string(WAIT));   //  Мы не смогли оплатить, деньги вернулись покупателю
}

TEST(cook, test2) {
Automata test;
test.on();
test.coin(40);
test.choice(1);
EXPECT_EQ(test.getState(), std::to_string(WAIT));   // Покупатель получил свой товар
}

TEST(cook, test3) {
Automata test;
test.on();
test.coin(30);
test.choice(5);
EXPECT_EQ(test.getState(), std::to_string(WAIT));   // Покупатель получил свой товар
}


TEST(cancel, test1) {
Automata test;
test.cancel();
EXPECT_EQ(test.getState(), std::to_string(OFF));    // Мы не можем отменить выключенный аппарат
}

TEST(cancel, test2) {
Automata test;
test.on();
test.cancel();
EXPECT_EQ(test.getState(), std::to_string(WAIT));
}

TEST(cancel, test3) {
Automata test;
test.on();
test.coin(30);
EXPECT_EQ(test.getState(), std::to_string(WAIT));
}
