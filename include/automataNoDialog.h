#pragma once
#include <string>
#include <vector>
#include <stdio.h>
#include <stdarg.h>

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
	std::vector<std::string> menu;
	std::vector<unsigned int> prices;
	STATES state;
public:
	Automata(std::string datafile);
	void on();
	void off();
	//void test(...);
	int coin(int money);
	void getMenu();
	STATES getState();
	int choice(unsigned int choice_id);
	bool check(unsigned int choice);
	void cancel();
	void cook();
	void finish();
};