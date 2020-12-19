//  Copyright 2020 PolinaP
#include <iostream>
#include "automata.h"
using namespace std;

Automata::Automata()
{
	cash = 0;
	state = States::OFF;
}

void Automata::on()
{
	if (state == States::OFF) {
		state = States::WAIT;
		cout << "Hello, World!" << endl;
	} else {
		cout << "Automata is already running" << endl;
	}
}

void Automata::off()
{
	if (state == States::WAIT)	{
		state = States::OFF;
		cash = 0;
		cout << "Turned off sucessfully" << endl;
	} else {
		cout << "Automata cannot be off right now" << endl;
	}
}

void Automata::coin(int money)
{
	if (state == States::WAIT || state == States::ACCEPT) {
		state = States::ACCEPT;
		cash += money;
		cout << "Cash:" << cash << endl;
	}
}

void Automata::getMenu()
{
	cout << "Menu:" << endl;
	for (int i = 0; i < menu.size(); i++)
		cout << menu[i] << " - " << prices[i] << "$" << endl;
}

string Automata::getState()
{
	cout << "Current state is " << strStates[state] << endl;
	return strStates[state];
}

bool Automata::check(int position)
{
	state = States::CHECK;
	return prices[position] <= cash;
}

void Automata::choice(int position)
{
	if (state == States::ACCEPT) {
		if (check(position))	{
			cash -= prices[position];
			cook();
		} else	{
			cout << "Not enough money" << endl;
		}
	} else {
		cout << "You have to insert money firstly" << endl;
	}
}

void Automata::cook()
{
	state = States::COOK;
	cout << "Automata is working..." << endl;
	cout << "Drink is ready" << endl;
}

int Automata::finish()
{
	if (state == States::COOK)	{
		state = States::WAIT;
		int change = cash;
		cout << "Your change:" << cash << endl;
		cash = 0;
		return change;
	} else	{
		cout << "Unable to finish right now" << endl;
		return -1;
	}
}

void Automata::cancel()
{
	if (state == States::COOK || state == States::CHECK || state == States::ACCEPT)	{
		state = States::WAIT;
	} else {
		cout << "Unable to cancel right now" << endl;
	}
}
