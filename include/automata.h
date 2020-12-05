//Copyright 2020 FOM
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include<vector>
#include <string>
#define SIZE 10
enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK,
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
	std::string arr_menu[SIZE] = {"Espresso","Cappuccino",
		"Ristretto","Lungo",
		"Latte","Latte macchiato",
		"Tea","Green tea",
		"Cold tea","Water" };
	int arr_prices[SIZE] = { 40, 40, 60, 55, 45,
		55, 25, 30, 20, 20 };
	STATES state;
};
#endif // INCLUDE_AUTOMATA_H_
