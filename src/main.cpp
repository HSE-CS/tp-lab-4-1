//Copyright 2020 Pasmanik Irina
#include "Automata.h"
#include <iostream>

int main() {
	Automata automata;
	automata.on();
	std::cout << automata.getMenu() << std::endl;
	automata.coin(50);
	automata.cancel();
	std::cout << std::endl;
	automata.coin(20);
	automata.coin(30);
	automata.choice(2);
	automata.finish();
	automata.off();
	return 0;
}
