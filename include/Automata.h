#pragma once
#ifndef	AUTOMATA_H
#define	AUTOMATA_H

#define SIZE 10

enum States {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
private:
	int cash;
	std::string menu[SIZE];
	char prices[SIZE];
	States state;
public:
	Automata();
	void on();
	void off();
	void coin();
	std::string getMenu();
	States getState();
	void choice();
	void check();
	void cancel();
	void cook();
	void finish();
};

#endif
