#pragma once
#include <iostream>
#include <string>

using namespace std;

enum STATES
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
private:
	double cash;
	string drinks[5] = {"Tea", "Espresso", "Latte", "Cappuccino", "Hot chocolate" };
	double prices[5] = { 19.99, 29.99, 34.99, 49.99, 39.99};
	STATES state;
public:
	Automata();
	void on();
	void off();
	void coin(double coins);
	string getMenu();
	STATES getState();
	void choice(int num);
	void check(int num);
	void cancel();
	void cook(int num);
	void finish(int num);
};