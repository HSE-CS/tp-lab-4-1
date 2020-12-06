#include "Automata.h"

int main() {
	Automata a;
	std::cout << a.getMenu() << std::endl;
	a.on();
	a.coin(42);
	std::cout << a.getState() << std::endl;
	a.choice(2);
	std::cout << a.getCoin() << std::endl;
	
	return 0;
}
