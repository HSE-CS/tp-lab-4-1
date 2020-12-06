//Copyright 2020 Sozinov Kirill
#include "Automata.h"
#include <iostream>
using namespace std;

int main() {
	Automata a1;
	a1.on();
	cout << a1.getMenu() << endl;
	cout << a1.getState() << endl;
	a1.cancel();
	cout << a1.getState() << endl;
	a1.choice(0);
	a1.check(0);
	a1.off();
	cout << a1.getState() << endl;

	return 0;
}
