#include "Automata.h"

#include <iostream>

Automata::Automata()
{
  cash = currentChoice = 0;
  menu = {
    "Black Tea",
    "Green Tea",
    "Americano",
    "Capuccino",
    "Latte",
    "Hot Chocolate",
  };
  prices = {
    20,
    20,
    35,
    50,
    45,
    40,
  };
  state = STATES::OFF;
}

void Automata::on()
{
  if(state == STATES::OFF)
    state = STATES::WAIT;
}

void Automata::off()
{
  if (state == STATES::WAIT)
    state = STATES::OFF;
}

void Automata::coin(const unsigned int amount)
{
  if (state == STATES::ACCEPT || state == STATES::WAIT || state == STATES::CHECK)
  {
    state = STATES::ACCEPT;
    cash += amount;
  }
}

int Automata::getBalance() const
{
  return cash;
}

std::vector<std::pair<std::string, int>> Automata::getMenu() const
{
  std::vector<std::pair<std::string, int>> menuWithPrices;
  menuWithPrices.reserve(prices.size());
  for (size_t i = 0; i < prices.size(); ++i)
    menuWithPrices.emplace_back(menu[i], prices[i]);

  return menuWithPrices;
}

STATES Automata::getState()
{
  return state;
}

void Automata::choice(const size_t item)
{
  if (state == STATES::ACCEPT && item < menu.size())
  {
    currentChoice = item;
    state = STATES::CHECK;
  }
}

size_t Automata::getCurrentChoice() const
{
  return currentChoice;
}

bool Automata::check()
{
  if (state == STATES::CHECK || state == STATES::ACCEPT)
  {
    state = STATES::CHECK;
    if (cash >= prices[currentChoice])
    {
      state = STATES::READY;
      return true;
    }
  }
  return false;
}

void Automata::cancel()
{
  cash = 0;
  currentChoice = 0;
  state = STATES::WAIT;
}

void Automata::cook()
{
  if (state == STATES::READY)
  {
    state = STATES::COOK;
    cash -= prices[currentChoice];
    std::cout << "Cooking " << menu[currentChoice] << "\a..." << std::endl;
  }
}

void Automata::finish()
{
  cancel();
}
