#include "Automata.h"

int main() {
	Automata coffee_aut;

	std::cout << coffee_aut.getState() << std::endl;

	coffee_aut.on();

	std::cout << coffee_aut.getMenu() << std::endl;

	coffee_aut.coin(10);
	coffee_aut.coin(10);
	coffee_aut.coin(10);

	coffee_aut.choice("frappe");

	coffee_aut.coin(10);
	coffee_aut.coin(10);
	coffee_aut.coin(10);
	coffee_aut.coin(10);

	coffee_aut.choice("frappe");


	if (coffee_aut.check()) {
		coffee_aut.cook();
		coffee_aut.finish();
	}
	else {
		coffee_aut.cancel();
	}

	coffee_aut.off();
 
	return 0;
};