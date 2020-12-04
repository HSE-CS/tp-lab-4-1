//Copyright 2020 Uskova
#ifndef INCLUDE_AUTOMATA_H_
#define  INCLUDE_AUTOMATA_H_

#include <string>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
 private:
	double cash;
	std::string menu[12] = {
		"Americano",
		"Double americano",
		"Latte",
		"Cappuccino",
		"Mokkachino",
		"Espresso",
		"Double espresso",
		"Hot chocolate",
		"Coffee with milk",
		"Milk",
		"Green tea",
		"Black tea" };
	int prices[12] = {
		35,
		60,
		40,
		40,
		40,
		35,
		50,
		30,
		40,
		25,
		25,
		25 };
	STATES state;
 public:
	Automata();
	void on();
	void off();
	double coin(double cash);
	void getMenu();
	STATES getState();
	void choice(int num);
	bool check(int num);
	double cancel();
	void cook(int num);
	void finish();
};

#endif
