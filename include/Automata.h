#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <vector>
#include <string>

enum States {
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
	void coin(int);
	void getMenu();
	States getState();
	void choise(std::string);
	bool check(int);
	void cancel();
	void cook();
	void finish();
private:
	int cash = 0;
	std::vector<std::string> menu = { "Espresso", "Americano", "Cappuccino", "Latte", "Chocolate", "Hot milk", "Tea" };
	std::vector<int> prices = { 25, 40, 40, 40, 35, 35, 20};
	States state;
};

#endif 
