//  Copyright 2020 PolinaP
#ifndef AUTOMATA_H
#define AUTOMATA_H

using namespace std;

#include <string>
#include <vector>
#include <iostream>

enum States { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
private:
	int cash;
	vector<string> strStates = { "OFF","WAIT","ACCEPT","CHECK","COOK" };
	vector<string> menu = { "Latte","Espresso","Cappuccino","Tea","Water" };
	vector<int> prices = { 10,20,30,40,50 };
	States state;
public:
	Automata();
	void on();
	void off();
	void coin(int);
	void getMenu();
	string getState();
	void choice(int);
	bool check(int);
	void cancel();
	void cook();
	int finish();
};
#endif
