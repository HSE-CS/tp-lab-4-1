#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum STATE { OFF = 1, WAIT, ACCEPT, CHECK, COOK };

class Automata 
{
private:
	int cash, donation;
	int prices[8] = { 7, 10, 13, 19, 20, 25, 999, 1};
	string menu[8] = { "Tea", "Milk", "Espresso", "Americano", "Iced coffee", "Cappucino", "Red eye", "Yuan Yang" };
	STATE state;
public:
	Automata() 
	{
		state = OFF;
		cash = 0;
		donation = 0;
	};
	void on();
	void off();
	void coin(int, bool next=false);
	void getMenu(int num=8);
	STATE getState();
	void choice(int);
	void check(int);
	void cancel();
	void cook();
	void finish();
};

#endif
