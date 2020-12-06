#include "Automata.h"

Automata::Automata()
{
	this->cash = 0;
	const char * menu[] = { "espresso", "latte", "capucino", "raf" };
	this->menu = menu;
	const int prices[] = { 20, 30, 30, 40 };
	this->prices = prices;
	this->state = OFF;
}

void Automata::on()
{
	this->state = WAIT;
}

void Automata::off()
{
	this->cash = 0;
	this->state = OFF;
}

void Automata::coin(int value)
{
	if (this->state == WAIT || this->state == ACCEPT) {
		this->state = ACCEPT;
		this->cash += value;
	}
	else {
		std::cout << "You are already done this part" << std::endl;
		return; 
	}
}

std::string Automata::getMenu()
{
	std::string result;
	int length = 0;
	for (size_t i = 0; i < sizeof(this->prices)/sizeof(this->prices[0]); i++)
	{
		result.append(this->menu[i]);
		result.append(":");
		char word[2]{ 0 };
		result.append(itoa(this->prices[i], word, 10));
		result.append("\n");
	}
	return result;
}

char* Automata::getState()
{
	switch (this->state)
	{
	case OFF:
		char result[4] = "OFF";
		return result;
	case WAIT:
		char result[5] = "WAIT";
		return result;
	case ACCEPT:
		char result[7] = "ACCEPT";
		return result;
	case CHECK:
		char result[6] = "CHECK";
		return result;
	case COOK:
		char result[5] = "COOK";
		return result;
	default:
		char result[6] = "ERROR";
		return result;
	}
}

void Automata::choice(int value)
{
	if (this->state == ACCEPT) {
		if (this->check(value)) {
			std::cout << "Please, w8" << std::endl;
			this->cook();
		}
		else {
			std::cout << "U have no enough money for buy this. Please, put more coins or chose different drink." << std::endl;
			this->cancel(1);
		}
	}
}

bool Automata::check(int value)
{
	if (this->state == ACCEPT)
	{
		this->state = CHECK;
		if (this->prices[value] <= this->cash) {
			return true;
		}
		return false;
	}
}

void Automata::cancel(int reason)
{
	// reason is: 
	// 0 - no enough money for buy
	// 1 - customer cancel his moves
	if (reason) {
		this->state = ACCEPT;
	}
	else
	{
		this->state = WAIT;
	}
}

void Automata::cook()
{
	if (this->state == CHECK) {
		this->state = COOK;
		std::cout << "W8 a minute, your drink is cooking" << std::endl;
		_sleep(2000);
		this->finish();
	}
}

void Automata::finish()
{
	if (this->state == COOK) {
		this->cash = 0;
		this->state = WAIT;
	}
}
