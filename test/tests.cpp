#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public ::testing::Test
{
public:
  Automata instance;
};

TEST_F(AutomataTest, init)
{
  const std::vector<std::string> expectedMenu = {
    "Black Tea",
    "Green Tea",
    "Americano",
    "Capuccino",
    "Latte",
    "Hot Chocolate",
  };
  const std::vector<int> expectedPrices = {
    20,
    20,
    35,
    50,
    45,
    40,
  };
  EXPECT_EQ(instance.getState(), STATES::OFF);
  const auto menu = instance.getMenu();
  for (size_t i = 0; i < menu.size(); ++i)
  {
    ASSERT_EQ(menu[i].first, expectedMenu[i]);
    ASSERT_EQ(menu[i].second, expectedPrices[i]);
  }
}

TEST_F(AutomataTest, on_off)
{
  ASSERT_EQ(instance.getState(), STATES::OFF);
  instance.on();
  ASSERT_EQ(instance.getState(), STATES::WAIT);
  instance.off();
  ASSERT_EQ(instance.getState(), STATES::OFF);
}

TEST_F(AutomataTest, choice)
{
  instance.on();
  instance.coin(30);
  instance.choice(1);
  ASSERT_EQ(instance.getState(), STATES::CHECK);
  instance.cancel();
  ASSERT_EQ(instance.getState(), STATES::WAIT);
}

TEST_F(AutomataTest, accept)
{
  instance.on();
  ASSERT_EQ(instance.getBalance(), 0);
  instance.coin(10);
  ASSERT_EQ(instance.getBalance(), 10);
  ASSERT_EQ(instance.getState(), STATES::ACCEPT);
  instance.coin(2);
  ASSERT_EQ(instance.getBalance(), 12);
  ASSERT_EQ(instance.getState(), STATES::ACCEPT);
  instance.cancel();
  ASSERT_EQ(instance.getState(), STATES::WAIT);
  ASSERT_EQ(instance.getBalance(), 0);
}

TEST_F(AutomataTest, check)
{
  instance.on();
  instance.coin(30);
  instance.choice(3);
  ASSERT_FALSE(instance.check());
  ASSERT_EQ(instance.getState(), STATES::CHECK);
  ASSERT_EQ(instance.getBalance(), 30);

  instance.coin(20);
  instance.choice(3);
  ASSERT_TRUE(instance.check());
  ASSERT_EQ(instance.getState(), STATES::READY);
  ASSERT_EQ(instance.getBalance(), 50);

  instance.cancel();
  ASSERT_EQ(instance.getState(), STATES::WAIT);
  ASSERT_EQ(instance.getBalance(), 0);
}

TEST_F(AutomataTest, cook_and_finish)
{
  instance.on();
  instance.coin(60);
  instance.choice(3);
  ASSERT_TRUE(instance.check());
  ASSERT_EQ(instance.getState(), STATES::READY);
  instance.cook();
  ASSERT_EQ(instance.getBalance(), 10);
  instance.finish();
  ASSERT_EQ(instance.getState(), STATES::WAIT);
  ASSERT_EQ(instance.getBalance(), 0);
}
