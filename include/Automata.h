// Copyright 2020 dash
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#define M 10

enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
 public:
	 Automata();
	 void on();
	 void off();
	 bool coin(int chash);
	 std::string getMenu();
	 STATES getState();
	 void choice(int num);
	 void check(int num);
	 void cancel();
	 void cook();
	 void finish();

 private:
	 int cash;
	 std::string menu[M] = {"Espresso", "Americano", "Latte", "Cappuccino", "Mochaccino", "Glasse", "Hot chocolate", "Cocoa", "Green tea", "Black tea"};
	 int prices[M] = {30, 40, 45, 45, 45, 50, 55, 55, 25, 25};
	 STATES state;
};

#endif // INCLUDE_AUTOMATA_H_