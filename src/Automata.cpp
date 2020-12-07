#include <iostream>
#include <string>
#include "Automata.h"

using namespace std;

Automata::Automata()
{
	cash = 0;
	state = OFF;
}

void Automata::on()
{
	if (state == OFF)
		state = WAIT;
}

void Automata::off()
{
	if (state == WAIT)
		state = OFF;
}

void Automata::coin(double coins)
{
	if (state == WAIT || state == ACCEPT)
	{
		cash += coins;
		state = ACCEPT;
	}
}

string Automata::getMenu()
{
	string menu = "";
	for (int i = 0; i < sizeof(prices) / sizeof(double); i++)
		menu += to_string(i) + " " + drinks[i] + " - " + to_string(prices[i]).erase(to_string(prices[i]).size()-4) + "\n";
	return menu;
}

STATES Automata::getState()
{
	return state;
}

void Automata::choice(int num)
{
	if (state == ACCEPT && num < 5 && num >= 0)
	{
		state = CHECK;
		check(num);
	}
}

void Automata::check(int num)
{
	if (cash >= prices[num]) 
		cook(num);
	else
		state = ACCEPT;
}

void Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		cash = 0; 
	}
}

void Automata::cook(int num)
{
	if (state == CHECK) {
		state = COOK;
		cout << "Cooking..." << endl;
		finish(num);
	}
}

void Automata::finish(int num)
{
	if (state == COOK) 
	{
		if (cash - prices[num] > 0) 
			cout << "Your change: " << cash - prices[num] << endl;
		cash = 0;
		state = WAIT;
	}
}