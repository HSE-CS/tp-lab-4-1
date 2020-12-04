#pragma once
#include <string>
#include <vector>

using Beverage = std::string;
using BeverageList = std::vector<std::pair<Beverage, uint32_t>>;

enum VendingMachineState { OFF, WAITING, BEVERAGE_SELECTION, COOKING };

class VendingMachine {
 private:
  uint32_t balance;
  BeverageList beverages;
  VendingMachineState state;
  uint32_t selected_idx;

 public:
  VendingMachine();
  void on();
  void off();
  void insertCoins(const uint32_t);
  const uint32_t cancel();
  const uint32_t select(const uint32_t);
  void addBeverage(Beverage, uint32_t);
  void removeBeverage(const uint32_t);
  const uint32_t getBalance();
  const BeverageList getFullBeverageList();
  const BeverageList getBeverageList();
  const VendingMachineState getState();
  const Beverage finish();
};