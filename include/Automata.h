//Copyright 2020 Ryzhova
#ifndef INCLUDE_AUTOMATA_H_
#define  INCLUDE_AUTOMATA_H_

#include <iostream>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
 private:
	double cash = 0.0;
	std::string menu[8] = {"water", "tea", "latte", "cappuccino",
                            "americano", "espresso", "hot chocolate",
                            "cocoa"};
	double prices[8] = {15.0, 25.7, 35.1, 40.6, 40.0, 35.25, 50.0, 45.9};
	STATES state;
    void check(int index);
    void cook(int index);
	void finish(int index);
 public:
	Automata();
	void on();
	void off();
	void coin(double cash);
	std::string getMenu();
	STATES getState();
	void choice(int num);
	void cancel();
};

#endif