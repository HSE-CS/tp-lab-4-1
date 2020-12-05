// Copyright 2020 Lab_4 TiNa
#include "Automata.h"
#include <iostream>
#include <string>


int main() {
	Automata aut;
	aut.on();
	std::cout << aut.getMenu() << std::endl;
	aut.coin(100);
	std::cout << aut.getState() << std::endl;
	aut.choice(8);
	std::cout << aut.getState() << std::endl;
	aut.check(8);
	std::cout << aut.getState() << std::endl;
	aut.off();
	std::cout << aut.getState() << std::endl;
	return 0;
}