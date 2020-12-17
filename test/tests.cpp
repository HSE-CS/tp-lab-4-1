#include "gtest/gtest.h"
#include "Automata.h"


TEST(get_menu, expect_no_error)
{
Automata automata;
automata.on();
EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(choice, expect_no_error)
{
Automata automata;
automata.on();
automata.coin(50);
automata.choice(2);
EXPECT_EQ(automata.getState(), STATES::ACCEPT);
}


TEST(cancel, expect_no_error)
{
Automata automata;
automata.on();
automata.coin(50);
automata.cancel();
EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(finish, expect_no_error)
{
Automata automata;
automata.on();
automata.coin(500);
automata.choice(2);
EXPECT_EQ(automata.getState(), STATES::WAIT);
}

TEST(getCash, expect_no_error)
{
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.coin(20);
    EXPECT_EQ(automata.getCash(), 120);
}