#include "Automata.h"

Automata::Automata() : cash{ 0 }, state{ OFF }, drink{ 0 }
{
	menu = new std::string[6]{
		"Water",
		"Green tea",
		"Black tea",
		"Espresso",
		"Capuccino",
		"Hot chocolate"
	};
	prices = new unsigned[6]{ 10, 40, 30, 50, 60, 60 };
}

void Automata::on()
{
	if (getState() == OFF)
		state = WAIT;
}

void Automata::off()
{
	if (getState() == WAIT)
		state = OFF;
}

void Automata::coin(unsigned coins)
{
	if (getState() == WAIT)
	{
		if (coins > 0)
		{
			cash += coins;
			state = ACCEPT;
		}
		else
			cancel();
	}
}

std::string Automata::getMenu() const
{
	std::string res;
	for (int i = 0; i < 6; i++)
		res += std::to_string(i + 1) + ") " + menu[i] + " - " + std::to_string(prices[i]) + " RUBLES\n";
	return res;
}

STATES Automata::getState() const
{
	return state;
}

void Automata::choice(const int n)
{
	if (getState() == ACCEPT && n >= 0 && n <= 6)
	{
		state = CHECK;
		drink = n;
	}
}

bool Automata::check()
{
	if (getState() == CHECK && cash >= prices[drink])
		return true;
	else
	{
		cancel();
		return false;
	}
}

void Automata::cancel()
{
	if (getState() == ACCEPT || getState() == CHECK)
		state = WAIT;
}

void Automata::cook()
{
	if (getState() == CHECK && check())
		state = COOK;
}

void Automata::finish()
{
	if (getState() == COOK)
	{
		state = WAIT;
		cash -= prices[drink];
	}
}

