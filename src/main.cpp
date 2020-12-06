// Copyright 2020 Nikita Stifeev
#include "Automata.h"

int main() {
	Automata my_machine = Automata();
	my_machine.on();
	std::cout << "Your budget:" << std::endl;
	int budget;
	std::cin >> budget;
	my_machine.coin(budget);
	int n;
	std::cout << "what do you want to buy?" << std::endl;
	std::cin >> n;
	if (my_machine.choice(n) != 11) {
		my_machine.cancel();
	}
	else if (my_machine.check() == 11) {
		my_machine.cook();
		my_machine.finish();
	}
	else {
		my_machine.cancel();
	}
	my_machine.off();
}