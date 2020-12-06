#include <iostream>
#include "Automata.h"

int main() {
	Automata a;
	a.on();
	a.coin(5);
	a.coin(5);
	a.coin(5);
	a.coin(30);
	std::cout << a.getState() << std::endl;
	std::cout << "Choose a drink\n";
	a.getMenu();
	a.choise("Latte");
	a.cook();
	a.finish();
	a.choise("Cappuccino");
	a.cook();
	a.finish();
	a.off();
	Automata b;
	b.on();
	b.coin(20);
	std::cout << "Choose a drink\n";
	b.getMenu();
	b.choise("Chocolate");
	b.cook();
	b.finish();
	b.off();
	Automata c;
	c.getMenu();
	return 0;
}