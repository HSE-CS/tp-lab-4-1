#include "VendingMachine.hpp"

#include <iostream>

const BeverageList DEFAULT_BEVERAGES = {
    {"Coffee", 12}, {"Hot choclate", 10}, {"Green tea", 8}, {"Black tea", 7}};

VendingMachine::VendingMachine() {
  this->beverages = DEFAULT_BEVERAGES;
  this->selected_idx = 0;
  this->state = OFF;
  this->balance = 0;
}

void VendingMachine::on() {
  switch (this->state) {
    case OFF:
      this->state = WAITING;
      break;
    default:
      std::cerr << "Called `on` while not in `OFF` state" << std::endl;
  }
}

void VendingMachine::off() {
  switch (this->state) {
    case WAITING:
      this->state = OFF;
      break;
    default:
      std::cerr << "Called `off` while not in `WAITING` state" << std::endl;
  }
}

void VendingMachine::insertCoins(const uint32_t c) {
  switch (this->state) {
    case WAITING:
      this->state = BEVERAGE_SELECTION;
    case BEVERAGE_SELECTION:
      this->balance += c;
      break;
    default:
      std::cerr << "Called `insertCoins` while not in `WAITING, "
                   "BEVERAGE_SELECTION` state"
                << std::endl;
  }
}

const uint32_t VendingMachine::cancel() {
  switch (this->state) {
    case BEVERAGE_SELECTION:
      this->state = WAITING;
      uint32_t _balance = this->balance;
      this->balance = 0;
      return _balance;
    default:
      std::cerr << "Called `cancel` while not in `BEVERAGE_SELECTION` state"
                << std::endl;
  }
  return 0;
}

const uint32_t VendingMachine::select(const uint32_t idx) {
  switch (this->state) {
    case BEVERAGE_SELECTION:
      if ((idx < this->beverages.size()) &&
          (this->balance >= this->beverages[idx].second)) {
        this->selected_idx = idx;
        this->state = COOKING;
        uint32_t ret = this->balance - this->beverages[idx].second;
        this->balance = 0;
        return ret;
      }
      break;
    default:
      std::cerr << "Called `select` while not in `BEVERAGE_SELECTION` state"
                << std::endl;
  }
  return 0;
}

void VendingMachine::addBeverage(Beverage b, uint32_t price) {
  this->beverages.push_back(std::pair<Beverage, uint32_t>(b, price));
}

void VendingMachine::removeBeverage(const uint32_t idx) {
  switch (this->state) {
    case OFF:
    case WAITING:
    case BEVERAGE_SELECTION:
      this->beverages.erase(this->beverages.begin() + idx);
      break;
    default:
      std::cerr << "Called `removeBeverage` while not in `OFF, WAITING, "
                   "BEVERAGE_SELECTION` state"
                << std::endl;
  }
}

const BeverageList VendingMachine::getFullBeverageList() { return this->beverages; }

const BeverageList VendingMachine::getBeverageList() {
  BeverageList out;
  for (uint32_t i = 0; i < this->beverages.size(); ++i) {
    if (this->beverages[i].second <= this->balance) {
      out.push_back(this->beverages[i]);
    }
  }
  return out;
}

const Beverage VendingMachine::finish() {
  switch (this->state) {
    case COOKING:
      this->state = WAITING;
      return this->beverages[this->selected_idx].first;
      break;
    default:
      std::cerr << "Called `finish` while not in `COOKING` state" << std::endl;
  }
  return Beverage();
}

const uint32_t VendingMachine::getBalance(){
  return this->balance;
}

const VendingMachineState VendingMachine::getState(){
  return this->state;
}