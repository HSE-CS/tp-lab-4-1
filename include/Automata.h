//Copyright (c) 2020 Sozinov Kirill

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>
#include <utility>

enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {

private:
	unsigned int cash;
	/*static*/ std::vector<std::string> menu; // { "black tea", "green tea", "cappuccino", "latte", "espresso", "americano", "hot chocolate"}
	/*static*/ std::vector<unsigned int> prices;
	STATES state;
public:
	Automata(std::vector<std::string> menu, std::vector<unsigned int> prices);
	void on();
	void off();
	void coin(unsigned int money);
	std::pair< std::vector <std::string>, std::vector <unsigned int> > getMenu();
	STATES getState();
	void choice(unsigned int drink);
	bool check(unsigned int drink);
	void cancel();
	void cook();
	void finish();
};

#endif // INCLUDE_AUTOMATA_H_

