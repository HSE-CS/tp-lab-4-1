#include <algorithm>
#include <iostream>

#include "VendingMachine.hpp"

int main() {
  VendingMachine machine;
  machine.on();
  const BeverageList full_list = machine.getFullBeverageList();
  uint32_t coins = 0;
  uint32_t idx = 0;

  std::cout << "Here's the menu:" << std::endl;
  for (uint32_t i = 0; i < full_list.size(); ++i) {
    std::cout << "  " << i + 1 << ". " << full_list[i].second << " - "
              << full_list[i].first << std::endl;
  }

  std::cout << "Cough up your cash: ";
  std::cin >> coins;
  machine.insertCoins(coins);
  BeverageList can_buy = machine.getBeverageList();
  while (can_buy.size() < 1) {
    std::cout << "Can't buy anything with that. Feed me more coins: ";
    std::cin >> coins;
    machine.insertCoins(coins);
    can_buy = machine.getBeverageList();
  }

  std::cout << "Here's what you can buy with that amount of cash("<< machine.getBalance() <<"):" << std::endl;
  for (uint32_t i = 0; i < can_buy.size(); ++i) {
    std::cout << "  " << i + 1 << ". " << can_buy[i].second << " - "
              << can_buy[i].first << std::endl;
  }

  while (idx < 1 || idx > can_buy.size()) {
    std::cout << "Select one: ";
    std::cin >> idx;
    if (idx < 1 || idx > can_buy.size()) {
      std::cout << "Invalid index" << std::endl;
    }
  }

  idx = std::find(full_list.begin(), full_list.end(), can_buy[idx - 1]) -
        full_list.begin();
  std::cout << "Cooking... Here's your change: " << machine.select(idx) << std::endl;
  std::cout << "...And here's your " << machine.finish() << std::endl;
  machine.off();
  return 0;
}