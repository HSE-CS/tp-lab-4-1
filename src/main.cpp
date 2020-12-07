#include "Automata.h"
#include <iostream>

int main()
{
	Automata x;
	x.on();
	std::cout << x.getState() << std::endl;

	std::cout << x.getMenu() << std::endl;

	x.coin(0);
	std::cout << x.getState() << std::endl;

	x.coin(100);
	x.choice(3);
	std::cout << x.getState() << std::endl;
	x.cook();
	std::cout << x.getState() << std::endl;

	x.finish();
	std::cout << x.getState() << std::endl;
	
	x.off();
	std::cout << x.getState() << std::endl;


	return 0;
}