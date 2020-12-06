#include "Automata.h"

#include <iostream>

void add_money(Automata &automata, const int amount)
{
	automata.coin(amount);
	std::cout << "Added " << amount << " RUB, balance: " << automata.getBalance() << " RUB" << std::endl;
}

int main()
{
	Automata automata;
	automata.on();
	
	const auto menu = automata.getMenu();
	std::cout << "Menu:" << std::endl;
	for (size_t i = 0; i < menu.size(); ++i)
		std::cout << i + 1 << ": " << menu[0].first << "(" << menu[0].second << " RUB)" << std::endl;
	std::cout << std::endl;

	add_money(automata, 5);
	add_money(automata, 10);
	add_money(automata, 25);

	automata.choice(2);
	const auto item = menu[automata.getCurrentChoice()];
	std::cout << "Chosen item: " << item.first << ", price: " << item.second << " RUB" << std::endl;
	if (automata.check())
	{
		std::cout << "Ready to cook" << std::endl;
		automata.cook();
		std::cout << "Beverage has been cooked, your balance is " << automata.getBalance() << " RUB" << std::endl;
	}
	else
		std::cout << "Not enough money to pay" << std::endl;
	automata.off();
	std::cout << "Power off" << std::endl;

	return 0;
}
