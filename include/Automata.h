// Copyright 2020 Lab_4 TiNa
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#define N 9

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
	 int cash;
	 std::string menu[N] = { "Black tea", "Green tea", "Espresso", "Big espresso", "Coffee with milk", "Cappuccino", "Hot chocolate", "Chocolate with milk", "Mokkachino"};
	 int prices[N] = {20, 20, 30, 50, 40, 60, 50, 60, 65};
	 STATES state;
 public:
	 Automata();
	 void on();
	 void off();
	 void coin(int money);
	 std::string getMenu();
	 STATES getState();
	 void choice(int num);
	 void check(int num);
	 void cancel();
	 void cook();
	 void finish();
};

#endif  // INCLUDE_AUTOMATA_H_