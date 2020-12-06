// Copyright 2020 dash
#include <iostream>
#include "Automata.h"

int main() {
	Automata a;
	a.on();
	std::cout << a.getMenu() << std::endl;
	std::cout << a.getState() << std::endl;
	a.coin(60);
	std::cout << a.getState() << std::endl;
	a.choice(3);
	std::cout << a.getState() << std::endl;
	a.check(3);
	std::cout << a.getState() << std::endl;
	a.off();
	std::cout << a.getState() << std::endl;
}