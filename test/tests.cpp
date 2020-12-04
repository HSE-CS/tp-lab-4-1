#include <gtest/gtest.h>

#include "VendingMachine.hpp"

// Honestly, this code is garbage.
// Either way, testing this is quite difficult
TEST(vm, test1) {
  VendingMachine v;
  v.on();
  ASSERT_EQ(v.getState(), WAITING);
  v.off();
  ASSERT_EQ(v.getState(), OFF);
}

TEST(vm, test2) {
  VendingMachine v;
  v.on();
  v.insertCoins(100);
  ASSERT_EQ(v.getBalance(), 100);
  v.insertCoins(100);
  v.insertCoins(100);
  ASSERT_EQ(v.getBalance(), 300);
}

TEST(vm, test3) {
  VendingMachine v;
  v.on();
  v.addBeverage("Mocha", 100);
  BeverageList list = v.getFullBeverageList();
  ASSERT_EQ(list[list.size() - 1].second, 100);
}

// Why? I don't know, why not?
TEST(vm, test4) {
  VendingMachine v;
  v.on();
  ASSERT_STREQ(v.finish().c_str(), Beverage().c_str());
}

TEST(vm, test5) {
  VendingMachine v;
  v.on();
  BeverageList list = v.getFullBeverageList();
  list.erase(list.begin());
  v.removeBeverage(0);
  BeverageList list2 = v.getFullBeverageList();
  for (uint32_t i = 0; i < list2.size(); ++i){
      ASSERT_EQ(list[i].second, list2[i].second);
  }
}

TEST(vm, test6) {
  VendingMachine v;
  v.on();
  v.select(0);
  ASSERT_EQ(v.getState(), WAITING);
  v.insertCoins(100);
  ASSERT_EQ(v.getState(), BEVERAGE_SELECTION);
  v.select(0);
  ASSERT_EQ(v.getState(), COOKING);
  v.finish();
  ASSERT_EQ(v.getState(), WAITING);
  v.off();
  ASSERT_EQ(v.getState(), OFF);
}

TEST(vm, test7) {
  VendingMachine v;
  v.on();
  v.insertCoins(100);
  ASSERT_EQ(v.cancel(), 100);
  v.insertCoins(200);
  v.insertCoins(100);
  ASSERT_EQ(v.cancel(), 300);
  ASSERT_EQ(v.cancel(), 0);
}

TEST(vm, test8) {
  VendingMachine v;
  v.off();
  v.insertCoins(1001);
  v.select(100);
  ASSERT_EQ(v.cancel(), 0);
  ASSERT_EQ(v.getBalance(), 0);
  v.finish();
  ASSERT_EQ(v.getState(), OFF);
}

TEST(vm, test9) {
  VendingMachine v;
  v.on();
  ASSERT_EQ(v.getState(), WAITING);
}

TEST(vm, test10) {
  VendingMachine v;
  v.on();
  v.insertCoins(101);
  ASSERT_EQ(v.getState(), BEVERAGE_SELECTION);
}