#include "Automata.h"
#include <iostream>
int main()
{
	Automata a;
	a.on();
	std::cout << a.getMenu();
	a.coin(100);
	a.choice("black tea");
	bool res = a.check();
	std::cout << res;  // true, black tea -> 30
	if (res)
	{
		a.cook();
		a.finish();
	}
	a.choice("green tea");
	res = a.check();
	std::cout << res;  // false, cash = 0
	if (res)
	{
		a.cook();
		a.finish();
	}
	a.off();
}