#include "Automata.h"
#include <vector>
#include <iostream>
#include <cstring>

std::vector <std::string> menu_{ "coffee", "cocoa", "latte", "black tea", "green tea" };
std::vector <int> prices_{ 40, 45, 50, 30, 35 };

Automata::Automata()
{
	cash = 0;
	menu = menu_;
	prices = prices_;
	state = OFF;
}

void Automata::off()
{
	if (state == WAIT)
		state = OFF;
}

void Automata::on()
{
	if (state == OFF)
		state = WAIT;
}

void Automata::coin(int money)
{
	if (state == WAIT || state == ACCEPT)
	{
		cash = money;
		state = ACCEPT;
	}
}

std::string Automata::getMenu()
{
	if (state != OFF) {
		std::string res, elem;
		for (int i = 0; i < menu.size(); i++)
		{
			std::string price = std::to_string(prices[i]), num = std::to_string(i);
			elem = menu[i] + " -> " + price + "\n";
			res.append(elem);
		}
		return res;
	}
	return "Error, automata is off\n";
}

STATES Automata::getState()
{
	return state;
}

void Automata::choice(std::string drink_)
{
	if (state == ACCEPT) {
		for (int i = 0; i != menu_.size(); i++) {
			if (menu_[i] == drink_) {
				this->drink_index = i;
				state = CHECK;
			}
		}
	}
}

bool Automata::check()
{
	if (state == CHECK || state == ACCEPT)
	{
		state = CHECK;
		return this->prices[this->drink_index] <= this->cash;
	}
	return false;
}

int Automata::cancel()
{
	state = WAIT;
	int cash_return = cash;
	this->cash = 0;
	return cash_return;
}

void Automata::finish()
{
	if (this->getState() == COOK)
	{
		cancel();
	}
}

void Automata::cook()
{
	if (this->getState() == CHECK)
	{
		state = COOK;
		this->cash -= prices[drink_index];
		this->drink_index = 0;
	}
}