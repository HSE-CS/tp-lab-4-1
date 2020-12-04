//Copyright 2020 Uskova
#include "Automata.h"
#include <iostream>
#include <Windows.h>

int main()
{
	Automata coffee_machine;
	std::cout << "On" << std::endl;
	Sleep(2000);
	coffee_machine.on();
	Sleep(4000);
	std::cout << " " << std::endl;
	std::cout << "Get menu" << std::endl;
	Sleep(2000);
	coffee_machine.getMenu();
	Sleep(5000);
	std::cout << " " << std::endl;
	std::cout << "35 rub" << std::endl;
	Sleep(2000);
	coffee_machine.coin(35);
	Sleep(4000);
	std::cout << " " << std::endl;
	std::cout << "5" << std::endl;
	coffee_machine.choice(5);
	Sleep(4000);
	std::cout << " " << std::endl;
	std::cout << "20 rub" << std::endl;
	Sleep(2000);
	coffee_machine.coin(20);
	Sleep(4000);
	std::cout << " " << std::endl;
	std::cout << "5" << std::endl;
	Sleep(2000);
	coffee_machine.choice(5);
	Sleep(4000);
	std::cout << " " << std::endl;
	std::cout << "Off" << std::endl;
	coffee_machine.off();
	return 0;
}
