#pragma once
#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <iostream>
#include <string>
#include 


enum States
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
private:
	int cash;
	const char** menu;
	const int* prices;
	States state;
public:
	Automata();
	void on();
	void off();
	void coin(int);
	std::string getMenu();
	char* getState();
	void choice(int);
	bool check(int);
	void cancel(int);
	void cook();
	void finish();

};

#endif // AUTOMATA_H