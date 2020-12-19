// Copyright 2020 SalakhovRamazan

#pragma once
#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <iostream>
#include <string>
//#include <windows.h>
#include <stdlib.h>
#include <vector>
#define MENU 4

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
	std::string menu[MENU] = { "Latte", "Kumis", "Capuccino", "Tea" };
	int prices[MENU] = { 20, 300, 30, 10 };
	States state;
public:
	Automata();
	void on();
	void off();
	void coin(int);
	void choice(int);
	bool check(int);
	void cancel(int);
	void cook();
	void finish();
	std::string getMenu();
	States getState();
};

#endif // AUTOMATA_H 