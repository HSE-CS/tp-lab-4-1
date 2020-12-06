//Copyright 2020 Pasmanik Irina
#pragma once
#include <iostream>
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
	std::string menu[SIZE] = {"Espresso", "Americano", "Latte", "Black Tea", "Green Tea"};
	char prices[SIZE] = { 40, 45, 60, 30, 30 };
	States state;
public:
	Automata();
	void on();
	void off();
	void coin(int coin);
	int getCash();
	std::string getMenu();
	States getState();
	void choice(int pos);
	void check(int pos);
	void cancel();
	void cook();
	void finish();
};

#endif
