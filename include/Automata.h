// Copyright 2020 Nikita Stifeev
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <iostream>

class Automata {
  private:
	enum STATUS {
		ACCEPT,
		WAIT,
		CHECK,
		COOK,
		COMPLETE,
		OFF,
	};
	std::string error[6] = { "the coffee maker is already on",
							"it can't turn off",
							"where is the your money?",
							"wrong number of drink",
							"operation failed to complete",
							"not enough money" };
	unsigned int cash_money;
	std::string menu[5] = { "espresso", "americano", "latte", "frappe", "tea" };
	unsigned int price[5] = { 20, 35, 25, 30, 15 };
	STATUS current_status;
	int number_drink;
	void getMenu();
	void changeState(STATUS state);
  public:
	Automata();
	int on();
	int off();
	int coin(int money);
	int choice(int drink);
	int check();
	int cancel();
	int cook();
	int finish();
	std::string getState();
	unsigned int getCash();
};

#endif  // INCLUDE_AUTOMATA_H_