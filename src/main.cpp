//Copyright 2020 Uskova
#include "Automata.h"
#include <iostream>

int main()
{
	Automata coffee_machine;
	std::cout << "On" << std::endl;
	coffee_machine.on();
	std::cout << " " << std::endl;
	std::cout << "Get menu" << std::endl;
	coffee_machine.getMenu();
	std::cout << " " << std::endl;
	std::cout << "35 rub" << std::endl;
	coffee_machine.coin(35);
	std::cout << " " << std::endl;
	std::cout << "5" << std::endl;
	coffee_machine.choice(5);
	std::cout << " " << std::endl;
	std::cout << "20 rub" << std::endl;
	coffee_machine.coin(20);
	std::cout << " " << std::endl;
	std::cout << "5" << std::endl;
	coffee_machine.choice(5);
	std::cout << " " << std::endl;
	std::cout << "Off" << std::endl;
	coffee_machine.off();
	return 0;
}
